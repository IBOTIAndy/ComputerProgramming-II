#include <stdio.h>
#include <string.h>
//004 計算總成績、平均、排名
//2019/03/05 IBOTIAndy
typedef struct{
    int ID;
    char name[10];
    int grade1;
    int grade2;
    int grade3;
    int gradesum;
    int rank;
}student;

//-----input-----
void input(student students[], int *n){
    int i=0;
    scanf("%d", n);
    for(i=0; i < *n; i++){
        scanf("%d", &students[i].ID);
        scanf("%s", students[i].name);
        scanf("%d", &students[i].grade1);
        scanf("%d", &students[i].grade2);
        scanf("%d", &students[i].grade3);
    }
}
//----/input-----

//-----output-----
void outputLeaderboard(student students[], int n){
    int rank=0, j=0;
    for(rank=1; rank <= n; rank++){
        for(j=0; j < n; j++){
            if(students[j].rank == rank){
                printf("%d ", students[j].ID);
                printf("%s ", students[j].name);
                printf("%d ", students[j].grade1);
                printf("%d ", students[j].grade2);
                printf("%d ", students[j].grade3);
                printf("%d ", students[j].gradesum);
                printf("%d ", students[j].rank);
                printf("\n");
                j = n;
            }
        }
    }
}
//-----
void outputFloatGrade(float ans){
    ans = (int)((ans * 100) + 0.5) / 100.0;
    printf("%.2f\n", ans);
}
//----/output-----

//-----gradeMath-----
void everyoneGradesum(student students[], int n){
    int i=0;
    for(i=0; i < n; i++){
        students[i].gradesum = students[i].grade1 + students[i].grade2 + students[i].grade3;
    }
}
void ranking(student students[], int n){
    int i=0, j=0, first=0, firstGradesum=0;
    for(i=0; i < n; i++){
        first = 0;
        firstGradesum = 0;
        for(j=0; j < n; j++){
            if(students[j].rank == 0){
                if(students[j].gradesum >= firstGradesum){
                    firstGradesum = students[j].gradesum;
                    first = j;
                }
            }
        }
        students[first].rank = i + 1;
    }
}
//-----
float gradesAverage(student students[], int n){
    int i=0;
    float grade1ans=0, grade2ans=0, grade3ans=0, gradesumans=0;
    for(i=0; i < n; i++){
        grade1ans = grade1ans + students[i].grade1;
        grade2ans = grade2ans + students[i].grade2;
        grade3ans = grade3ans + students[i].grade3;
        gradesumans = gradesumans + students[i].gradesum;
    }
    grade1ans = grade1ans / n;
    grade2ans = grade2ans / n;
    grade3ans = grade3ans / n;
    gradesumans = gradesumans / n;
    outputFloatGrade(grade1ans);
    outputFloatGrade(grade2ans);
    outputFloatGrade(grade3ans);
    outputFloatGrade(gradesumans);
    return gradesumans;
}
//-----
int gradesumMedian(student students[], int n){
    int Median=0;
    float ans=0;
    int i=0;
    Median = n / 2 + 1;
    if(n % 2 == 0){
        for(i=0; i < n; i++){
            if(students[i].rank == Median - 1 || students[i].rank == Median){
                ans = ans + students[i].gradesum;
            }
        }
    }
    else{
        for(i=0; i < n; i++){
            if(students[i].rank == Median){
                ans = students[i].gradesum;
            }
        }
    }
    return ans;
}
//-----
//void gradesumSD(student students[], int n){
//
//}
//void gradesumVariance(student students[], int n){
//
//}

void gradeMath(student students[], int n){
    float gradesum=0;
    everyoneGradesum(students, n);                      //計算每個人的總成績
    ranking(students, n);                               //計算名次
    outputLeaderboard(students, n);                     //依照排名輸出
    gradesum = gradesAverage(students, n);              //計算每個成績的平均
    outputFloatGrade(gradesumMedian(students, n));      //Median 中位數
    //outputFloatGrade(gradesumVariance(students, n));    //Variance 變異數
    //outputFloatGrade(gradesumSD(students, n));          //SD = Standard Deviation 標準差
}
//----/gradeMath-----

//-----test-----
void testInput(student students[], int *n){
    *n=5;
    students[0].ID = 107598032; students[0].grade1 = 90;    students[0].grade2 = 90;    students[0].grade3 = 90;
    students[1].ID = 107598029; students[1].grade1 = 100;   students[1].grade2 = 100;   students[1].grade3 = 100;
    students[2].ID = 107598044; students[2].grade1 = 65;    students[2].grade2 = 77;    students[2].grade3 = 42;
    students[3].ID = 107598038; students[3].grade1 = 38;    students[3].grade2 = 44;    students[3].grade3 = 15;
    students[4].ID = 107598045; students[4].grade1 = 99;    students[4].grade2 = 99;    students[4].grade3 = 99;
    strcpy(students[0].name, "杜豐腴");
    strcpy(students[1].name, "鞏粒方");
    strcpy(students[2].name, "河老師");
    strcpy(students[3].name, "杜鎂鋅");
    strcpy(students[4].name, "小熊維尼");
}
void inputDataOutput(student students[], int n){
    int i=0;
    for(i=0; i < n; i++){
        printf("%d %s %d %d %d %d\n", students[i].ID, students[i].name, students[i].grade1, students[i].grade2, students[i].grade3, students[i].gradesum);
    }
}
//----/test-----
int main(){
    int n=0;
    student students[100]={{0, "", 0, 0, 0, 0, 0}};
    //input(students, &n);
    testInput(students, &n);
    inputDataOutput(students, n);
    gradeMath(students, n);
//    printf("Hello world!\n");
    return 0;
}
