#include<stdio.h>
#include<stdlib.h>//system();exit();
#include<conio.h>//getch();
#include<string.h>//strcmp();
#include<io.h>


typedef struct book{
    char book_num[15];
    char book_nam[20];
    char book_writer[20];
    int bookn;
    struct book*next;
    }BK;

typedef struct borrow{
     char borrow_num[15];
     char borrow_fidate[15];
     }BT;

typedef struct student{
    char  stud_num[15];
    char  stud_nam[15];
    int a;
    BT borrow[2];
    struct student*next;
}ST;


 struct manger{
   char man_num[15];
   char man_nam[15];
}MA;

BK*head_B;
ST*head_S;
int z;
int l=0;
char v[15];




void Initial();
void InitM();
void InitS();
void InitB();

void Start();
void Exit();

void role();
void menu1();
void menu2();

void listB();
void Sear_S();
void Sear_B();
void checB();

void addS();
void addB();
void removeB();
void borrowB();
void returnB();

void writF();
void readF();
void check();

void Start()
{
    system("cls");
    printf("\n\n\n\n\t\t******************************************************************\n");
    printf("\n\n\n\n\t\t**     Welcome to the Library Information Management System     **\n ");
    printf("\n\n\n\n\t\t******************************************************************\n");
    printf("\n\n\t\tinput any key to enter the system...");
    getch();
    system("cls");


}
void Exit(){
    system("cls");
    printf("\n\n\n\n\t\t******************************************************************\n");
    printf("\n\n\n\n\t\t**           The data was saved successful!                     **\n ");
    printf("\n\n\n\n\t\t**          Welcome to this system next time!                   **\n ");
    printf("\n\n\n\n\t\t******************************************************************\n");
    printf("\n\n\t\tinput any key to enter the system...");
    getch();
    system("cls");

}
void role(){
    int a;
    T:
    printf("***************************\n");
    printf("Please choose your role:\n");
    printf("1.Student     2.manager\n");
    scanf("%d",&a);
    for(;;){
    if(a==1){
        system("cls");
        menu1();
        break;
    }else if(a==2){
        char t[15];
        printf("please input the ID number:\n");
        scanf("%s",t);
        if(strcmp(MA.man_num,t)==0){
        system("cls");
        menu2();
        }else{
        printf("The number is wrong!\n");
        getch();
        system("cls");
        goto T;
        }
        break;
    }else{
        printf("You input a wrong number!Try again!\n");
    }
    }


}

void  menu2()
{
int b=0;
while(b!=1){
    int a;
    printf("\n\n   Main Menu of the system(Manager)\n");
    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    printf(".    1---Add books                        \n");
    printf(".    2---Remove books                    \n");
    printf(".    3--- Check Books Information         \n");
    printf(".    4--- Check Students Information      \n");
    printf(".    5---Exit                             \n");
    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    printf("Please input the number:");
    while(b!=1)
    {
        scanf("%d",&a);
        if(a<1||a>5)
            printf("error!Please input again!\n");
        else
            break;
    }
    switch(a)
        {
            case 1:addB();break;
            case 2:removeB();break;
            case 3:Sear_B();break;
            case 4:Sear_S();break;
            case 5:
                system("cls");
                printf("******************************\n");
                printf("exit or Change your identity?\n");
                printf("1.exit    2.change identity\n");
                scanf("%d",&z);
                if(z==1){
                writF();
                Exit();
                exit(0);
                }else if(z==2){
                    system("cls");
                    menu1();
                    Exit();
                    exit(0);
                }
            default:printf("error!");
            exit(0);
            }
}
}


