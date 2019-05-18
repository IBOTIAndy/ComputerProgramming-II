#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//024 模擬 Linux Command-Line Interface
//2019/05/18 PM. 11:44 IBOTIAndy
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

enum type{not, touch, vim, cat, head, tail};
//---------/typedef----------

//----------run--------------
//-------inputSet--------
void stringCut(char in[], commandLine_t *list){  //字串切割
    //字串切割
    //切出指令，參數
}

int selectType(char *command){return not;}
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
    enum type select=not;
    commandLine_t commandLine;
    gets(in);                                   //輸入
    stringCut(in, &commandLine);                //切割輸入
    select = selectType(commandLine.command);   //選擇要使用的指令
    if(select == touch){        //建立檔案
        create(fileList, commandLine.parameterList);
    }
    else if(select == vim){     //檔案書寫
        write(fileList, commandLine.parameterList);
    }
    else if(select == cat){     //查看檔案
        read(fileList, commandLine.parameterList);
    }
    else if(select == head){    //查看檔案 從前面開始
        readHead(fileList, commandLine.parameterList);
    }
    else if(select == tail){    //差看檔案 從後面開始
        readTail(fileList, commandLine.parameterList);
    }
}
//---------/run--------------

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
