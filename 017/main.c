#include <stdio.h>
#include <stdlib.h>
//017 �M�D�Ѯv���@��
//2019/04/19 IBOTIAndy AM. 01:10
typedef struct{                 //���@�M��
    char studentName[10];       //�ǥͦW��
    char studentOrder[10][10];  //�ǥͧ��@��
    int studentN;               //�ǥͼƶq
    char teacherName[10];       //�Ѯv�W��
    char teacherOrder[10][10];  //�Ѯv���@��
    int teacherM;               //�Ѯv�ƶq
}volunteerOrder;
//----------input----------
void setlist(volunteerOrder *list){ //�]�w�򥻸�T
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

void input(volunteerOrder *list){   //��J
    char inputString[30]="";        //��J���Ȧs�}�C
    int i=0, j=0, n=4;
    setlist(list);                  //�]�w�򥻸�T
    for(i=0; i < n; i++){                           //��J�ǥͧ��@��
        gets(inputString);                          //���o���
        list->studentOrder[i][0] = inputString[0];  //��J�ǥͲĤ@�ӧ��@
        list->studentOrder[i][1] = inputString[2];  //��J�ǥͲĤG�ӧ��@
        list->studentOrder[i][2] = inputString[4];  //��J�ǥͲĤT�ӧ��@
        list->studentOrder[i][3] = inputString[6];  //��J�ǥͲĥ|�ӧ��@
    }
    for(j=0; j < n; j++){                           //��J�Ѯv���@��
        gets(inputString);                          //���o���
        list->teacherOrder[j][0] = inputString[0];  //��J�Ѯv�Ĥ@�ӧ��@
        list->teacherOrder[j][1] = inputString[2];  //��J�Ѯv�ĤG�ӧ��@
        list->teacherOrder[j][2] = inputString[4];  //��J�Ѯv�ĤT�ӧ��@
        list->teacherOrder[j][3] = inputString[6];  //��J�Ѯv�ĥ|�ӧ��@
    }
}
//---------/input----------

//-----------run-----------
void teacherSelect(){}

void studentSelect(){}

void run(volunteerOrder list){}
//----------/run-----------

//----------test-----------
void inputView(volunteerOrder list){                //��J�T�{
    int i=0, j=0;
    printf("studentN = %d\n", list.studentN);       //��X�ǥͼƶq
    printf("teacherM = %d\n", list.teacherM);       //��X�Ѯv�ƶq
    for(i=0; i < list.studentN; i++){               //��������ǥͳ���X��
        printf("%c: ", list.studentName[i]);            //��X�ǥͦW�r
        for(j=0; j < list.teacherM; j++){               //�����Ӿǥͧ��@�ǿ�X��
            printf("%c", list.studentOrder[i][j]);          //��X�ǥͿ�ܪ��� j ��Ѯv
            if(j + 1 != list.teacherM){                     //�p�G�٨S��̫�
                printf(", ");                               //��X�r�� (�A) ���j
            }
        }                                               //�䤤�@�Ӿǥͪ����@�ǿ�X����
        printf("\n");                                   //����
    }
    printf("\n");                                   //�����ǥͿ�X���A�����Ŧ�P�Ѯv���}
    for(i=0; i < list.teacherM; i++){               //��������Ѯv����X��
        printf("%c: ", list.teacherName[i]);            //��X�Ѯv�W�r
        for(j=0; j < list.studentN; j++){               //�����ӦѮv���@�ǿ�X��
            printf("%c", list.teacherOrder[i][j]);          //��X�Ѯv��ܪ��� j ��ǥ�
            if(j + 1 != list.studentN){                     //�p�G�٨S��̫�
                printf(", ");                               //��X�r�� (�A) ���j
            }
        }                                               //�䤤�@�ӦѮv�����@�ǿ�X����
        printf("\n");                                   //����
    }
}
//---------/test-----------

int main(){
    volunteerOrder list={" ", {""}, 0, " ", {""}, 0};   //
    input(&list);                                       //��J
//    inputView(list);                                    //���տ�J�������T
    run(list);                                          //����
    //printf("Hello world!\n");
    return 0;
}