void menu1()
{
int b=0;
while(b!=1){
    int a;
    printf("\n\n   Main Menu of the system(Student)\n");
    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    printf(".    0---Check all books information       \n");
    printf(".    1---Add student(register)             \n");
    printf(".    2--- Book Borrowing                  \n");
    printf(".    3--- Book Returning                  \n");
    printf(".    4---Exit                             \n");
    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    printf("Please input the number:");
    while(b!=1)
    {
        scanf("%d",&a);
        if(a<0||a>4)
            printf("error!Please input again!\n");
        else
            break;
    }

        switch(a)
        {
            case 0:listB();break;
            case 1:addS();break;
            case 2:borrowB();break;
            case 3:returnB();break;
            case 4:
                Q:
                system("cls");
                printf("******************************\n");
                printf("exit or Change your identity?\n");
                printf("1.exit    2.change identity\n");
                scanf("%d",&z);
                if(z==1){
                writF();
                Exit();
                getch();
                exit(0);
                }else if(z==2){
                    printf("Please input the  code:\n");
                    scanf("%s",v);
                if(strcmp(MA.man_num,v)==0){
                    system("cls");
                    menu2();
                    Exit();
                    exit(0);
                }else{
                  goto Q;
                }
                }
            default:printf("error!");
            exit(0);
            }

}
}
void Initial(){
    InitB();
    InitM();
    InitS();
}
void InitB(){
    BK*a0;
    printf("\n");
    printf("*********************************\n");
    printf("Before the first time start the system,you need to initialize firstly:\n");
    printf("BOOK:\n");
    a0=(BK*)malloc(sizeof(BK));
    head_B=a0;
    printf("Please input the information of books:\n");
    printf("The order number of book:\n");
    scanf("%s",a0->book_num);
    printf("The name of book:\n");
    scanf("%s",a0->book_nam);
    printf("The writer name of book:\n");
    scanf("%s",a0->book_writer);
    printf("The number of book: \n");
    scanf("%d",&a0->bookn);
    printf("The book initialize is finish!\n");
    a0->next=NULL;
    printf("*********************************\n");
    }


void InitM(){
    printf("Manager:\n");
    printf("Manager initialize begin:\n");
    printf("Please sign the manager's information:\n");
    printf("Please input manager's code:\n");
    scanf("%s",MA.man_num);
    printf("Please input the manager's name:\n");
    scanf("%s",MA.man_nam);
    printf("The manager initialize module is finish!\n");
    printf("*********************************\n");
}

void InitS(){
     printf("Student:\n");
     ST*b0;
     int i;
     int a=0;
     b0=(ST*)malloc(sizeof(ST));
     head_S=b0;
     printf("Please input the information of students:\n");
     printf("The student's ID number:\n");
     scanf("%s",b0->stud_num);
     printf("The student's name:\n");
     scanf("%s",b0->stud_nam);
     b0->next=NULL;
     b0->a=0;
     strcpy(b0->borrow[0].borrow_fidate,"NULL");
     strcpy(b0->borrow[0].borrow_num,"NULL");
     strcpy(b0->borrow[1].borrow_fidate,"NULL");
     strcpy(b0->borrow[1].borrow_num,"NULL");

     printf("The module is finish!Press any key to continue...\n");
     getch();
     system("cls");

}

