#include <stdio.h>

//005 �d�߾ǥ;Ǵ����Z��
//2019/03/09_PM.06:26
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

void input(student students[]){
    int i=0, n=0;
    scanf("%d", &n);
    for(i=0; i < n; i++){
        inputStudent(students + i);
    }
}
//----/input-----

//-----output-----
void inputDataOutputCourse(course *courses){
    printf("    %s %d %d\n", courses->name, courses->credit, courses->grade);
}

void inputDataOutputStudent(student *students){
    int i=0;
    printf("�Ǹ�: %d\n", students->ID);
    printf("�m�W: %s\n", students->name);
    printf("�׽Ҽƶq: %d\n", students->course);
    printf("�׽ҦC��:\n");
    for(i=0; i < students->course; i++){
        inputDataOutputCourse(&students->courses[i]);
    }
    printf("\n");
}

void inputDataOutput(student students[], int n){
    int i=0;
    for(i=0; i < n; i++){
        inputDataOutputStudent(&students[i]);
    }
}
//----/output-----

//-----test-----

//----/test-----

int main(){
    student students[10];
    input(students);
    inputDataOutput(students, 3);
    //run();
//    printf("Hello world!\n");
    return 0;
}
