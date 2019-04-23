#include<stdio.h>//basic functions or FILE
#include<stdlib.h>//system();exit();free();malloc()
#include<conio.h>//getch();
#include<string.h>//strcmp();strcpy();
#include<io.h>//access
#include"struct.h"
#include"function.h"

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
