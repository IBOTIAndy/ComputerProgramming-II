#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//023 模擬讀檔
//2019/05/15 PM. 02:05 IBOTIAndy
//----------typedef----------
typedef struct file_s{
    char name[50];
    int list[100];
}file_t;
//---------/typedef----------

//----------write------------
int duplicateFileName(file_t file[], char name[]){
    int i=0;
    while(file[i].name[0] != '\0'){
        if(strcmp(file[i].name, name) == 0){
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

void writeFile(file_t file[], char name[], int list[]){ //寫入檔案
    int i=0, j=0;
    while(1){                           //找到空位
        if(file[i].name[i] == '\0'){    //如果是空的
            strcpy(file[i].name, name); //將名稱寫入
            break;                      //跳出迴圈
        }
        i = i + 1;
    }
    while(1){                       //寫入資料
        file[i].list[j] = list[j];  //將數字寫入
        if(list[j] == -1){          //如果是結束符號
            break;                  //跳出迴圈
        }
        j = j + 1;
    }
}

void write(file_t file[]){  //寫入模式
    char name[50]="";           //暫存的名稱
    int list[100]={0};          //暫存的資料
    int i=0;
    scanf("%c", &name[0]);      //去除換行字元
    printf("Mod: write:\n");    //UI
    printf("name: ");           //UI
    gets(name);                 //取檔案名稱
    printf("data:\n");          //UI
    while(1){                   //寫入資料
        scanf("%d", &list[i]);  //將資料寫入暫存區
        if(list[i] == -1){      //如果是結束符號
            break;              //跳出
        }
        i = i + 1;
    }
    if(duplicateFileName(file, name)){  //如果有重複的檔案名稱
        printf("Error\n");              //輸出錯誤
    }
    else{                               //如果沒有重複的檔案名稱
        writeFile(file, name, list);    //存檔
    }
//    printf("%s\n", file[0].name);
//    printf("%d %d %d\n", file[0].list[0], file[0].list[1], file[0].list[2]);
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
        printf("Select mod:\n");    //測試時使用
        printf("1. write\n");       //UI
        printf("2. read\n");        //UI
        printf("3. edit\n");        //UI
        printf("4. exit\n");        //UI
        scanf("%d", &select);       //選擇模式
        printf("\n");               //UI
        if(select == 1){
            write(file);
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
        printf("\n");
    }
}

int main(){
    file_t file[20]={{"", {0}}};
    run(file);
//    printf("Hello world!\n");
    return 0;
}
