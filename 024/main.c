#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//024 模擬 Linux Command-Line Interface
//2019/05/19 AM. 03:12 IBOTIAndy
//----------typedef----------
typedef struct file_s{  //檔案
    char name[20];      //檔案名稱
    char data[200];     //檔案資料
}file_t;

typedef struct fileList_s{  //檔案列表
    file_t file[20];        //檔案
    int n;                  //目前檔案數量
}fileList_t;

typedef struct parameterList_s{ //參數陣列
    char *parameter[20];        //參數
    int n;                      //參數數量
}parameterList_t;

typedef struct commandLine_s{       //指令
    char *command;                  //使用的指令
    parameterList_t parameterList;  //參數s
}commandLine_t;

enum type{not_e, touch_e, vim_e, cat_e, head_e, tail_e, exit_e};
//---------/typedef----------

//----------run--------------
//-------inputSet--------
void parameterCut(parameterList_t *parameterList){  //切割參數
    int i=0;
    parameterList->parameter[i] = strtok(NULL, " ");        //先切一次
    while(parameterList->parameter[i] != NULL){             //直到切完東西
        i = i + 1;
        parameterList->parameter[i] = strtok(NULL, " ");    //繼續切割
    }                       //因為切完的時候 i 會在空的那個位子 所以:
    parameterList->n = i;   //參數數量為 i
}

void stringCut(char in[], commandLine_t *list){  //字串切割
    list->command = strtok(in, " ");        //第一次切割，取指令
    parameterCut(&(list->parameterList));   //切割參數
}

int selectType(char *command){  //選擇要使用的指令
    //因為使用列舉 所以直接回傳那個變數 (27行)
    if(!strcmp(command, "touch")){      //建立檔案
        return touch_e;
    }
    else if(!strcmp(command, "vim")){   //檔案書寫
        return vim_e;
    }
    else if(!strcmp(command, "cat")){   //查看檔案
        return cat_e;
    }
    else if(!strcmp(command, "head")){  //查看檔案 從前面開始
        return head_e;
    }
    else if(!strcmp(command, "tail")){  //差看檔案 從後面開始
        return tail_e;
    }
    else if(!strcmp(command, "exit")){  //離開
        return exit_e;
    }
    return not_e;
}
//------/inputSet--------

//-------operation-------
void create(fileList_t fileList, parameterList_t parameterList){}

void write(fileList_t fileList, parameterList_t parameterList){}

void read(fileList_t fileList, parameterList_t parameterList){}

void readHead(fileList_t fileList, parameterList_t parameterList){}

void readTail(fileList_t fileList, parameterList_t parameterList){}
//------/operation-------

void run(){
    fileList_t fileList={{{"", ""}}, 0};
    char in[50]="";
    enum type select=not_e;
    commandLine_t commandLine;
    while(1){
        gets(in);                                   //輸入
        stringCut(in, &commandLine);                //切割輸入
        select = selectType(commandLine.command);   //選擇要使用的指令
        if(select == touch_e){      //建立檔案
            create(fileList, commandLine.parameterList);
        }
        else if(select == vim_e){   //檔案書寫
            write(fileList, commandLine.parameterList);
        }
        else if(select == cat_e){   //查看檔案
            read(fileList, commandLine.parameterList);
        }
        else if(select == head_e){  //查看檔案 從前面開始
            readHead(fileList, commandLine.parameterList);
        }
        else if(select == tail_e){  //差看檔案 從後面開始
            readTail(fileList, commandLine.parameterList);
        }
        else if(select == exit_e){  //結束
            break;
        }
    }
}
//---------/run--------------

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