void addB(){
    BK*a0;
    BK*a1;
    a1=head_B;
    printf("add new books module:\n");
    printf("Please input the information of books:\n");
    a0=(BK*)malloc(sizeof(BK));
    printf("Please input the book's order number:\n");
    scanf("%s",a0->book_num);
    while(strcmp(a0->book_num,a1->book_num)!=0&&a1->next!=NULL){
        a1=a1->next;
    }
    if(strcmp(a0->book_num,a1->book_num)==0){
            printf("The kind of book already exists\n");
            printf("The number of the books:\n");
            scanf("%d",&a0->bookn);
            a1->bookn=a1->bookn+a0->bookn;

    }
    else{
            printf("The name of the book:\n");
            scanf("%s",a0->book_nam);
            printf("The writer of the book:\n");
            scanf("%s",a0->book_writer);
            printf("The number of books is:\n");
            scanf("%d",&a0->bookn);
            a1->next=a0;
            a0->next=NULL;

            }


    printf("Add new books is finish!Press any key to continue...\n");
    getch();
    system("cls");
}
void removeB(){
    BK*a;
    BK*a0;
    BK*a1;
    int t;
    int w;
    a=head_B;
    a1=head_B;
    a0=(BK*)malloc(sizeof(BK));
    printf("The order of book you want to remove is:\n");
    scanf("%s",a0->book_num);
    while(strcmp(a0->book_num,a1->book_num)!=0&&a1->next!=NULL){
        a=a1;
        a1=a1->next;
    }
    if(strcmp(a0->book_num,a1->book_num)==0){
            E:
            printf("The number of this kind of books you want to remove:\n");
            scanf("%d",&t);
            if(t<=a1->bookn){
                a1->bookn=a1->bookn-t;
            }
            else{

                printf("You want to remove this kind of books?\n");
                printf("1.yes  2.no\n");
                scanf("%d",&w);
                if(w==1){
                a->next=a1->next;
                free(a1);
                }else{
                 goto E;
                }
            }
    }
    else{
        printf("The book is not exist!");
    }
printf("Remove books is finish!Press any key to continue...\n");
getch();
system("cls");
}
void addS(){
    ST*a0;
    ST*a1;
    a1=head_S;
    int i;
    printf("Add students information:\n");
    a0=(ST*)malloc(sizeof(ST));
    printf("Please input the student's ID number:\n");
    scanf("%s",a0->stud_num);

    while(strcmp(a0->stud_num,a1->stud_num)!=0&&a1->next!=NULL){
        a1=a1->next;
    }
    if(strcmp(a0->stud_num,a1->stud_num)==0){
        printf("The student had registered!\n");
        goto RL;
    }
    else{
        printf("Please input the information of students:\n");
        printf("The student's ID number:\n");
        scanf("%s",a0->stud_num);
        printf("The student's name:\n");
        scanf("%s",a0->stud_nam);
        a0->a=0;
        strcpy(a0->borrow[0].borrow_fidate,"NULL");
        strcpy(a0->borrow[0].borrow_num,"NULL");
        strcpy(a0->borrow[1].borrow_fidate,"NULL");
        strcpy(a0->borrow[1].borrow_num,"NULL");
             a1->next=a0;
             a0->next=NULL;
        }

    RL:
        printf("The register (add module) finish!\n");
        getch();
        system("cls");
}

