#include <stdio.h>
#include <stdlib.h>
//017 專題老師志願序
//2019/04/19 IBOTIAndy AM. 01:10
typedef struct{                 //志願清單
    char studentName[10];       //學生名稱
    char studentOrder[10][10];  //學生志願序
    int studentN;               //學生數量
    char teacherName[10];       //老師名稱
    char teacherOrder[10][10];  //老師志願序
    int teacherM;               //老師數量
}volunteerOrder;
//----------input----------
void setlist(volunteerOrder *list){ //設定基本資訊
    list->studentName[0] = 'W';
    list->studentName[1] = 'X';
    list->studentName[2] = 'Y';
    list->studentName[3] = 'Z';
    list->teacherName[0] = 'A';
    list->teacherName[1] = 'B';
    list->teacherName[2] = 'C';
    list->teacherName[3] = 'D';
    list->studentN = 4;
    list->teacherM = 4;
}

void input(volunteerOrder *list){   //輸入
    char inputString[30]="";        //輸入的暫存陣列
    int i=0, j=0, n=4;
    setlist(list);                  //設定基本資訊
    for(i=0; i < n; i++){                           //輸入學生志願序
        gets(inputString);                          //取得整行
        list->studentOrder[i][0] = inputString[0];  //輸入學生第一個志願
        list->studentOrder[i][1] = inputString[2];  //輸入學生第二個志願
        list->studentOrder[i][2] = inputString[4];  //輸入學生第三個志願
        list->studentOrder[i][3] = inputString[6];  //輸入學生第四個志願
    }
    for(j=0; j < n; j++){                           //輸入老師志願序
        gets(inputString);                          //取得整行
        list->teacherOrder[j][0] = inputString[0];  //輸入老師第一個志願
        list->teacherOrder[j][1] = inputString[2];  //輸入老師第二個志願
        list->teacherOrder[j][2] = inputString[4];  //輸入老師第三個志願
        list->teacherOrder[j][3] = inputString[6];  //輸入老師第四個志願
    }
}
//---------/input----------

//-----------run-----------
void teacherSelect(){}

void studentSelect(){}

void run(volunteerOrder list){}
//----------/run-----------

//----------test-----------
void inputView(volunteerOrder list){                //輸入確認
    int i=0, j=0;
    printf("studentN = %d\n", list.studentN);       //輸出學生數量
    printf("teacherM = %d\n", list.teacherM);       //輸出老師數量
    for(i=0; i < list.studentN; i++){               //直到全部學生都輸出完
        printf("%c: ", list.studentName[i]);            //輸出學生名字
        for(j=0; j < list.teacherM; j++){               //直到單個學生志願序輸出完
            printf("%c", list.studentOrder[i][j]);          //輸出學生選擇的第 j 位老師
            if(j + 1 != list.teacherM){                     //如果還沒到最後
                printf(", ");                               //輸出逗號 (，) 分隔
            }
        }                                               //其中一個學生的志願序輸出完畢
        printf("\n");                                   //換行
    }
    printf("\n");                                   //全部學生輸出完，中間空行與老師分開
    for(i=0; i < list.teacherM; i++){               //直到全部老師都輸出完
        printf("%c: ", list.teacherName[i]);            //輸出老師名字
        for(j=0; j < list.studentN; j++){               //直到單個老師志願序輸出完
            printf("%c", list.teacherOrder[i][j]);          //輸出老師選擇的第 j 位學生
            if(j + 1 != list.studentN){                     //如果還沒到最後
                printf(", ");                               //輸出逗號 (，) 分隔
            }
        }                                               //其中一個老師的志願序輸出完畢
        printf("\n");                                   //換行
    }
}
//---------/test-----------

int main(){
    volunteerOrder list={" ", {""}, 0, " ", {""}, 0};   //
    input(&list);                                       //輸入
//    inputView(list);                                    //測試輸入正不正確
    run(list);                                          //執行
    //printf("Hello world!\n");
    return 0;
}
