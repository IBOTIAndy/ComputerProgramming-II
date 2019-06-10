#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//028 Linked list Queue實作
//2019/06/10 AM. 09:00 IBOTIAndy
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
    queue->size = queue->size + 1;          //將資料數量 + 1
}

void enterQueueData(queueList_t *queueList){    //輸入 Queue 資料
    queue_t *currently=NULL;
    char name[20]="";
    gets(name);                                 //輸入選擇的 Queue
    if(queueList->root == NULL){                //如果沒有任何的 Queue
        printf("Queue %s isn't exist\n", name); //    輸出沒找到
        return;                                 //    跳出
    }
    currently = queueList->root;                    //紀錄第一個 Queue
    while(currently != NULL){                       //直到全部找完
        if(!strcmp(currently->name, name)){         //如果找到要找的名稱
            createElement(currently);               //    建立元素並放入
            return;                                 //    跳出
        }
        currently = currently->next;        //找下一個 Queue
    }                                       //如果沒找到
    printf("Queue %s isn't exist\n", name); //輸出沒找到
}
//------/enterQueueData-------

//-------deleteQueue----------
int queueIsEmpty(element_t *data){  //queue 是空的嗎?
    if(data == NULL){               //如果 queue 是空的
        printf("Queue is empty\n"); //輸出 "Queue is empty"
        return 1;
    }
    return 0;
}

element_t* deleteQueueRoot(queue_t *queue){
    element_t *newRoot=NULL;
    if(queueIsEmpty(queue->root)){        //如果 queue 是空的
        return queue->root;
    }
    newRoot = queue->root->next;
    queue->size = queue->size - 1;
    return newRoot;
}

queue_t* deleteFindQueue(queue_t *root, char *name){  //找 Queue
    queue_t *before=NULL;
    queue_t *currently=NULL;
    currently = root;                   //紀錄第一個 Queue
    while(currently != NULL){                               //直到全部找完
        if(!strcmp(currently->name, name)){                 //如果找到要找的名稱
            currently->root = deleteQueueRoot(currently);   //    Queue
            return root;                                    //    跳出，回傳開頭
        }
        before = currently;                 //前一個指向目前
        currently = currently->next;        //找下一個 Queue
    }                                       //如果沒找到
    printf("Queue %s isn't exist\n", name); //輸出沒找到
    return root;                            //跳出，回傳開頭
}

void deleteQueue(queueList_t *queueList){   //刪除 Queue
    char name[20]="";
    gets(name);                                 //輸入選擇的 Queue
    if(queueList->root == NULL){                //如果沒有任何的 Queue
        printf("Queue %s isn't exist\n", name); //    輸出沒找到
        return;                                 //    跳出
    }
    deleteFindQueue(queueList->root, name);    //找 Queue 並回傳開頭
}
//------/deleteQueue----------

//-------mergeQueue-----------
queue_t* findQueue(queue_t *currently, char *name){ //找 Queue
    while(currently != NULL){               //全部搜尋
        if(!strcmp(currently->name, name)){ //如果找到
            break;                          //跳出迴圈
        }
        currently = currently->next;        //繼續找
    }                   //如果沒找到 則代表 currently = NULL
    return currently;   //回傳找到的 Queue，或是 NULL
}

element_t* mergeElement(element_t *elementA, element_t *elementB){  //連結 Element
    element_t *currently=NULL;
    if(elementA == NULL){               //如果第一個 element 是空的
        return elementB;                //回傳 element B
    }                                   //如果不是空的
    currently = elementA;               //目前指定為 element A
    while(currently->next != NULL){     //直到找到 element A 的結尾
        currently = currently->next;    //目前繼續往下走
    }                                   //找到結尾
    currently->next = elementB;         //結尾的下一個 指向 element B 的開頭
    return elementA;                    //回傳開頭
}

