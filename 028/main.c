#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//028 Linked list Queue實作
//2019/05/30 PM. 04:19 IBOTIAndy
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

//----------createNewPoint----------
queue_t* createNewQueue(char *name){    //建立新 queue 並回傳
    queue_t *newQueue=(queue_t*)malloc(sizeof(queue_t));    //給予新的 queue 空間
    strcpy(newQueue->name, name);   //設定名稱
    newQueue->root=NULL;            //檔案指向 NULL
    newQueue->size=0;               //檔案大小初始值
    newQueue->next=NULL;            //下一個 queue 為 NULL
    return newQueue;                //回傳新的 queue 記憶體位置
}

element_t* createNewElement(int data){    //建立新 element 並回傳
    element_t *newElement=(element_t*)malloc(sizeof(element_t));    //給予新的 element 空間
    newElement->data=data;  //將資料寫入新的元素
    newElement->next=NULL;  //下一個 element 為 NULL
    return newElement;      //回傳新的 element 記憶體位置
}
//---------/createNewPoint----------

//----------run--------------
//-------createQueue----------
queue_t* setQueueListTail(queue_t *root, queue_t *newQueue){    //設定 queue 串列
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
    queueList->root = setQueueListTail(queueList->root, newQueue);   //將新的 queue 放入串列的尾部
}
//------/createQueue----------

//-------enterQueueData-------
element_t* setElementListTail(element_t *root, element_t *newElement){  //設定 queue 串列
    element_t *currently=NULL;
    if(root == NULL){                   //如果沒有任何的 queue
        return newElement;              //回傳新的 queue 位置
    }
    currently = root;                   //目前指向第一個
    while(currently->next != NULL){     //如果下一個位置不是空的
        currently = currently->next;    //往下走
    }                                   //直到最後一個
    currently->next = newElement;       //將新的 queue 放在最後面
    return root;                        //回傳開頭
}

void createElement(queue_t *queue){ //建立元素
    int data=0;
    char wrap=' ';
    element_t *newElement=NULL;
    scanf("%d%c", &data, &wrap);            //輸入資料(wrap 是去掉換行)
    newElement = createNewElement(data);    //新建元素，並將資料放入
    queue->root = setElementListTail(queue->root, newElement);  //將元素放入串列的尾部
}

void enterQueueData(queueList_t *queueList){    //輸入 Queue 資料
    queue_t *currently=NULL;
    char name[20]="";
    gets(name);                                 //輸入選擇的 Queue
    if(queueList->root == NULL){                //如果沒有任何的 Queue
        printf("Queue %s isn't exist\n", name); //    輸出沒找到
        return;                                 //    跳出
    }
    currently = queueList->root;            //紀錄第一個 Queue
    while(currently != NULL){               //直到全部找完
        if(!strcmp(currently->name, name)){ //如果找到要找的名稱
            createElement(currently);       //    建立元素並放入
            return;                         //    跳出
        }
        currently = currently->next;        //找下一個 Queue
    }                                       //如果沒找到
    printf("Queue %s isn't exist\n", name); //輸出沒找到
}
//------/enterQueueData-------

void run(queueList_t *queueList){
    char in[2]="";
    while(1){
        gets(in);
        if(!strcmp(in, "1")){       //Create_queue
            createQueue(queueList); //建立一個 queue
        }
        else if(!strcmp(in, "2")){  //Enter_queue_data
            enterQueueData(queueList);  //將資料輸入現有的 queue
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
