#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
    struct stu*next;
}ST;
BK*head_B;
ST*head_S;
void Initial();
int menu();
void Select();
void InitB();
void addB();
void removeB();
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

    printf("The book initialize is finish!Press any key to continue...");
    getch();
    system("cls");
    }
void addB(){
    BK*a,a0,a1;
    a=a1=head_B;
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
            scanf("%d",a0->bookn)£»
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
    BK*a,a0,a1;
    int t;
    a=a1=head_B;
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
int main()
{
    Initial();

    Select();
}

