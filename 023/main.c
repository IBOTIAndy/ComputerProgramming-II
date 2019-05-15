#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//023 模擬讀檔
//2019/05/15 PM. 04:43 IBOTIAndy
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

void write(file_t file[]){  //寫檔 (寫入模式)
    char name[50]="";           //暫存的名稱
    int list[100]={0};          //暫存的資料
    int i=0;
    scanf("%c", &name[0]);      //去除換行字元
    printf("Mod: write:\n");    //UI 目前模式
    printf("name: ");           //UI 要寫入的名稱
    gets(name);                 //取檔案名稱
    printf("data:\n");          //UI 要寫入的資料
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
int findFile(file_t file[], char name[], int *i){   //找檔案
    while(file[*i].name[0] != '\0'){                //直到沒有檔案
        if(strcmp(file[*i].name, name) == 0){       //如果檔案名稱相同 (找到檔案)
            return 1;                               //回傳找到了 (if(1))
        }
        *i = *i + 1;
    }
    return 0;                                       //如果都沒找到 回傳沒找到 (if(0))
}

//-----output-----
void changeToBinary(int data, int binary[], int n){ //將十進位轉為二進位
    int i=0;
    for(i=0; i < n; i++){       //直到做了 n 次(指定的 n bit)
        binary[i] = data % 2;   //二進位為十進位除二取餘數
        data = data / 2;        //十進位為十進位除二取商數
    }                           //(使用短除法)
}

void outputBinary(int binary[], int n){ //輸出二進位
    int i=0;
    for(i = n - 1; i >= 0; i--){    //從最大的開始輸出
        printf("%d ", binary[i]);   //輸出二進位
    }
    printf("\n");                   //輸出完，換行
}

void output(file_t file){   //輸出
    int i=0, n=0;
    int binary[8]={0};                              //暫存二進位
    while(file.list[n] != -1){                      //找資料總共幾筆
        n = n + 1;
    }
    printf("%d bytes\n", n);                        //輸出資料數量
    for(i=0; i < n; i++){                           //將全部資料輸出
        changeToBinary(file.list[i], binary, 8);    //將資料轉為二進位
        outputBinary(binary, 8);                    //輸出二進位狀態的資料
    }
}
//----/output-----

void read(file_t file[]){           //讀檔 (讀取模式)
    int i=0;
    char name[50];
    scanf("%c", &name[0]);          //去除換行
    printf("Mod: read:\n");         //UI 目前模式
    printf("name: ");               //UI 檔案名稱是甚麼
    gets(name);                     //輸入檔案名稱
    printf("\n");                   //UI 換行
    if(findFile(file, name, &i)){   //如果找到檔案
        printf("Data:\n");          //UI 資料
        output(file[i]);            //輸出
    }
    else{                           //如果沒找到檔案
        printf("Error\n");          //輸出錯誤
    }
}
//---------/read-------------

//----------edit-------------
void editFile(file_t *file){    //改變檔案內的資料
    int m=0;                            //第 m 個資料
    printf("m: ");                      //UI 第幾筆資料
    scanf("%d", &m);                    //輸入要改第幾個資料
    printf("change to: ");              //UI 改為
    scanf("%d", &file->list[m - 1]);    //將檔案改為新的值

}

void edit(file_t file[]){   //改檔 (更改內容)
    int i=0;
    char name[50];
    scanf("%c", &name[0]);          //去除換行
    printf("Mod: edit:\n");         //UI 目前模式
    printf("name: ");               //UI 檔案名稱是甚麼
    gets(name);                     //輸入檔案名稱
    printf("\n");                   //UI 換行
    if(findFile(file, name, &i)){   //如果找到檔案
        editFile(&(file[i]));       //更改
    }
    else{                           //如果沒找到檔案
        printf("Error\n");          //輸出錯誤
    }
}
//---------/edit-------------

void run(file_t file[]){
    int select=0;
    while(1){
        printf("Select mod:\n");    //測試時使用
        printf("1. write\n");       //UI 四
        printf("2. read\n");        //UI 種
        printf("3. edit\n");        //UI 模
        printf("4. exit\n");        //UI 式
        scanf("%d", &select);       //選擇模式
        printf("\n");               //UI
        if(select == 1){
            write(file);
        }
        else if(select == 2){
            read(file);
        }
        else if(select == 3){
            edit(file);
        }
        else if(select == 4){
            break;
        }
        printf("\n");               //UI
    }
}

int main(){
    file_t file[20]={{"", {0}}};
    run(file);
//    printf("Hello world!\n");
    return 0;
}
