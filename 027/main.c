#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//027 �U�Ч�@�~
//2019/05/26 PM. 11:30 IBOTIAndy
//----------typedef----------
typedef struct homework_s{      //�@�~���c
    char name[10];              //�@�~���֦���
    int isDelay;                //���S�����
    struct homework_s *next;    //�U�@���@�~
}homework_t;
//---------/typedef----------

//---setList---
homework_t* topInList(homework_t *topHW, homework_t *newHW){    //�q�W���J�}�C
    if(topHW != NULL){          //�p�G�}�C���O�Ū�@#$%^&*&^%$#%^&*()@*$&^%@^#&
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
    return topHW;                           //�^�ǳ̤W�������@�~
}
//---------/input------------

//----------run--------------
//-------makeUpHW-------
homework_t* makeUpHW(homework_t *topHW, char *name){    //�ɥ�@�~
    homework_t *newHW=NULL;
    newHW = malloc(sizeof(homework_t)); //�إ߷s���Ŷ����s�@�~
    strcpy(newHW->name, name);          //�N��J���W��
    newHW->isDelay = 1;                 //�N�O�_���]�w�� True
    topHW = topInList(topHW, newHW);    //��J�}�C�� �^�ǳ̤W�誺��m
    return topHW;                       //�^�ǳ̤W�������@�~
}
//------/makeUpHW-----------

//-----output-----
void output(homework_t *HW){            //��X�@�~���p
    printf("%s's HW is ", HW->name);    //��X�@�~���֦���
    if(!HW->isDelay){                   //�p�G�@�~�S�����
        printf("not ");                 //��X not delay
    }
    printf("delay\n");                  //
}

//-------correctionHW-------
homework_t* correctionHW(homework_t *topHW){    //��@�~
    homework_t *newTop=NULL;
    if(topHW == (homework_t*)NULL){          //�p�G�w�g�S���@�~�F
        printf("Empty\n");      //��X��
        return topHW;           //�^�ǭ쥻����m
    }
    newTop = topHW->next;       //�s�����h���U�@���@�~
    output(topHW);              //��X�̤W�h���@�~
    return newTop;              //�^�Ƿs�����h
}
//------/correctionHW-------
//----/output-----
void run(homework_t *topHW){
    char in[20]="";
    char *select, *name;
    gets(in);
    while(1){
        select = strtok(in, " ");           //���X��ܪ��Ҧ�
        if(!strcmp(select, "1")){           //�ɥ�@�~ (push) �O���ɥ檺�@�~�A�ðO�����
            name = strtok(NULL, " ");       //���ΥX�ǥͦW��
            topHW = makeUpHW(topHW, name);  //�ɥ�@�~
        }
        else if(!strcmp(select, "2")){      //��@�~ (pop) ��X�O�_���@�~�C�p�G�粒�A��X Empty
            topHW = correctionHW(topHW);    //��@�~
        }
        else if(!strcmp(select, "3")){      //�U�Z�A�L�X�٨S�諸�@�~���ǥͦW�١B��檬�p�A�p�G�@�~�粒�A��X Empty
//            offWork(topHW);
            break;
        }
        gets(in);
    }
}
//----------run--------------

int main(){
    homework_t *topHW=NULL; //�}�C���}�Y
    topHW = input(topHW);   //��J ���ƿ�J�W�� �����J -1 ����
    run(topHW);             //�}�l��@�~
//    printf("Hello world!\n");
    return 0;
}
