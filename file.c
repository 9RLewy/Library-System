#include<stdio.h>//basic functions or FILE
#include<stdlib.h>//system();exit();free();malloc()
#include<conio.h>//getch();
#include<string.h>//strcmp();strcpy();
#include<io.h>//access
#include"struct.h"
#include"function.h"

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
        if(feof(fp3)){
                free(b);
                a->next=NULL;
                break;}
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
   //judge if the program should initialize
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