void Sear_B(){
    BK*c0;
    char book[15];
    c0=head_B;
    int t;
    int z=1;
    printf("Input 1 if you want to search one book's information,input 2 if you want to list all information of books:\n");
    scanf("%d",&t);
    if(t==1){
        printf("Please input the order of book you want to find:\n");
        scanf("%s",book);
        while(c0!=NULL){
            if(strcmp(c0->book_num,book)==0){
                printf("There are the information of the book you want:\n");
                printf("Order number   Name   Writer   Number \n");
                printf("   %s\t\t %s\t   %s\t   %d\n",c0->book_num,c0->book_nam,c0->book_writer,c0->bookn);
                goto lewy;
            }else{
                c0=c0->next;
            }
        }
    }else if(t==2){
        printf("These are the all books' information:\n");
        while(c0!=NULL){
            if(z==1){
            printf("Order number   Name   Writer   Number \n");
            printf("%s\t       %s\t %s\t  %d\n",c0->book_num,c0->book_nam,c0->book_writer,c0->bookn);
            printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
            c0=c0->next;
            z=z+1;
            }else{
                printf("%s\t       %s\t %s\t  %d\n",c0->book_num,c0->book_nam,c0->book_writer,c0->bookn);
                printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
                c0=c0->next;
            }
        }
        goto lewy;
    }
    lewy:
        printf("The module is finish!Press any key to continue...\n");
        getch();system("cls");
}
void listB(){
    BK*c0;
    c0=head_B;
    int z=1;
    printf("These are all books' information:\n");
           while(c0!=NULL){
            if(z==1){
            printf("Order number   Name   Writer   Number \n");
            printf("%s\t       %s\t %s\t  %d\n",c0->book_num,c0->book_nam,c0->book_writer,c0->bookn);
            printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
            c0=c0->next;
            z=z+1;
            }else{
                printf("%s\t       %s\t %s\t  %d\n",c0->book_num,c0->book_nam,c0->book_writer,c0->bookn);
                printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
                c0=c0->next;
            }
        }
    printf("The module is finish!Press any key to continue...\n");
    getch();
    system("cls");


}
void borrowB(){
    BK*a0;
    ST*b0;
    b0=head_S;
    a0=head_B;
    char stud[15];
    char book[15];
    char date[15];
    printf("The borrow module start:\n");
    printf("Please input your ID  number:\n");
    scanf("%s",stud);
    while(strcmp(b0->stud_num,stud)!=0&&b0->next!=NULL){
        b0=b0->next;
    }
    if(strcmp(b0->stud_num,stud)==0){
            if(b0->a<2){
            printf("please input the order number of books you want:\n");
            scanf("%s",book);
            while(strcmp(a0->book_num,book)!=0&&a0->next!=NULL){
                a0=a0->next;
            }
            if(strcmp(a0->book_num,book)==0){

                    printf("please input the date you want to return:\n");
                    scanf("%s",date);
                    strcpy(b0->borrow[b0->a].borrow_num,book);
                    strcpy(b0->borrow[b0->a].borrow_fidate,date);
                    a0->bookn=a0->bookn-1;
                    b0->a=b0->a+1;
                    goto Z;


            }else{
                printf("The book you want is not exit!");
                goto Z;

            }

        }else{
            printf("The number of the student can borrow is 0!\n");
            goto Z;

             }
    }else{
        printf("The student is not exit!\n");
        goto Z;
    }



 Z:
        printf("The borrow module is finish!Press any key to continue...\n ");
        getch();
        system("cls");
}
void returnB(){
    BK*a0;
    ST*b0;
    b0=head_S;
    a0=head_B;
    char stud[15];
    char book[15];
    char date[15];
    printf("The return start:\n");
    printf("Please input your ID  number:\n");
    scanf("%s",stud);
    while(strcmp(b0->stud_num,stud)!=0&&b0->next!=NULL){
        b0=b0->next;
    }
    if(strcmp(b0->stud_num,stud)==0){
        printf("please input the order number of books you want:\n");
        scanf("%s",book);
        while(strcmp(a0->book_num,book)!=0&&a0->next!=NULL){
            a0=a0->next;
        }
         if(strcmp(a0->book_num,book)==0){
                a0->bookn=a0->bookn+1;
                if(strcmp(b0->borrow[0].borrow_num,a0->book_num)==0){
                    strcpy(b0->borrow[0].borrow_num,b0->borrow[1].borrow_num);
                    strcpy(b0->borrow[0].borrow_fidate,b0->borrow[1].borrow_fidate);
                    strcpy(b0->borrow[1].borrow_num,"NULL");
                    strcpy(b0->borrow[1].borrow_fidate,"NULL");
                    b0->a=b0->a-1;
                }else{
                    strcpy(b0->borrow[1].borrow_num,"NULL");
                    strcpy(b0->borrow[1].borrow_fidate,"NULL");
                    b0->a=b0->a-1;
                }

         }else{
                printf("The book you want is not exit!");
                goto T;

         }




    }else{
        printf("The student is not exit!\n");
        goto T;
    }

    T:
        printf("The return module is finish!Press any key to continue...\n");
        getch();
        system("cls");
}
void Sear_S(){
    ST*a0;
    a0=head_S;
    char stud[15];
    int t;
    printf("Input 1 if you want to search one student's information,input 2 if you want to list all students' information:\n");
    scanf("%d",&t);
    if(t==1){
        printf("Please input the ID number of student you want to find\n");
        scanf("%s",stud);
        while(a0!=NULL){
            if(strcmp(a0->stud_num,stud)==0){
                printf("%s\t\t%s\t\t\n",a0->stud_num,a0->stud_nam);
                printf("Book1:     %s\t\t%s\t\t\n",a0->borrow[0].borrow_num,a0->borrow[0].borrow_fidate);
                printf("Book2:     %s\t\t%s\t\t\n",a0->borrow[1].borrow_num,a0->borrow[1].borrow_fidate);
                printf("----------------------------------------------\n");
                goto M;
            }else{
                a0=a0->next;
            }
        }
    }else if(t==2){
        printf("These are all students' information:\n");
        while(a0!=NULL){
            printf("%s\t\t%s\t\t\n",a0->stud_num,a0->stud_nam);
            printf("Book1:     %s\t\t%s\t\t\n",a0->borrow[0].borrow_num,a0->borrow[0].borrow_fidate);
            printf("Book2:     %s\t\t%s\t\t\n",a0->borrow[1].borrow_num,a0->borrow[1].borrow_fidate);
            printf("----------------------------------------------\n");
            a0=a0->next;
        }

    }
M:
    printf("The module is finish!Press any key to continue...\n");
    getch();
    system("cls");
}

