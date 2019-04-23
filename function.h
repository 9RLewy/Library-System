#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

//six module

//initialization module
void Initial();
void InitM();//initial manager
void InitS();//initial student
void InitB();//initial books
//Start and End module
void Start();
void Exit();
//Menu module:select module
void role();
void menu1();
void menu2();
// Manager module:manager menu
void ChecM();
void addB();
void removeB();
void Sear_S();
void Sear_B();
//Student module:student menu
void listB();
void addS();
void borrowB();
void returnB();
//File module:
void writF();
void readF();
void check();


#endif // FUNCTION_H_INCLUDED
