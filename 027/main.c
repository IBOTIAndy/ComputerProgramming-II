#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//027 助教改作業
//2019/05/28 PM. 03:21 IBOTIAndy
//----------typedef----------
typedef struct homework_s{      //作業結構
    char name[10];              //作業的擁有者
    int isDelay;                //有沒有遲交
    struct homework_s *next;    //下一份作業
}homework_t;

typedef struct homeworkStack_s{ //作業堆疊
    homework_t *root;           //作業的最上方
}homeworkStack_t;
//---------/typedef----------

//---setList---
void topInList(homeworkStack_t *stack, homework_t *newHW){  //從上方放入堆疊
    if(stack->root != NULL){        //如果堆疊不是空的
        newHW->next = stack->root;  //將新作業的下一個指向最上面
    }                                                           //就像直接把紙放在最上面
    stack->root = newHW;            //將第一個指向新的
}

homework_t* createNewHomework(char *name, int isDelay){ //建立新的作業
    homework_t *newHW=(homework_t*)malloc(sizeof(homework_t));  //給作業一個記憶體位置
    strcpy(newHW->name, name);  //寫入名稱
    newHW->isDelay = isDelay;   //有沒有遲交
    newHW->next = NULL;         //下一個位置設定為 NULL
    return newHW;               //回傳該作業
}
//--/setList---

//----------input------------
void input(homeworkStack_t *stack){   //輸入
    homework_t *newHW=NULL;
    char inName[10]="";
    gets(inName);                               //輸入
    while(strcmp(inName, "-1")){                //直到輸入 -1 時停止
        newHW = createNewHomework(inName, 0);   //建立新的作業
        topInList(stack, newHW);                //放入堆疊中
        gets(inName);                           //繼續輸入
    }
}
//---------/input------------

//----------run--------------
//-------makeUpHW-------
void makeUpHW(homeworkStack_t *stack, char *name){  //補交作業
    homework_t *newHW=NULL;
    newHW = createNewHomework(name, 1); //建立新的作業  可改為一行
    topInList(stack, newHW);            //放入堆疊中    topInList(stack, createNewHomework(name, 1);
}
//------/makeUpHW-----------

//-----output-----
void output(homework_t *HW){            //輸出作業狀況
    printf("%s's HW is ", HW->name);    //輸出作業的擁有者
    if(!HW->isDelay){                   //如果作業沒有遲交
        printf("not ");                 //    輸出 not delay
    }
    printf("delay\n");                  //
}

//-------correctionHW-------
void correctionHW(homeworkStack_t *stack){  //改作業
    homework_t *newTop=NULL;
    if(stack->root == NULL){    //如果已經沒有作業了
        printf("Empty\n");      //    輸出空
    }
    else{
        output(stack->root);        //輸出最上層的作業
        newTop = stack->root->next; //將頂層的下一份作業紀錄起來
        free(stack->root);          //將記憶體空間釋放回去
        stack->root = newTop;       //新的頂層改為下一份作業
    }
}
//------/correctionHW-------

//-------offWork------------
void offWork(homeworkStack_t *stack){   //下班
    homework_t *nextHW=NULL;
    if(stack->root == NULL){    //如果已經空了
        printf("Empty\n");      //    輸出空
    }
    while(stack->root != NULL){     //直到堆疊清空
        output(stack->root);        //    輸出作業資訊
        nextHW = stack->root->next; //    記錄下一份作業
        free(stack->root);          //    將目前的作業刪除
        stack->root = nextHW;       //    頂層指向下一份作業
    }
}
//------/offWork------------
//----/output-----
void run(homeworkStack_t *stack){
    char in[20]="";
    char *select, *name;
    gets(in);
    while(1){
        select = strtok(in, " ");       //切出選擇的模式
        if(!strcmp(select, "1")){       //補交作業 (push) 記錄補交的作業，並記錄遲交
            name = strtok(NULL, " ");   //切割出學生名稱
            makeUpHW(stack, name);      //補交作業
        }
        else if(!strcmp(select, "2")){  //改作業 (pop) 輸出是否遲交作業。如果改完，輸出 Empty
            correctionHW(stack);        //改作業
        }
        else if(!strcmp(select, "3")){  //下班，印出還沒改的作業的學生名稱、遲交狀況，如果作業改完，輸出 Empty
            offWork(stack);             //下班
            break;                      //離開
        }
        gets(in);
    }
}
//---------/run--------------

int main(){
    homeworkStack_t stack={NULL};   //建立堆疊
    input(&stack);  //輸入 重複輸入名稱 直到輸入 -1 結束
    run(&stack);    //開始改作業
//    printf("Hello world!\n");
    return 0;
}
