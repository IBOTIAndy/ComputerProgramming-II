#include <stdio.h>
#include <stdlib.h>
//023 模擬讀檔
//2019/05/14 PM. 02:23 IBOTIAndy
//----------typedef----------
typedef struct file_s{
    char name[50];
    int list[100];
}file_t;
//---------/typedef----------

//----------write------------
int duplicateFileName(){return 0;}

void writeFile(){}

void write(file_t file[]){
    char name[50]="";           //暫存的名稱
    int list[100]={0};          //暫存的資料
    if(duplicateFileName()){    //如果有重複的檔案名稱
        printf("Error\n");      //輸出錯誤
    }
    else{                       //如果沒有重複的檔案名稱
        writeFile();            //存檔
    }
}
//---------/write------------

//----------read-------------
void read(){}
//---------/read-------------

//----------edit-------------
void edit(){}
//---------/edit-------------

void run(file_t file[]){
    int select=0;
    while(1){
        scanf("%d", &select);
        if(select == 1){
//            write(file);
        }
        else if(select == 2){
//            read(file);
        }
        else if(select == 3){
//            edit(file);
        }
        else if(select == 4){
            break;
        }
    }
}

int main(){
    file_t file[20];
    run(file);
//    printf("Hello world!\n");
    return 0;
}
