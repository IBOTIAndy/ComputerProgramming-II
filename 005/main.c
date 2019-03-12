#include <stdio.h>
#include <string.h>
//005 查詢學生學期成績單
//2019/03/11_PM.11:27
typedef struct{     //課程結構
    char name[20];  //課程名稱
    int credit;     //課程學分
    int grade;      //課程成績
}course;

typedef struct{         //學生結構
    int ID;             //學生學號
    char name[10];      //學生姓名
    int course;         //學生修課數量
    course courses[10]; //學生修課課程
    int creditsum;      //學生學分加總
    int creditsafe;     //學生實得學分
    float gradeaverage; //學生總平均
    int rank;           //學生名次
}student;

//-----input-----   //學生資料輸入
course* inputCourses(){         //輸入課程資料
    course data={"", 0, 0};     //先建立一個空的課程
    course *courses=&data;      //建立課程指標，指向空課程
    scanf("%s", data.name);     //設定課程名稱
    scanf("%d", &data.credit);  //設定課程學分
    scanf("%d", &data.grade);   //設定課程成績
    return courses;             //回傳課程指標給學生的課程陣列
}

void inputStudent(student *students){           //輸入學生資料
    int i=0;
    scanf("%d", &students->ID);                 //設定學生學號
    scanf("%s", students->name);                //輸入學生姓名
    scanf("%d", &students->course);             //輸入學生修課數量
    for(i=0; i < students->course; i++){        //持續輸入課程，直到到達修課課程數量
        students->courses[i] = *inputCourses(); //接收課程指標
    }
}

void input(student students[], int *n){ //輸入資料
    int i=0;
    scanf("%d", n);                     //輸入學生數量
    for(i=0; i < *n; i++){              //持續輸入學生資料，直到到達設定的學生數量
        inputStudent(students + i);     //帶入學生指標，以儲存輸入的學生資料
    }
}
//----/input-----

//-----intputDataOutput-----    //檢查輸入有無錯誤用
void inputDataOutputCourse(course *courses){    //輸出學生的所有課程
    printf("    %s %d %d\n", courses->name, courses->credit, courses->grade);
}

void inputDataOutputStudent(student *students){         //輸出學生資料
    int i=0;
    printf("學號: %d\n", students->ID);                 //學生學號
    printf("姓名: %s\n", students->name);               //學生姓名
    printf("修課數量: %d\n", students->course);         //修課數量
    printf("修課列表:\n");
    for(i=0; i < students->course; i++){                //搜尋學生的所有課程
        inputDataOutputCourse(&students->courses[i]);   //輸出學生的課程
    }
    printf("實得學分: %d\n", students->creditsafe);     //學生實得學分
    printf("總平均: %.2f\n", students->gradeaverage);   //學生總平均
    printf("排名: %d\n", students->rank);               //學生名次
    printf("\n");
}

void inputDataOutput(student students[], int n){        //輸出所有學生資料
    int i=0;
    for(i=0; i < n; i++){                               //搜尋所有學生
        inputDataOutputStudent(&students[i]);           //輸出學生資料
    }
}
//----/intputDataOutput-----

//-----output-----  //結果輸出
void outputCourse(course courses){  //輸出課程資訊
    printf("%s %d %d\n", courses.name, courses.credit, courses.grade);
}

void output(student students[], int i){                     //輸出單個學生資料
    int j=0;
    printf("%d %s\n", students[i].ID, students[i].name);    //輸出學生學號、姓名
    for(j=0; j < students[i].course; j++){                  //輸出學生所有課程資訊
        outputCourse(students[i].courses[j]);               //輸出課程
    }
    printf("%d\n", students[i].creditsafe);                 //輸出實得學分
    printf("%.2f\n", students[i].gradeaverage);             //輸出總平均
    printf("%d\n", students[i].rank);                       //輸出名次
}
//----/output-----

