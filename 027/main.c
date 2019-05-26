#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//027 助教改作業
//2019/05/26 PM. 11:30 IBOTIAndy
//----------typedef----------
typedef struct homework_s{      //作業結構
    char name[10];              //作業的擁有者
    int isDelay;                //有沒有遲交
    struct homework_s *next;    //下一份作業
}homework_t;
//---------/typedef----------

//---setList---
homework_t* topInList(homework_t *topHW, homework_t *newHW){    //從上方放入陣列
    if(topHW != NULL){          //如果陣列不是空的@#$%^&*&^%$#%^&*()@*$&^%@^#&
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
    return topHW;                           //回傳最上面那份作業
}
//---------/input------------

//----------run--------------
//-------makeUpHW-------
homework_t* makeUpHW(homework_t *topHW, char *name){    //補交作業
    homework_t *newHW=NULL;
    newHW = malloc(sizeof(homework_t)); //建立新的空間給新作業
    strcpy(newHW->name, name);          //將輸入的名稱
    newHW->isDelay = 1;                 //將是否遲交設定為 True
    topHW = topInList(topHW, newHW);    //放入陣列中 回傳最上方的位置
    return topHW;                       //回傳最上面那份作業
}
//------/makeUpHW-----------

//-----output-----
void output(homework_t *HW){            //輸出作業狀況
    printf("%s's HW is ", HW->name);    //輸出作業的擁有者
    if(!HW->isDelay){                   //如果作業沒有遲交
        printf("not ");                 //輸出 not delay
    }
    printf("delay\n");                  //
}

//-------correctionHW-------
homework_t* correctionHW(homework_t *topHW){    //改作業
    homework_t *newTop=NULL;
    if(topHW == (homework_t*)NULL){          //如果已經沒有作業了
        printf("Empty\n");      //輸出空
        return topHW;           //回傳原本的位置
    }
    newTop = topHW->next;       //新的頂層為下一份作業
    output(topHW);              //輸出最上層的作業
    return newTop;              //回傳新的頂層
}
//------/correctionHW-------
//----/output-----
void run(homework_t *topHW){
    char in[20]="";
    char *select, *name;
    gets(in);
    while(1){
        select = strtok(in, " ");           //切出選擇的模式
        if(!strcmp(select, "1")){           //補交作業 (push) 記錄補交的作業，並記錄遲交
            name = strtok(NULL, " ");       //切割出學生名稱
            topHW = makeUpHW(topHW, name);  //補交作業
        }
        else if(!strcmp(select, "2")){      //改作業 (pop) 輸出是否遲交作業。如果改完，輸出 Empty
            topHW = correctionHW(topHW);    //改作業
        }
        else if(!strcmp(select, "3")){      //下班，印出還沒改的作業的學生名稱、遲交狀況，如果作業改完，輸出 Empty
//            offWork(topHW);
            break;
        }
        gets(in);
    }
}
//----------run--------------

int main(){
    homework_t *topHW=NULL; //陣列的開頭
    topHW = input(topHW);   //輸入 重複輸入名稱 直到輸入 -1 結束
    run(topHW);             //開始改作業
//    printf("Hello world!\n");
    return 0;
}