void writF(){
    FILE*fp;
    FILE*fp1;
    FILE*fp2;
    BK*a;
    BK*b;
    ST*c;
    ST*d;
    a=head_B;
    c=head_S;
//write book's information
    if((fp=fopen("D:\\book.txt","wb"))==NULL){
        printf("The file can't open,Press any key to continue...\n");
        getch();
        exit(0);
    }
    while(a!=NULL){
            fprintf(fp,"%s  %s  %s  %d\r\n",a->book_num,a->book_nam,a->book_writer,a->bookn);
            b=a;
            a=a->next;
            free(b);

        }
        fclose(fp);
//write student's information
    if((fp1=fopen("D:\\student.txt","wb"))==NULL){
    printf("The file can't open,Press any key to continue...\n");
    getch();
    exit(0);
    }
    while(c!=NULL){
            fprintf(fp1,"%s  %s  \r\n%s %s %s %s\r\n",c->stud_num,c->stud_nam,c->borrow[0].borrow_num,c->borrow[0].borrow_fidate,c->borrow[1].borrow_num,c->borrow[1].borrow_fidate);
            d=c;
            c=c->next;
            free(d);

        }
        fclose(fp1);
//write manager's information
    if((fp2=fopen("D:\\manager.txt","wb"))==NULL){
    printf("The file can't open,Press any key to continue...\n");
    getch();
    exit(0);
    }
    fprintf(fp2,"%s %s",MA.man_nam,MA.man_num);
    fclose(fp2);
    }
void readF(){
     FILE*fp3;
     FILE*fp4;
     FILE*fp5;
     BK*a;
     BK*b;
     ST*c;
     ST*d;


//read book's information:
     if((fp3=fopen("D:\\book.txt","r"))==NULL){
     printf("The file can't open,Press any key to continue...\n");
     getch();
     exit(0);
    }
    a=(BK*)malloc(sizeof(BK));
    fscanf(fp3,"%s%s%s%d",a->book_num,a->book_nam,a->book_writer,&a->bookn);
    head_B=a;

    while(1){
        b=(BK*)malloc(sizeof(BK));
        fscanf(fp3,"%s%s%s%d",b->book_num,b->book_nam,b->book_writer,&b->bookn);
        if(feof(fp3)) break;
        a->next=b;
        a=b;
        a->next=NULL;

   }
   fclose(fp3);
//read student's information:
    if((fp4=fopen("D:\\student.txt","r"))==NULL){
     printf("The file can't open,Press any key to continue...\n");
     getch();
     exit(0);
    }

    c=(ST*)malloc(sizeof(ST));
    fscanf(fp4,"%s%s%s%s%s%s",c->stud_num,c->stud_nam,c->borrow[0].borrow_num,c->borrow[0].borrow_fidate,c->borrow[1].borrow_num,c->borrow[1].borrow_fidate);
    head_S=c;

    while(1){

        d=(ST*)malloc(sizeof(ST));
        fscanf(fp4,"%s%s%s%s%s%s",d->stud_num,d->stud_nam,d->borrow[0].borrow_num,d->borrow[0].borrow_fidate,d->borrow[1].borrow_num,d->borrow[1].borrow_fidate);
        if(feof(fp4)){
                free(d);
                c->next=NULL;
                break;}
        c->next=d;

        c=d;
        c->next=NULL;


   }

   fclose(fp4);
// read manager's information:
    if((fp5=fopen("D:\\manager.txt","r"))==NULL){
    printf("The file can't open,Press any key to continue...\n");
    getch();
    exit(0);
    }
    fscanf(fp5,"%s %s",MA.man_nam,MA.man_num);
    fclose(fp5);
    }
void check(){
    ST*a;
    a=head_S;
    while(a!=NULL){
        if(strcmp(a->borrow[0].borrow_num,"NULL")==0){
            a->a=0;
            a=a->next;
        }else if(strcmp(a->borrow[1].borrow_num,"NULL")==0){
            a->a=1;
            a=a->next;

        }else{
            a->a=2;
            a=a->next;
        }
    }

}


int main(){
  if(access("D:\\book.txt",0)==0){
  readF();
  check();
  Start();
  role();
  }else{
   Initial();
   Start();
   role();

  }
  return 0;
}
