#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX 3

typedef struct book{
    char book_num[10];
    char book_nam[20];
    char book_writer[20];
    int bookn;
    int booko;
    int n;
    struct book*next;
    }BK;
typedef struct borrow{
     char borrow_num[10];
     char borrow_fidate[15];
     }BT;
typedef struct student{
    char  stud_num[10];
    char  stud_nam[15];
    int a;
    int t;
    BT borrow[MAX];
    struct student*next;
}ST;
BK*head_B;
ST*head_S;
void Initial();
int menu();
void Select();
void InitB();
void addB();
void removeB();
void borrowB();
void returnB();
void InitS();
void Sear_B();
void Sear_T();
void Initial()
{
    system("cls");
    printf("\n\n\n\n\t\t******************************************************************\n");
    printf("\n\n\n\n\t\t**     Welcome to the Library Information Management System     **\n ");
    printf("\n\n\n\n\t\t******************************************************************\n");
    printf("\n\n\t\tinput any key to enter the system...");
    getch();
    system("cls");


}
int menu()
{
    int a;
    printf("\n\n\tMain Menu of the system\n");
    printf("=========================================\n");
    printf("*\t1---Book Initialization           \n");
    printf("*\t2---Student Initialization        \n");
    printf("*\t3---Book Borrowing                \n");
    printf("*\t4---Book Returning                \n");
    printf("*\t5---Check Books Information       \n");
    printf("*\t6---Check Students Information    \n");
    printf("*\t7---Exit                          \n");
    printf("=========================================\n");
    printf("Please input the number:");
    for(;;)
    {
        scanf("%d",&a);
        if(a<1||a>7)
            printf("error!Please input again!");
        else
            break;
    }
    return a;
}
void Select()
{
    for(;;)
    {
        switch(menu())
        {
            case 1:printf("1");break;
            case 2:printf("2");break;
            case 3:printf("3");break;
            case 4:printf("4");break;
            case 5:printf("5");break;
            case 6:printf("6");break;
            case 7:
                system("cls");
                printf("The data was saved successful!\n");
                printf("Welcome to use this system next time!\n");
                getch();
                exit(0);
            default:printf("error!");
            exit(0);
            }

    }
}
void InitB(){
    BK*a0;
    printf("Book initialize begin:");
    a0=(BK*)malloc(sizeof(BK));
    head_B=a0;
    printf("Please input the information of books:");
    printf("The order number of book:");
    scanf("%s",a0->book_num);
    printf("The name of book:");
    scanf("%s",a0->book_nam);
    printf("The writer name of book:");
    scanf("%s",a0->book_writer);
    printf("The number of book: ");
    scanf("%d",a0->bookn);
    a0->next=NULL;
    a0->n=0;
    printf("The book initialize is finish!Press any key to continue...");
    getch();
    system("cls");
    }
