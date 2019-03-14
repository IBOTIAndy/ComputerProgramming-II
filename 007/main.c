#include <stdio.h>

//007 字串頻率
//2019/03/14 PM.03:01 IBOTIAndy

typedef struct{ //定義結構
    char s[20]; //字串
    int size;   //字元個數(沒有'\0')
    int n;      //相同的數量
}string;        //字串

void input(char in[]){  //輸入
    gets(in);           //因為 scanf 遇到空白會停止，所以使用 gets
}

int main(){
    char in[100]="";        //輸入暫存區
    string s[20]={"", 0};   //存多個子句，方便管理
    input(in);              //輸入到 in (一次整行，因為不知道數量)
    //printf("%s", in);       //檢查輸入
//    printf("Hello world!\n");
    return 0;
}
