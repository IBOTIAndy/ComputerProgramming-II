#include <stdio.h>
#include <stdlib.h>
//017 專題老師志願序
//2019/04/19 IBOTIAndy AM. 12:06
typedef struct{                 //志願清單
    char studentName[10];       //學生名稱
    char studentOrder[10][10];  //學生志願序
    int studentN;               //學生數量
    char teacherName[10];       //老師名稱
    char teacherOrder[10][10];  //老師志願序
    int teacherM;               //老師數量
}volunteerOrder;
//----------input----------
void input(volunteerOrder *list){}
//---------/input----------

//-----------run-----------
void teacherSelect(){}

void studentSelect(){}

void run(volunteerOrder list){}
//----------/run-----------

int main(){
    volunteerOrder list;        //
    input(&list);               //輸入
    run(list);                  //執行
//    printf("Hello world!\n");
    return 0;
}
