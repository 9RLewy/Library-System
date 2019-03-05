#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
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
            case 1:
                system("cls");
                printf("1");
                break;
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
            default:printf("error!");exit(0);
        }
        break;
    }
}
int main()
{
    Initial();

    Select();
}

