#include <stdio.h>
#include <string.h>
#include <math.h>
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

//-----run-----
//--decoder1--
int isNumber(char *string){     //判斷是不是全部數字
    int i=0;
    while(string[i] != '\0'){                   //直到結束字元( '\0' )
        if(string[i] > '9' || string[i] < '0'){ //如果其中一個字元不在數字範圍內(ASCII)
            return 0;                           //回傳0 (False)
        }
        i = i + 1;                              //
    }
    return 1;   //回傳1 (True)
}

int ansMath1(char *string){ //數字翻轉
    int i=0, ans=0;         //
    double carry=0.0;       //進位
    while(string[i] != '\0'){                               //直到字串找完
        carry = pow(10, i);                                 //因為pow();這個函數的輸出直接轉成 int 會有問題
        //printf("carry = %lf, %d\n", carry, (int)carry);     //所以先放入 carry 再強制轉型態
        ans = ans + ((string[i] - '0') * (int)carry);       //輸入答案
        i = i + 1;                                          //往前移一格
    }
    return ans;             //回傳該字串翻轉並改為數字
}

void setAns1(char *decoderAns, int ans){   //設定答案
    int i=0;
    ans = ans % 10000;          //去掉超過四位數的位置
    for(i=3; i >= 0; i--){                  //從個位數輸入
        decoderAns[i] = '0' + (ans % 10);   //'0' + x 位元 例: 4 = '0' + 4 => '4'
        ans = ans / 10;                     //去除個位數
    }
    //printf("%s\n", decoderAns); //測試用
}

void decodeNumber(decoder *decoder1){   //解碼第一個字串(找數字，顛倒，相加，存到千位
    int i=0, ans=0;
    while(decoder1->strings[i].string != NULL){                 //直到整句子讀完
        if(isNumber(decoder1->strings[i].string)){              //如果找到數字
            ans = ans + ansMath1(decoder1->strings[i].string);  //答案加上顛倒的該數字
            //printf("%d\n", ans);                                //測試答案對不對
        }
        i = i + 1;                                              //
    }
    setAns1(decoder1->ans, ans);        //將答案寫入 decorder 儲存
    //printf("%s\n", decoder1->ans);      //查看答案對不對
}
//-/decoder1--
//--decoder2--
void decodeWord(decoder *decoder1){}
//-/decoder2--

void run(decoder decoder1, decoder decoder2){   //開始解碼
    char ans[100]="";                           //
    decodeNumber(&decoder1);                    //解第一組密碼(取數字顛倒相加)
    decodeWord(&decoder2);                      //解第二組密碼(字元出現次數)
    output(ans);                                //輸出密碼答案
}
//----/run-----

//-----test-----
void testinputdata(decoder decoderData){                            //查看輸入的資料
    int i=0;
    while(decoderData.strings[i].string != NULL){                   //直到沒有資料
    //while(i < decoderData.stringMaximum){                           //直到判斷到最後一個字串
        printf("%d: %s\n", i + 1, decoderData.strings[i].string);   //輸出分割好的字串
        i = i + 1;                                                  //
    }
}
//----/test-----

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