//-----main-----
//----gradeMath---- //學分、成績、名次計算
void creditSum(student *students){  //學分、實得學分加總
    int i=0, n=0, credit=0;
    int ansSum=0, ansSafe=0;
    n = students->course;           //最大值為學生課程數量
    for(i=0; i < n; i++){                       //搜尋學生的所有課程
        credit = students->courses[i].credit;   //紀錄學分
        if(students->courses[i].grade >= 60){   //如果該課程有到達60分
            ansSafe = ansSafe + credit;         //實得學分加總
        }
        ansSum = ansSum + credit;               //所有學分加總
    }
    students->creditsum = ansSum;   //儲存學分加總
    students->creditsafe = ansSafe; //儲存實得學分加總
}
void gradeAverage(student *students){   //計算總平均
    int i=0, n=0, credit=0, grade=0;
    float ans=0.0;
    n = students->course;               //最大值為修課課數
    for(i=0; i < n; i++){                       //搜尋所有課程
        credit = students->courses[i].credit;   //記錄學分
        grade = students->courses[i].grade;     //紀錄成績
        ans = ans + (credit * grade);           //加權分為全部課程的 (學分 乘以 成績) 後相加
    }   //總平均公式: ans = (course[0].(credit * grade) + course[1].(credit * grade) + ...) / creditSum;
    ans = ans / students->creditsum;        //成績加權 除以 總學分
    ans = (int)((ans * 100) + 0.5) / 100.0; //四捨五入取小數第二位
    students->gradeaverage = ans;           //成績寫入學生資料
}

//---ranking---
void reset(int first[], int n){ //重設選擇的學生
    int i=0;                    //
    for(i=0; i < n; i++){       //
        first[i] = -1;          //設為-1 避免撞到第一位學生
    }
}

void ranking(student students[], int n){    //排名
    int i=0, j=0, k=0, first[10]={0};
    float firstGradesum=0.0;            //最高成績
    for(i=0; i < n; i++){   //從名次0~名次n(學生數量)
        reset(first, 10);   //重設以選擇的學生位置
        firstGradesum = 0;  //每個名次都重新歸零最高分
        for(j=0, k=0; j < n; j++){                              //每個學生都要檢查總成績為多少
            if(students[j].rank == 0){                          //還沒有名次的學生，名次會是0
                if(students[j].gradeaverage == firstGradesum){  //如果成績相同
                    k = k + 1;                                  //
                    first[k] = j;                               //記錄學生的位置(第幾位學生)
                }
                else if(students[j].gradeaverage > firstGradesum){  //如果新成績大於最大成績
                    k = 0;                                          //紀錄位置歸零
                    reset(first, 10);                               //重設以選擇的學生位置
                    firstGradesum = students[j].gradeaverage;       //最高分更改
                    first[k] = j;                                   //記錄學生的位置(第幾位學生)
                }
            }
        }
        for(k=0; k < n; k++){                       //將同樣分數的學生設定成同樣的名次
            if(first[k] != -1){                     //如果是同樣名次的學生
                students[first[k]].rank = i + 1;    //設定名次
            }
        }
    }
}
//--/ranking---

void gradeMath(student students[], int n){  //學生成績計算
    int i=0;
    for(i=0; i < n; i++){               //搜尋所有學生
        creditSum(&(students[i]));      //計算學生的學分
        gradeAverage(&(students[i]));   //計算學生總平均
    }
    ranking(students, n);               //計算學生的排名
}
//---/gradeMath----

//----inputLoop---- //重複輸入與查詢
int selectID(student students[], int inID, int *i, int n){  //尋找學生
    *i = 0;     //每次搜尋前歸零
    while(*i < n){                      //搜尋所有學生直到全部學生都找過
        if(students[*i].ID == inID){    //如果學生的學號 是輸入的學號
            return 1;                   //回傳給if(1)，當作True
        }
        *i = *i + 1;                    //找下一位學生
    }
    return 0;                           //沒有與輸入相同的學生，回傳if(0)，當作False
}

void run(student students[], int n){        //執行'
    int in=0, i=0;
    gradeMath(students, n);                 //執行學生資料運算
    scanf("%d", &in);                       //第一次輸入ID(學號)
    while(in != 0){                         //如果輸入不是0(結束)，持續執行
        if(selectID(students, in, &i, n)){  //如果找到對應的學生
            output(students, i);            //輸出學生成績單
        }
        else{                               //如果沒有找到學生
            printf("ERROR\n");              //輸出ERROR
        }
        scanf("%d", &in);                   //再次輸入ID(學號)
    }
}
//---/inputLoop----
//----/main-----

int main(){
    int n;  //儲存學生總數
    student students[10]={{0, "", 0, {}, 0, 0, 0}}; //定義學生陣列並給予初始值
    input(students, &n);            //輸入全部學生的資訊
    //inputDataOutput(students, 3);   //檢查用: 輸出學生資料，確認有正常寫入
    run(students, n);               //執行本次功能，重複執行
    //inputDataOutput(students, 3);   //檢查用: 輸出學生資料(多加實得學分、總平均、排名)
//    printf("Hello world!\n");
    return 0;
}
