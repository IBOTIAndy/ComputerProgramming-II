#include <stdio.h>

//007 �r���W�v
//2019/03/14 PM.03:01 IBOTIAndy

typedef struct{ //�w�q���c
    char s[20]; //�r��
    int size;   //�r���Ӽ�(�S��'\0')
    int n;      //�ۦP���ƶq
}string;        //�r��

void input(char in[]){  //��J
    gets(in);           //�]�� scanf �J��ťշ|����A�ҥH�ϥ� gets
}

int main(){
    char in[100]="";        //��J�Ȧs��
    string s[20]={"", 0};   //�s�h�Ӥl�y�A��K�޲z
    input(in);              //��J�� in (�@�����A�]�������D�ƶq)
    //printf("%s", in);       //�ˬd��J
//    printf("Hello world!\n");
    return 0;
}
