#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//028 Linked list Queue實作
//2019/05/29 PM. 01:21 IBOTIAndy
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

//----------run--------------
void run(queueList_t *queueList){
    char in[2]="";
    while(1){
        gets(in);
        if(!strcmp(in, "1")){       //Create_queue
//            createQueue();
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
