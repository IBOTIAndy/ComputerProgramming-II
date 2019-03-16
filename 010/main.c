#include <stdio.h>

//010 解密碼
//2019/03/16 PM. 11:52 IBOTIAndy
typedef struct{         //
    char string[20];    //
}stringArray;           //

typedef struct{                 //
    stringArray strings[50];    //
    int stringMaximum;          //
    int ansNow;                 //
    char ans[100];              //
}decoder;                       //

void cutinput(decoder *decoder){}

void input(decoder *decoder1, decoder *decoder2){}

void output(char ans[]){}

void decodeNumber(decoder *decoder1){}

void decodeWord(decoder *decoder1){}

void run(decoder decoder1, decoder decoder2){   //開始解碼
    char ans[100]="";                           //
    decodeNumber(&decoder1);                    //解第一組密碼(取數字顛倒相加)
    decodeWord(&decoder2);                      //解第二組密碼(字元出現次數)
    output(ans);                                //輸出密碼答案
}

int main(){
    decoder decoder1={{}, 0, 0, ""};    //定義第一組密碼
    decoder decoder2={{}, 0, 0, ""};    //定義第二組密碼
    input(&decoder1, &decoder2);        //輸入密碼
    run(decoder1, decoder2);            //執行
//    printf("Hello world!\n");
    return 0;
}