void addB(){
    BK*a;
    BK*a0;
    BK*a1;
    a=head_B;
    a1=head_B;
    printf("add new books module:\n");
    printf("Please input the information of books:\n");
    a0=(BK*)malloc(sizeof(BK));
    printf("Please input the book's order number:\n");
    scanf("%s",a0->book_num);
    while(strcmp(a0->book_num,a1->book_num)!=0&&a1->book_num!=NULL){
        a1=a1->next;
    }
    if(strcmp(a0->book_num,a1->book_num)==0){
            printf("The kind of book is already exists\n");
            printf("The number of the books:\n");
            scanf("%d",a0->bookn);
            a1->booko=a1->booko+a0->bookn;

    }
    else{
            printf("The name of the book:\n");
            scanf("%s",a0->book_nam);
            printf("The writer of the book:\n");
            scanf("%s",a0->book_writer);
            printf("The number of books is:\n");
            printf("%d",a0->bookn);
            while(a->next!=NULL){
            a=a->next;}
            if(head_B=NULL){
                head_B=a0;
            }
            else{
                a->next=a0;
                a0->next=NULL;

            }

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
    a=head_B;
    a1=head_B;
    printf("The order of book you want to remove is:");
    scanf("%s",a0->book_num);
    while(strcmp(a0->book_num,a1->book_num)!=0&&a1->book_num!=NULL){
        a=a1;
        a1=a1->next;
    }
    if(strcmp(a0->book_num,a1->book_num)==0){
            printf("The number of this kind of books you want to remove:");
            scanf("%d",t);
            if(t<=a1->bookn){
                a1->bookn=a1->bookn-t;
            }
            else{
                printf("You want to remove this kind of books:");
                a->next=a1->next;
                free(a1);
            }
    }
    else{
        printf("The book is not exist!");
    }
printf("Remove books is finish!Press any key to continue...\n");
getch();
system("cls");
}
void InitS(){
     ST*b0;
     int i;
     b0=(ST*)malloc(sizeof(ST));
     head_S=b0;
     printf("Please input the information of students:\n");
     printf("The student's ID number:\n");
     scanf("%s",b0->stud_num);
     printf("The student's name:\n");
     scanf("%s",b0->stud_nam);
     for(i=0;i<MAX;i++){
        strcpy(b0->borrow[i].borrow_num,"0");
        strcpy(b0->borrow[i].borrow_fidate,"0");
     }
     b0->next=NULL;

     printf("The module is finish!Press any key to continue...\n");
     getch();
     system("cls");

}
void borrowB(){
    BK*c0;
    ST*d0;
    char book_RN[15];
    char stud_N[15];
    char limit_DA[15];
    int t;
    d0=head_S;
    c0=head_B;
    printf("Please input your ID number:\n");
    scanf("%s",stud_N);
    while(d0->next!=NULL&&strcmp(stud_N,d0->stud_num)!=0){
            d0=d0->next;
    }
    if(d0->next==NULL&&strcmp(stud_N,d0->stud_num)!=0){
        printf("The ID  number is not exist!Press any key to continue...\n");
        goto END;
    }
    printf("Please input the order number of books you want\n");
    scanf("%s",book_RN);
    while(c0->next!=NULL&&strcmp(book_RN,c0->book_num)!=0){
        c0=c0->next;
    }
    if(c0->next==NULL&&strcmp(book_RN,c0->book_num)!=0){
        printf("The book you want is not exit!Press any key to continue...\n");
        goto END;
    }
    else if(c0->bookn<=0){
        printf("The books have been borrowed out!Press any key to continue...\n");
        goto END;
    }
    else if (d0->a>MAX||d0->a==MAX){
        printf("The number of books you can borrow is already full!Press any key to continue...!\n");
        goto END;
    }
    else if (strcmp(d0->borrow[0].borrow_num,book_RN)!=0){
        for(t=0;t<=MAX;t++){
            d0->a=t;
            if(strcmp(d0->borrow[t].borrow_num,book_RN)==0){
                printf("You can not borrow two same books!\n");
                goto END;
            }
            else if(strcmp(d0->borrow[t].borrow_num,"0")==0){
                printf("Please input you return date:\n");
                scanf("%s",limit_DA);
                strcpy(d0->borrow[t].borrow_num,book_RN);
                strcpy(d0->borrow[t].borrow_fidate,limit_DA);
                c0->bookn--;
                printf("The borrow module success!Press any to continue...\n");
                goto END;


            }


        }
    }
    else{
        printf("Please input you return date:\n");
        scanf("%s",limit_DA);
        strcpy(d0->borrow[d0->a].borrow_num,book_RN);
        strcpy(d0->borrow[d0->a].borrow_fidate,limit_DA);
        c0->bookn--;
        goto END;
    }
END: getch();system("cls");
}
void returnB(){
    BK*c0;
    ST*d0;
    char stud_N[15];
    char book_RN[15];
    c0=head_B;
    d0=head_S;
    int t=0;
    int x,y;
    printf("Return book module....\n");
    printf("please input your ID number:\n");
    scanf("%s",stud_N);
    while(d0->next!=NULL&&strcmp(stud_N,d0->stud_num)!=0){
        d0=d0->next;
    }
    if(d0->next==NULL&&strcmp(stud_N,d0->stud_nam)!=0){
        printf("The ID number is not exist!Press any key to continue...\n");
        t=1;
        goto end;
    }
    printf("Please input the order number of books you want to return...\n");
    scanf("%s",book_RN);
    while(c0->next!=NULL&&strcmp(book_RN,c0->book_num)!=0){
        c0=c0->next;
    }
    if(c0->next==NULL&&strcmp(book_RN,c0->book_num)!=0){
        printf("The order number of books you want to return is not exist!Press any key to continue...\n");
        t=1;
        goto end;
    }
    for(x=0;x<MAX;x++){
        if(strcmp(book_RN,d0->borrow[x].borrow_num)==0){
                t=2;
                y=x;
                for(y;y<MAX-1;y++){
                    strcpy(d0->borrow[y].borrow_num,d0->borrow[y+1].borrow_num);
                    strcpy(d0->borrow[y].borrow_fidate,d0->borrow[y+1].borrow_fidate);
                }
                strcpy(d0->borrow[MAX-1].borrow_num,"0");
                strcpy(d0->borrow[MAX-1].borrow_fidate,"0");
                c0->bookn++;
                printf("The return book module is finished!\n");
                goto end;
        }
    }
        if(t=0){
            printf("You don't borrow this book!\n");

        }
        end: getch();system("cls");

}
void Sear_B(){
    BK*c0;
    char book[15];
    c0=head_B;
    int t;
    printf("Input 1 if you want to search one book's information,input 2 if you want to list all information of books:\n");
    scanf("%d",t);
    if(t==1){
    printf("Please input the order of book you want to find:\n");
    scanf("%s",book);
    for(;;){
        if(strcmp(c0->book_num,book)==0){
            printf("There are the information of the book you want:\n");
            printf("%s\t%s\t%s\t%d\n",c0->book_num,c0->book_nam,c0->book_writer,c0->bookn);
            goto lewy;
        }else{
            c0=c0->next;
        }
    }
    }else if(t==2){
        printf("These are the all books information:\n");
        while(c0->next!=NULL){
            printf("%s\t%s\t%s\t%d\n\n",c0->book_num,c0->book_nam,c0->book_writer,c0->bookn);
        }
        goto lewy;
    }
    lewy:
        printf("The module is finish!Press any key to continue...\n");
        getch();system("cls");
}
void Sear_T(){
    ST*d0;
    char stud[15];
    int t;
    d0=head_S;
    printf("Input 1 if you want to find one student's information,input 2 if you want to find all students information:\n");
    scanf("%d",t);
    if(t==1){
        printf("Please input the number of student you want to find:\n");
        scanf("%s",stud);
        for(;;){
            if(strcmp(stud,d0->stud_num)==0){
                printf("The information of the student is:\n");
                printf("The number and name of the student:\n");
                printf("%s\t\t%s:\n\n",d0->stud_num,d0->stud_nam);
                for(t=0;t<MAX;t++){
                printf("order number     limit date\n");
                printf("%s\t",d0->borrow[t].borrow_num);
                printf("%s\n",d0->borrow[t].borrow_fidate);
                }
                printf("------------------------\n");
            }else{
                d0=d0->next;

            }
            goto robert;
            }
    }else if(t==2){
        printf("These are all information of students:\n");
        while(d0->next!=NULL){
                printf("The information of the student is:\n");
                printf("The number and name of the student:\n");
                printf("%s\t\t%s:\n\n",d0->stud_num,d0->stud_nam);
                for(t=0;t<MAX;t++){
                printf("order number     limit date\n");
                printf("%s\t",d0->borrow[t].borrow_num);
                printf("%s\n",d0->borrow[t].borrow_fidate);
                }
                printf("------------------------\n");
        }
        goto robert;
    }
    robert:
        printf("The module is finish!\n");
        getch();
        system("cls");
}
int main()
{
    Initial();

    Select();
}

