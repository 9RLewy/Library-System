#include<stdio.h>//basic functions or FILE
#include<stdlib.h>//system();exit();free();malloc()
#include<conio.h>//getch();
#include<string.h>//strcmp();strcpy();
#include<io.h>//access
#include"struct.h"
#include"function.h"

void addS(){
    ST*a0;
    ST*a1;
    a1=head_S;
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
        printf("Please input the student's name:\n");
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
