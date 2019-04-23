#include<stdio.h>//basic functions or FILE
#include<stdlib.h>//system();exit();free();malloc()
#include<conio.h>//getch();
#include<string.h>//strcmp();strcpy();
#include<io.h>//access
#include"struct.h"
#include"function.h"

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
void  menu2()
{
int b=0;
while(b!=1){
    int a;
    printf("\n\n   Main Menu of the system(Manager)\n");
    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    printf(".    0---Check manager's information      \n");
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
        if(a<0||a>5)
            printf("error!Please input again!\n");
        else
            break;
    }
    switch(a)
        {
            case 0:ChecM();break;
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

//select menu:student or manager
void role(){
    int a;
    T:
    printf("***************************\n");
    printf("Please choose your role:\n");
    printf("1.Student     2.Manager\n");
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
