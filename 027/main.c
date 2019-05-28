#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//027 �U�Ч�@�~
//2019/05/28 PM. 03:21 IBOTIAndy
//----------typedef----------
typedef struct homework_s{      //�@�~���c
    char name[10];              //�@�~���֦���
    int isDelay;                //���S�����
    struct homework_s *next;    //�U�@���@�~
}homework_t;

typedef struct homeworkStack_s{ //�@�~���|
    homework_t *root;           //�@�~���̤W��
}homeworkStack_t;
//---------/typedef----------

//---setList---
void topInList(homeworkStack_t *stack, homework_t *newHW){  //�q�W���J���|
    if(stack->root != NULL){        //�p�G���|���O�Ū�
        newHW->next = stack->root;  //�N�s�@�~���U�@�ӫ��V�̤W��
    }                                                           //�N��������ȩ�b�̤W��
    stack->root = newHW;            //�N�Ĥ@�ӫ��V�s��
}

homework_t* createNewHomework(char *name, int isDelay){ //�إ߷s���@�~
    homework_t *newHW=(homework_t*)malloc(sizeof(homework_t));  //���@�~�@�ӰO�����m
    strcpy(newHW->name, name);  //�g�J�W��
    newHW->isDelay = isDelay;   //���S�����
    newHW->next = NULL;         //�U�@�Ӧ�m�]�w�� NULL
    return newHW;               //�^�Ǹӧ@�~
}
//--/setList---

//----------input------------
void input(homeworkStack_t *stack){   //��J
    homework_t *newHW=NULL;
    char inName[10]="";
    gets(inName);                               //��J
    while(strcmp(inName, "-1")){                //�����J -1 �ɰ���
        newHW = createNewHomework(inName, 0);   //�إ߷s���@�~
        topInList(stack, newHW);                //��J���|��
        gets(inName);                           //�~���J
    }
}
//---------/input------------

//----------run--------------
//-------makeUpHW-------
void makeUpHW(homeworkStack_t *stack, char *name){  //�ɥ�@�~
    homework_t *newHW=NULL;
    newHW = createNewHomework(name, 1); //�إ߷s���@�~  �i�אּ�@��
    topInList(stack, newHW);            //��J���|��    topInList(stack, createNewHomework(name, 1);
}
//------/makeUpHW-----------

//-----output-----
void output(homework_t *HW){            //��X�@�~���p
    printf("%s's HW is ", HW->name);    //��X�@�~���֦���
    if(!HW->isDelay){                   //�p�G�@�~�S�����
        printf("not ");                 //    ��X not delay
    }
    printf("delay\n");                  //
}

//-------correctionHW-------
void correctionHW(homeworkStack_t *stack){  //��@�~
    homework_t *newTop=NULL;
    if(stack->root == NULL){    //�p�G�w�g�S���@�~�F
        printf("Empty\n");      //    ��X��
    }
    else{
        output(stack->root);        //��X�̤W�h���@�~
        newTop = stack->root->next; //�N���h���U�@���@�~�����_��
        free(stack->root);          //�N�O����Ŷ�����^�h
        stack->root = newTop;       //�s�����h�אּ�U�@���@�~
    }
}
//------/correctionHW-------

//-------offWork------------
void offWork(homeworkStack_t *stack){   //�U�Z
    homework_t *nextHW=NULL;
    if(stack->root == NULL){    //�p�G�w�g�ŤF
        printf("Empty\n");      //    ��X��
    }
    while(stack->root != NULL){     //������|�M��
        output(stack->root);        //    ��X�@�~��T
        nextHW = stack->root->next; //    �O���U�@���@�~
        free(stack->root);          //    �N�ثe���@�~�R��
        stack->root = nextHW;       //    ���h���V�U�@���@�~
    }
}
//------/offWork------------
//----/output-----
void run(homeworkStack_t *stack){
    char in[20]="";
    char *select, *name;
    gets(in);
    while(1){
        select = strtok(in, " ");       //���X��ܪ��Ҧ�
        if(!strcmp(select, "1")){       //�ɥ�@�~ (push) �O���ɥ檺�@�~�A�ðO�����
            name = strtok(NULL, " ");   //���ΥX�ǥͦW��
            makeUpHW(stack, name);      //�ɥ�@�~
        }
        else if(!strcmp(select, "2")){  //��@�~ (pop) ��X�O�_���@�~�C�p�G�粒�A��X Empty
            correctionHW(stack);        //��@�~
        }
        else if(!strcmp(select, "3")){  //�U�Z�A�L�X�٨S�諸�@�~���ǥͦW�١B��檬�p�A�p�G�@�~�粒�A��X Empty
            offWork(stack);             //�U�Z
            break;                      //���}
        }
        gets(in);
    }
}
//---------/run--------------

int main(){
    homeworkStack_t stack={NULL};   //�إ߰��|
    input(&stack);  //��J ���ƿ�J�W�� �����J -1 ����
    run(&stack);    //�}�l��@�~
//    printf("Hello world!\n");
    return 0;
}
