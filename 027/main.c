#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//027 助教改作業
//2019/05/26 PM. 00:54 IBOTIAndy
//----------typedef----------
typedef struct homework_s{      //作業結構
    char name[10];              //作業的擁有者
    int isDelay;                //有沒有遲交
    struct homework_s *next;    //下一份作業
}homework_t;
//---------/typedef----------

//---setList---
homework_t* topInList(homework_t *topHW, homework_t *newHW){    //從上方放入陣列
    if(topHW != NULL){          //如果陣列不是空的
        newHW->next = topHW;    //將新作業的下一個指向最上面
    }                                                           //就像直接把紙放在最上面
    return newHW;               //回傳新作業的位置
}
//--/setList---

//----------input------------
homework_t* input(homework_t *topHW){   //輸入
    homework_t *newHW=NULL;
    char inName[10]="";
    gets(inName);                                   //輸入
    while(strcmp(inName, "-1")){                    //直到輸入 -1 時停止
        newHW = malloc(sizeof(homework_t));         //建立新的空間給新作業
        strcpy(newHW->name, inName);                //將輸入的名稱
        newHW->isDelay = 0;                         //將是否遲交設定為 False
        topHW = topInList(topHW, newHW);            //放入陣列中 回傳最上方的位置
        gets(inName);                               //繼續輸入
    }
    return topHW;
}
//---------/input------------

int main(){
    homework_t *topHW=NULL; //陣列的開頭
    topHW = input(topHW);   //輸入 重複輸入名稱 直到輸入 -1 結束
//    printf("Hello world!\n");
    return 0;
}
