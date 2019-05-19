#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//024 模擬 Linux Command-Line Interface
//2019/05/19 PM. 02:55 IBOTIAndy
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

enum type{not_e, touch_e, vim_e, cat_e, head_e, tail_e, rm_e, ls_e, exit_e};
//---------/typedef----------

//----------run--------------
//-------inputSet--------
//-----strtok-----
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
//----/strtok-----

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
    else if(!strcmp(command, "rm")){    //移除檔案
        return rm_e;
    }
    else if(!strcmp(command, "ls")){    //列出全部檔案
        return ls_e;
    }
    else if(!strcmp(command, "exit")){  //離開
        return exit_e;
    }
    return not_e;
}
//------/inputSet--------

//-------operation-------
//-----createFile-----
void createNewFile(file_t *file, char *fileName){   //建立新的檔案
    strcpy(file->name, fileName);   //將檔名寫入檔案
}

void create(fileList_t *fileList, parameterList_t parameterList){   //建立檔案，需支援一次建立多個檔案
    int i=0;
    for(i=0; i < parameterList.n; i++){                                                 //直到所有參數都使用完
        createNewFile(&(fileList->file[fileList->n + i]), parameterList.parameter[i]);  //建立新的檔案 (檔案位置, 參數)
    }
    fileList->n = fileList->n + parameterList.n;    //檔案總數 = 目前檔案數 + 參數數量
}
//----/createFile-----

void write(fileList_t fileList, parameterList_t parameterList){}

void read(fileList_t fileList, parameterList_t parameterList){}

void readHead(fileList_t fileList, parameterList_t parameterList){}

void readTail(fileList_t fileList, parameterList_t parameterList){}

void removeFile(fileList_t *fileList, parameterList_t parameterList){}

void listFiles(fileList_t fileList){}
//------/operation-------

//-------view------------
void viewFileData(fileList_t fileList){
    int i=0;
    for(i=0; i < fileList.n; i++){
        printf("%d.%s\n", i + 1, fileList.file[i].name);
        printf("%s\n", fileList.file[i].data);
    }
    printf("\n");
}
//------/view------------

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
            create(&fileList, commandLine.parameterList);
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
        else if(select == rm_e){    //移除檔案
            removeFile(&fileList, commandLine.parameterList);
        }
        else if(select == ls_e){    //列出檔案列表
            listFiles(fileList);
        }
        else if(select == exit_e){  //結束
            break;
        }
        viewFileData(fileList);     //檢查檔案用，看資料寫入正不正確
    }
}
//---------/run--------------

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
