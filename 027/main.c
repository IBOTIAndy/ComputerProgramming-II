#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//027 �U�Ч�@�~
//2019/05/26 PM. 00:54 IBOTIAndy
//----------typedef----------
typedef struct homework_s{      //�@�~���c
    char name[10];              //�@�~���֦���
    int isDelay;                //���S�����
    struct homework_s *next;    //�U�@���@�~
}homework_t;
//---------/typedef----------

//---setList---
homework_t* topInList(homework_t *topHW, homework_t *newHW){    //�q�W���J�}�C
    if(topHW != NULL){          //�p�G�}�C���O�Ū�
        newHW->next = topHW;    //�N�s�@�~���U�@�ӫ��V�̤W��
    }                                                           //�N��������ȩ�b�̤W��
    return newHW;               //�^�Ƿs�@�~����m
}
//--/setList---

//----------input------------
homework_t* input(homework_t *topHW){   //��J
    homework_t *newHW=NULL;
    char inName[10]="";
    gets(inName);                                   //��J
    while(strcmp(inName, "-1")){                    //�����J -1 �ɰ���
        newHW = malloc(sizeof(homework_t));         //�إ߷s���Ŷ����s�@�~
        strcpy(newHW->name, inName);                //�N��J���W��
        newHW->isDelay = 0;                         //�N�O�_���]�w�� False
        topHW = topInList(topHW, newHW);            //��J�}�C�� �^�ǳ̤W�誺��m
        gets(inName);                               //�~���J
    }
    return topHW;
}
//---------/input------------

int main(){
    homework_t *topHW=NULL; //�}�C���}�Y
    topHW = input(topHW);   //��J ���ƿ�J�W�� �����J -1 ����
//    printf("Hello world!\n");
    return 0;
}
