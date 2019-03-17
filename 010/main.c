#include <stdio.h>
#include <string.h>
//010 �ѱK�X
//2019/03/17 PM. 05:33 IBOTIAndy
typedef struct{     //�w�q���c
    char *string;   //�r��(��)����
}stringArray;       //�r��}�C

typedef struct{                 //�w�q���c
    stringArray strings[50];    //�r��}�C
    int stringMaximum;          //�s�J���r��ƶq
    int ansNow;                 //���ץثe�ȥΪ��r����
    char ans[100];              //����
}decoder;                       //�ѽX��

void enterString(stringArray *s, char *word){   //�x�s�r��
    s->string = word;                           //�N�r�ꪺ�}�Y��m�A�s�J���c������
}

void cutinput(char text[], decoder *decoder){       //���Φr��
    int i=0;                                        //
    char *word;                                     //�إߦr��(�r��)����
    word = strtok(text, " ");                       //���Φr��A�H�Ů欰�_�I�C�s�J���Ф�
    enterString(&(decoder->strings[0]), word);      //�N���мg�J���c���x�s
    i = 1;                                          //�]���Ĥ@��(��m0)�g�L�F�A�ҥH�x�s��m+1
    while(word != NULL){                            //���򪽨�r����Χ���
        word = strtok(NULL, " ");                   //���Φr��A�H�Ů欰�_�I�C�s�J���Ф�
        enterString(&(decoder->strings[i]), word);  //�N���мg�J���c���x�s
        i = i + 1;                                  //
    }
    decoder->stringMaximum = i - 1;                 //�O���x�s���r��ƶq
//    i = 0;                                          //���ե�
//    while(decoder->strings[i].string != NULL){
//        printf("%s\n", decoder->strings[i].string);
//        i = i + 1;
//    }
}

void input(char ciphertext[], decoder *decoder){    //��J
    gets(ciphertext);                               //���@����J
    cutinput(ciphertext, decoder);                  //���ο�J���r��
}

void output(char ans[]){}

void decodeNumber(decoder *decoder1){}

void decodeWord(decoder *decoder1){}

void run(decoder decoder1, decoder decoder2){   //�}�l�ѽX
    char ans[100]="";                           //
    decodeNumber(&decoder1);                    //�ѲĤ@�ձK�X(���Ʀr�A�ˬۥ[)
    decodeWord(&decoder2);                      //�ѲĤG�ձK�X(�r���X�{����)
    output(ans);                                //��X�K�X����
}

void testinputdata(decoder decoderData){                            //�d�ݿ�J�����
    int i=0;
    while(decoderData.strings[i].string != NULL){                   //����S�����
    //while(i < decoderData.stringMaximum){                           //����P�_��̫�@�Ӧr��
        printf("%d: %s\n", i + 1, decoderData.strings[i].string);   //��X���Φn���r��
        i = i + 1;                                                  //
    }
}

int main(){
    char ciphertext1[100]="";           //�w�q�Ĥ@�ձK�X
    char ciphertext2[100]="";           //�w�q�ĤG�ձK�X
    decoder decoder1={{}, 0, 0, ""};    //�w�q�Ĥ@�ոѱK�X��
    decoder decoder2={{}, 0, 0, ""};    //�w�q�ĤG�ոѱK�X��
    input(ciphertext1, &decoder1);      //��J�K�X
    input(ciphertext2, &decoder2);      //��J�K�X
    //testinputdata(decoder1);            //��J���ת�����
    //testinputdata(decoder2);            //��J���ת�����
    run(decoder1, decoder2);            //����
//    printf("Hello world!\n");
    return 0;
}
