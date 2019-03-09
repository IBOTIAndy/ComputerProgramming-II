#include <stdio.h>

//005 查詢學生學期成績單
//2019/03/09_PM.08:39
typedef struct{
    char name[20];
    int credit;
    int grade;
}course;

typedef struct{
    int ID;
    char name[10];
    int course;
    course courses[10];
    int creditsum;
    float gradeaverage;
    int rank;
}student;

//-----input-----
course* inputCourses(){
    course data={"", 0, 0};
    course *courses=&data;
    scanf("%s", data.name);
    scanf("%d", &data.credit);
    scanf("%d", &data.grade);
    return courses;
}

void inputStudent(student *students){
    int i=0;
    scanf("%d", &students->ID);
    scanf("%s", students->name);
    scanf("%d", &students->course);
    for(i=0; i < students->course; i++){
        students->courses[i] = *inputCourses();
    }
}

void input(student students[], int *n){
    int i=0;
    scanf("%d", n);
    for(i=0; i < *n; i++){
        inputStudent(students + i);
    }
}
//----/input-----

//-----intputDataOutput-----
void inputDataOutputCourse(course *courses){
    printf("    %s %d %d\n", courses->name, courses->credit, courses->grade);
}

void inputDataOutputStudent(student *students){
    int i=0;
    printf("學號: %d\n", students->ID);
    printf("姓名: %s\n", students->name);
    printf("修課數量: %d\n", students->course);
    printf("修課列表:\n");
    for(i=0; i < students->course; i++){
        inputDataOutputCourse(&students->courses[i]);
    }
    printf("總學分: %d\n", students->creditsum);
    printf("總分: %.2f\n", students->gradeaverage);
    printf("排名: %d\n", students->rank);
    printf("\n");
}

void inputDataOutput(student students[], int n){
    int i=0;
    for(i=0; i < n; i++){
        inputDataOutputStudent(&students[i]);
    }
}
//----/intputDataOutput-----

//-----output-----
void output(student students[], int i){
    i = i + 1;
}
//----/output-----

//-----main-----
void creditSum(student *students){
    int i=0, n=0, ans=0;
    n = students->course;
    for(i=0; i < n; i++){
        ans = ans + students->courses[i].credit;
    }
    students->creditsum = ans;
}
void gradeAverage(student *students){
    int i=0, n=0;
    float ans=0.0;
    n = students->course;
    for(i=0; i < n; i++){
        ans = ans + (students->courses[i].credit * students->courses[i].grade);
    }
    ans = ans / students->creditsum;
    students->gradeaverage = ans;
}

void ranking(student students[], int n){
    int i=0, j=0, first=0;
    float firstGradesum=0.0;
    for(i=0; i < n; i++){
        first = 0;
        firstGradesum = 0;
        for(j=0; j < n; j++){
            if(students[j].rank == 0){
                if(students[j].gradeaverage >= firstGradesum){
                    firstGradesum = students[j].gradeaverage;
                    first = j;
                }
            }
        }
        students[first].rank = i + 1;
    }
}

void gradeMath(student students[], int n){
    int i=0;
    for(i=0; i < n; i++){
        creditSum(&(students[i]));
        gradeAverage(&(students[i]));
    }
    ranking(students, n);
}

int selectID(student students[], int inID, int *i, int n){
    *i = 0;
    while(*i < n){
        if(students[*i].ID == inID){
            return 1;
        }
        *i = *i + 1;
    }
    return 0;
}

void run(student students[], int n){
    int in=0, i=0;
    scanf("%d", &in);
    gradeMath(students, n);
    while(in != 0){
        if(selectID(students, in, &i, n)){
            output(students, i);
        }
        else{
            printf("error\n");
        }
        scanf("%d", &in);
    }
}
//----/main-----

//-----test-----

//----/test-----

int main(){
    int n;
    student students[10]={{0, "", 0, {}, 0, 0, 0}};
    input(students, &n);
    //inputDataOutput(students, 3);
    run(students, n);
    //inputDataOutput(students, 3);
//    printf("Hello world!\n");
    return 0;
}
