#include<stdio.h>//basic functions or FILE
#include<stdlib.h>//system();exit();free();malloc()
#include<conio.h>//getch();
#include<string.h>//strcmp();strcpy();
#include<io.h>//access
#include"struct.h"
#include"function.h"

void ChecM(){
    printf("These are the information of manager:\n");
    printf("Name    Password \n");
    printf("%s\t   %s\n",MA.man_nam,MA.man_num);
    printf("This module is finish!Press any key to continue...\n");
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
    BK*a1;
    char bo[15];
    int t;
    int w;
    a=head_B;
    a1=head_B;
    printf("The order of book you want to remove is:\n");
    scanf("%s",bo);
    while(strcmp(bo,a1->book_num)!=0&&a1->next!=NULL){
        a=a1;
        a1=a1->next;
    }
    if(strcmp(bo,a1->book_num)==0){
            E:
            printf("The number of this kind of books you want to remove:\n");
            scanf("%d",&t);
            if(t<=a1->bookn){
                a1->bookn=a1->bookn-t;
            }
            else{

                printf("Do you want to remove this kind of books?\n");
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
        printf("The book is not exist!\n");
    }
printf("Remove books is finish!Press any key to continue...\n");
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
                printf("- - - - - - - - - - - - - - - - - - - - - - -\n");
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
