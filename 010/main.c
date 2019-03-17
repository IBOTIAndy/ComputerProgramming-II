#include <stdio.h>
#include <string.h>
//010 解密碼
//2019/03/17 PM. 05:33 IBOTIAndy
typedef struct{     //定義結構
    char *string;   //字元(串)指標
}stringArray;       //字串陣列

typedef struct{                 //定義結構
    stringArray strings[50];    //字串陣列
    int stringMaximum;          //存入的字串數量
    int ansNow;                 //答案目前暫用的字元數
    char ans[100];              //答案
}decoder;                       //解碼器

void enterString(stringArray *s, char *word){   //儲存字串
    s->string = word;                           //將字串的開頭位置，存入結構的指標
}

void cutinput(char text[], decoder *decoder){       //切割字串
    int i=0;                                        //
    char *word;                                     //建立字串(字元)指標
    word = strtok(text, " ");                       //切割字串，以空格為斷點。存入指標中
    enterString(&(decoder->strings[0]), word);      //將指標寫入結構裡儲存
    i = 1;                                          //因為第一次(位置0)寫過了，所以儲存位置+1
    while(word != NULL){                            //持續直到字串切割完畢
        word = strtok(NULL, " ");                   //切割字串，以空格為斷點。存入指標中
        enterString(&(decoder->strings[i]), word);  //將指標寫入結構裡儲存
        i = i + 1;                                  //
    }
    decoder->stringMaximum = i - 1;                 //記錄儲存的字串數量
//    i = 0;                                          //測試用
//    while(decoder->strings[i].string != NULL){
//        printf("%s\n", decoder->strings[i].string);
//        i = i + 1;
//    }
}

void input(char ciphertext[], decoder *decoder){    //輸入
    gets(ciphertext);                               //取一整行輸入
    cutinput(ciphertext, decoder);                  //切割輸入的字串
}

void output(char ans[]){}

void decodeNumber(decoder *decoder1){}

void decodeWord(decoder *decoder1){}

void run(decoder decoder1, decoder decoder2){   //開始解碼
    char ans[100]="";                           //
    decodeNumber(&decoder1);                    //解第一組密碼(取數字顛倒相加)
    decodeWord(&decoder2);                      //解第二組密碼(字元出現次數)
    output(ans);                                //輸出密碼答案
}

void testinputdata(decoder decoderData){                            //查看輸入的資料
    int i=0;
    while(decoderData.strings[i].string != NULL){                   //直到沒有資料
    //while(i < decoderData.stringMaximum){                           //直到判斷到最後一個字串
        printf("%d: %s\n", i + 1, decoderData.strings[i].string);   //輸出分割好的字串
        i = i + 1;                                                  //
    }
}

int main(){
    char ciphertext1[100]="";           //定義第一組密碼
    char ciphertext2[100]="";           //定義第二組密碼
    decoder decoder1={{}, 0, 0, ""};    //定義第一組解密碼器
    decoder decoder2={{}, 0, 0, ""};    //定義第二組解密碼器
    input(ciphertext1, &decoder1);      //輸入密碼
    input(ciphertext2, &decoder2);      //輸入密碼
    //testinputdata(decoder1);            //輸入答案的測試
    //testinputdata(decoder2);            //輸入答案的測試
    run(decoder1, decoder2);            //執行
//    printf("Hello world!\n");
    return 0;
}
