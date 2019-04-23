#include <stdio.h>
#include <stdlib.h>
//017 專題老師志願序
//2019/04/23 IBOTIAndy PM. 10:30
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

//-------volunteer-------
//-----commonTeacher-----
void resetCommonTeacher(int commonTeacher[], int n){    //重置commonTeacher
    int i=0;
    for(i=0; i < n; i++){
        commonTeacher[i] = 0;
    }
}

int selectCommonTeacher(volunteerOrder *list, int i, int j, int commonTeacher[]){   //找選到共同的老師
    char teacherName=' ';
    int have=0;
    resetCommonTeacher(commonTeacher, list->studentN);  //重置共同老師的紀錄
    commonTeacher[i] = 1;                               //目前的位置先記錄為1
    teacherName = list->studentOrder[j][i];             //紀錄老師的名字
    j = j + 1;                                          //移到下一位學生的位置
    while(j < list->studentN){                          //直到全部學生的志願都檢查過
        if(list->studentOrder[j][i] == teacherName){    //如果找到有選到一樣的老師
            commonTeacher[j] = 1;                       //學生位置標記為1
            have = 1;                                   //紀錄為有共同老師
        }
        j = j + 1;
    }
    return have;
}
//----/commonTeacher-----

//-----setAns-----
void cleanStudentTeacher(volunteerOrder *list, char studentName, char teacherName, int n){  //志願序上，清除以選到的學生與老師
    int i=0, j=0;
    for(j=0; j < n; j++){
        for(i=0; i < n; i++){
            if(list->studentOrder[j][i] == teacherName){    //如果學生清單上的老師已經選到
                list->studentOrder[j][i] = '-';                 //清除(用 '-' 代替)
            }                                               //
            if(list->teacherOrder[j][i] == studentName){    //如果老師清單上的學生已經被選到
                list->teacherOrder[j][i] = '-';                 //清除(用 '-' 代替)
            }                                               //
        }
    }
}

void findTeacher(volunteerOrder *list, int i, int j, char listOfResults[][2]){  //將學生分配給老師
    listOfResults[j][0] = list->studentName[j];                                             //記錄學生
    listOfResults[j][1] = list->studentOrder[j][i];                                         //紀錄老師
    cleanStudentTeacher(list, listOfResults[j][0], listOfResults[j][1], list->studentN);    //將記錄過的老師從清單去除
}
//----/setAns-----

void teacherSelect(volunteerOrder *list, char teacherName, char commonTeacher[], char listOfResults[][2]){ //老師選擇
}

void studentSelect(volunteerOrder *list, int j, char listOfResults[][2]){    //學生選擇
    int commonTeacher[10]={0};      //紀錄存到相同老師的學生
    int i=0;                        //j=目前的學生
    for(j=0; j < list->studentN; j++){                      //找全部的學生-----------------------------------
        if(list->studentOrder[j][i] != '-'){                    //如果這個老師還沒被選到-----------------   |
            if(selectCommonTeacher(list, i, j, commonTeacher)){     //找看看有沒有共同的老師---------   |   |
//                teacherSelect(list, commonTeacher, listOfResults);      //有共同老師，看老師選擇序  |   |   |
            }                                                       //-------------------------------   |   |
            else{                                                   //沒共同老師---------------------   |   |
                findTeacher(list, i, j, listOfResults);                 //將學生配給老師            |   |   |
            }                                                       //-------------------------------   |   |
        }                                                       //---------------------------------------   |
    }                                                       //-----------------------------------------------
}

void volunteerSelect(volunteerOrder *list, char listOfResults[][2]){    //搜尋志願序
    int j=0;
    for(j=0; j < list->teacherM; j++){          //找全部志願序----
        studentSelect(list, j, listOfResults);      //學生選擇   |
    }                                           //----------------
}
//------/volunteer-------

//----------output----------
void output(char ans[][2], int n){
    int i=0;
    for(i=0; i < n; i++){
        printf("%c->%c\n", ans[i][0], ans[i][1]);
    }
}
//---------/output----------

void run(volunteerOrder list){
    char listOfResults[10][2]={{""}};       //存答案結果 [0]=學生，[1]=老師
    volunteerSelect(&list, listOfResults);  //依照志願序搜尋
    output(listOfResults, list.studentN);   //輸出答案
}
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
