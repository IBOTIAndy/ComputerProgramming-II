#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//028 Linked list Queue實作
//2019/05/30 PM. 02:53 IBOTIAndy
//----------typedef----------
typedef struct element_s{   //元素結構
    int data;               //元素
    struct element_s *next; //下一個元素
}element_t;

typedef struct queue_s{     //隊伍
    char name[20];          //名稱
    element_t *root;        //裡面元素的開頭
    int size;               //多少元素
    struct queue_s *next;   //下一個隊伍
}queue_t;

typedef struct queueList_s{ //隊伍的串列
    queue_t *root;          //第一個隊伍
}queueList_t;
//---------/typedef----------

//----------
queue_t* createNewQueue(char *name){    //建立新 queue 並回傳
    queue_t *newQueue=(queue_t*)malloc(sizeof(queue_t));    //給予新的 queue 空間
    strcpy(newQueue->name, name);   //設定名稱
    newQueue->root=NULL;            //檔案指向 NULL
    newQueue->size=0;               //檔案大小初始值
    newQueue->next=NULL;            //下一個 queue 為 NULL
    return newQueue;                //回傳新的 queue 記憶體位置
}

//----------run--------------
//-------createQueue-------
queue_t* setListTail(queue_t *root, queue_t *newQueue){    //設定 queue 串列
    queue_t *currently=NULL;
    if(root == NULL){                   //如果沒有任何的 queue
        return newQueue;                //回傳新的 queue 位置
    }
    currently = root;                   //目前指向第一個
    while(currently->next != NULL){     //如果下一個位置不是空的
        currently = currently->next;    //往下走
    }                                   //直到最後一個
    currently->next = newQueue;         //將新的 queue 放在最後面
    return root;                        //回傳開頭
}

void createQueue(queueList_t *queueList){   //建立 queue
    char name[20]="";   //queue 的名稱
    queue_t *newQueue=NULL;             //新增一個 queue 指標
    gets(name);                         //輸入名稱
    newQueue = createNewQueue(name);    //建立 queue 並回傳記憶體位置
    queueList->root = setListTail(queueList->root, newQueue);   //將新的 queue 放入串列的尾部
}
//------/createQueue-------

void run(queueList_t *queueList){
    char in[2]="";
    while(1){
        gets(in);
        if(!strcmp(in, "1")){       //Create_queue
            createQueue(queueList); //建立一個 queue
        }
        else if(!strcmp(in, "2")){  //Enter_queue_data
//            enterQueueData();
        }
        else if(!strcmp(in, "3")){  //Delete_queue
//            deleteQueue();
        }
        else if(!strcmp(in, "4")){  //Merge_queue
//            mergeQueue();
        }
        else if(!strcmp(in, "5")){  //Print_all_queue
//            printAllQueue();
        }
        else if(!strcmp(in, "6")){  //Exit
            break;
        }
    }
}
//---------/run--------------

int main(){
    queueList_t queueList={NULL};
    run(&queueList);
//    printf("Hello world!\n");
    return 0;
}
