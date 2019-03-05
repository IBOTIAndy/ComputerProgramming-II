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
//----/output-----

//-----gradeMath-----
void everybodyGradesum(student students[], int n){
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

void gradeMath(student students[], int n){
    everybodyGradesum(students, n);
    ranking(students, n);
    outputLeaderboard(students, n);
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
