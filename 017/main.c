#include <stdio.h>
#include <stdlib.h>
//017 �M�D�Ѯv���@��
//2019/04/19 IBOTIAndy AM. 12:06
typedef struct{                 //���@�M��
    char studentName[10];       //�ǥͦW��
    char studentOrder[10][10];  //�ǥͧ��@��
    int studentN;               //�ǥͼƶq
    char teacherName[10];       //�Ѯv�W��
    char teacherOrder[10][10];  //�Ѯv���@��
    int teacherM;               //�Ѯv�ƶq
}volunteerOrder;
//----------input----------
void input(volunteerOrder *list){}
//---------/input----------

//-----------run-----------
void teacherSelect(){}

void studentSelect(){}

void run(volunteerOrder list){}
//----------/run-----------

int main(){
    volunteerOrder list;        //
    input(&list);               //��J
    run(list);                  //����
//    printf("Hello world!\n");
    return 0;
}
