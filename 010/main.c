#include <stdio.h>

//010 �ѱK�X
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

void run(decoder decoder1, decoder decoder2){   //�}�l�ѽX
    char ans[100]="";                           //
    decodeNumber(&decoder1);                    //�ѲĤ@�ձK�X(���Ʀr�A�ˬۥ[)
    decodeWord(&decoder2);                      //�ѲĤG�ձK�X(�r���X�{����)
    output(ans);                                //��X�K�X����
}

int main(){
    decoder decoder1={{}, 0, 0, ""};    //�w�q�Ĥ@�ձK�X
    decoder decoder2={{}, 0, 0, ""};    //�w�q�ĤG�ձK�X
    input(&decoder1, &decoder2);        //��J�K�X
    run(decoder1, decoder2);            //����
//    printf("Hello world!\n");
    return 0;
}
