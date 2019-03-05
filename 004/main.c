#include <stdio.h>

//004 ­pºâ¦¨ÁZ
//2019/03/05 IBOTIAndy
typedef struct{
    int ID;
    char name[10];
    int grade1;
    int grade2;
    int grade3;
    int gradeadd;
}student;

void input(student students[], int *n){
    int i=0;
    scanf("%d", n);
    for(i=0; i < *n; i++){
        scanf("%d %s %d %d %d", &students[i].ID, students[i].name, &students[i].grade1, &students[i].grade2, &students[i].grade3);
    }
}
//-----test-----
void testInput(student students[], int *n){
    *n=5;
    students[0].ID = 107598032; students[0].grade1 = 90;    students[0].grade2 = 90;    students[0].grade3 = 90;
    students[1].ID = 107598029; students[1].grade1 = 100;   students[1].grade2 = 100;   students[1].grade3 = 100;
    students[2].ID = 107598044; students[2].grade1 = 65;    students[2].grade2 = 77;    students[2].grade3 = 42;
    students[3].ID = 107598038; students[3].grade1 = 38;    students[3].grade2 = 44;    students[3].grade3 = 15;
    students[4].ID = 107598045; students[4].grade1 = 99;    students[4].grade2 = 99;    students[4].grade3 = 99;
    strcpy(students[0].name, "§ùÂ×µÍ");
    strcpy(students[1].name, "¾d²É¤è");
    strcpy(students[2].name, "ªe¦Ñ®v");
    strcpy(students[3].name, "§ùÁâ¾N");
    strcpy(students[4].name, "¤pºµºû¥§");
}
void inputDataOutput(student students[], int n){
    int i=0;
    for(i=0; i < n; i++){
        printf("%d %s %d %d %d %d\n", students[i].ID, students[i].name, students[i].grade1, students[i].grade2, students[i].grade3, students[i].gradeadd);
    }
}

//----/test-----
int main()
{
    int n=0;
    student students[100]={{0, "", 0, 0, 0, 0}};
    input(students, &n);
    //testInput(students, &n);
    //inputDataOutput(students, n);
//    gradeMath(student, n);
//    printf("Hello world!\n");
    return 0;
}
