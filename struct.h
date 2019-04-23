#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
typedef struct book{
    char book_num[15];
    char book_nam[15];
    char book_writer[15];
    int bookn;//number of books
    struct book*next;
    }BK;


 struct borrow{
     char borrow_num[15];
     char borrow_fidate[15];
     };

typedef struct student{
    char  stud_num[15];
    char  stud_nam[15];
    int a;//used to limit the number of book which each people can borrow
    struct borrow borrow[2];
    struct student*next;
}ST;


 struct manger{
   char man_num[15];
   char man_nam[15];
}MA;

BK*head_B;
ST*head_S;// two head node
int z;//list book
char v[15];//input the password when goto manager menu

#endif // STRUCT_H_INCLUDED