queue_t* deleteQueueB(queue_t *root, char *name){
    queue_t *before=NULL;
    queue_t *currently=NULL;
    currently = root;                   //紀錄第一個 Queue
    if(!strcmp(currently->name, name)){ //如果第一個就是
        root = currently->next;         //    最上層
        free(currently);                //    釋放記憶體
        return root;                    //    跳出，回傳開頭
    }
    while(currently != NULL){               //直到全部找完
        if(!strcmp(currently->name, name)){ //如果找到要找的名稱
            before->next = currently->next; //    前一個的下一個改為目前的下一個(1->2,2->3) => (1->3)
            free(currently);                //    釋放記憶體
            return root;                    //    跳出，回傳開頭
        }
        before = currently;                 //前一個指向目前
        currently = currently->next;        //找下一個 Queue
    }                                       //如果沒找到
    printf("Queue %s isn't exist\n", name); //輸出沒找到
    return root; //跳出，回傳開頭
}

void mergeQueue(queueList_t *queueList){    //連接兩個 Queue
    queue_t *queueA=NULL, *queueB=NULL;
    int canWork=0;
    char nameA[20]="", nameB[20]="";
    canWork = 1;    //可以正常運作
    gets(nameA);    //輸入第一個名稱
    gets(nameB);    //輸入第二個名稱
    queueA = findQueue(queueList->root, nameA);     //找第一個 Queue
    if(queueA == NULL){                             //如果沒找到
        printf("Queue %s isn't exist\n", nameA);    //輸出找不到
        canWork = 0;                                //不能運作
    }
    queueB = findQueue(queueList->root, nameB);     //找第二個 Queue
    if(queueB == NULL){                             //如果沒找到
        printf("Queue %s isn't exist\n", nameB);    //輸出找不到
        canWork = 0;                                //不能運作
    }
    if(canWork){                                                    //如果可以運作
        queueA->root = mergeElement(queueA->root, queueB->root);    //連接兩個 Element 串列
        queueA->size = queueA->size + queueB->size;                 //串列長度相加
        queueList->root = deleteQueueB(queueList->root, nameB);     //移除 QueueB
    }
}
//------/mergeQueue-----------

//-------printAllQueue--------
void printElement(element_t *currently){    //輸出資料
    while(currently != NULL){           //直到資料輸出完
        printf("%d ", currently->data); //輸出資料
        currently = currently->next;    //指向下一個資料
    }
}

void printAllQueue(queueList_t *queueList){ //輸出全部的 Queue
    queue_t *currently=NULL;
    printf("****************************************\n");
    if(queueList->root == NULL){            //如果甚麼都沒有
        printf("Isn't have any queue\n");   //
    }
    else{
        currently = queueList->root;                    //指向第一個 Queue
        while(currently != NULL){                       //全部輸出
            printf("Queue Name:%s ", currently->name);  //輸出名稱
            printf("Queue Size:%d ", currently->size);  //輸出資料大小
            printf("Queue Element:");                   //輸出資料
            if(currently->root == NULL){                //如果沒資料
                printf("Queue is empty");               //輸出空
            }
            else{                                       //如果有資料
                printElement(currently->root);          //輸出資料
            }
            printf("\n");                               //換行
            currently = currently->next;                //做下一個 Queue
        }
    }
    printf("****************************************\n");
}
//------/printAllQueue--------

void run(queueList_t *queueList){
    char in[2]="";
    while(1){
        gets(in);
        if(!strcmp(in, "1")){       //Create_queue
            createQueue(queueList);     //建立一個 Queue
        }
        else if(!strcmp(in, "2")){  //Enter_queue_data
            enterQueueData(queueList);  //將資料輸入現有的 Queue
        }
        else if(!strcmp(in, "3")){  //Delete_queue
            deleteQueue(queueList);     //刪除 Queue
        }
        else if(!strcmp(in, "4")){  //Merge_queue
            mergeQueue(queueList);      //合併 Qqueue
        }
        else if(!strcmp(in, "5")){  //Print_all_queue
            printAllQueue(queueList);   //輸出全部的 Queue
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
