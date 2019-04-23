#include <stdio.h>
#include <stdlib.h>
//017 �M�D�Ѯv���@��
//2019/04/23 IBOTIAndy PM. 10:30
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

//-------volunteer-------
//-----commonTeacher-----
void resetCommonTeacher(int commonTeacher[], int n){    //���mcommonTeacher
    int i=0;
    for(i=0; i < n; i++){
        commonTeacher[i] = 0;
    }
}

int selectCommonTeacher(volunteerOrder *list, int i, int j, int commonTeacher[]){   //����@�P���Ѯv
    char teacherName=' ';
    int have=0;
    resetCommonTeacher(commonTeacher, list->studentN);  //���m�@�P�Ѯv������
    commonTeacher[i] = 1;                               //�ثe����m���O����1
    teacherName = list->studentOrder[j][i];             //�����Ѯv���W�r
    j = j + 1;                                          //����U�@��ǥͪ���m
    while(j < list->studentN){                          //��������ǥͪ����@���ˬd�L
        if(list->studentOrder[j][i] == teacherName){    //�p�G��즳���@�˪��Ѯv
            commonTeacher[j] = 1;                       //�ǥͦ�m�аO��1
            have = 1;                                   //���������@�P�Ѯv
        }
        j = j + 1;
    }
    return have;
}
//----/commonTeacher-----

//-----setAns-----
void cleanStudentTeacher(volunteerOrder *list, char studentName, char teacherName, int n){  //���@�ǤW�A�M���H��쪺�ǥͻP�Ѯv
    int i=0, j=0;
    for(j=0; j < n; j++){
        for(i=0; i < n; i++){
            if(list->studentOrder[j][i] == teacherName){    //�p�G�ǥͲM��W���Ѯv�w�g���
                list->studentOrder[j][i] = '-';                 //�M��(�� '-' �N��)
            }                                               //
            if(list->teacherOrder[j][i] == studentName){    //�p�G�Ѯv�M��W���ǥͤw�g�Q���
                list->teacherOrder[j][i] = '-';                 //�M��(�� '-' �N��)
            }                                               //
        }
    }
}

void findTeacher(volunteerOrder *list, int i, int j, char listOfResults[][2]){  //�N�ǥͤ��t���Ѯv
    listOfResults[j][0] = list->studentName[j];                                             //�O���ǥ�
    listOfResults[j][1] = list->studentOrder[j][i];                                         //�����Ѯv
    cleanStudentTeacher(list, listOfResults[j][0], listOfResults[j][1], list->studentN);    //�N�O���L���Ѯv�q�M��h��
}
//----/setAns-----

void teacherSelect(volunteerOrder *list, char teacherName, char commonTeacher[], char listOfResults[][2]){ //�Ѯv���
}

void studentSelect(volunteerOrder *list, int j, char listOfResults[][2]){    //�ǥͿ��
    int commonTeacher[10]={0};      //�����s��ۦP�Ѯv���ǥ�
    int i=0;                        //j=�ثe���ǥ�
    for(j=0; j < list->studentN; j++){                      //��������ǥ�-----------------------------------
        if(list->studentOrder[j][i] != '-'){                    //�p�G�o�ӦѮv�٨S�Q���-----------------   |
            if(selectCommonTeacher(list, i, j, commonTeacher)){     //��ݬݦ��S���@�P���Ѯv---------   |   |
//                teacherSelect(list, commonTeacher, listOfResults);      //���@�P�Ѯv�A�ݦѮv��ܧ�  |   |   |
            }                                                       //-------------------------------   |   |
            else{                                                   //�S�@�P�Ѯv---------------------   |   |
                findTeacher(list, i, j, listOfResults);                 //�N�ǥͰt���Ѯv            |   |   |
            }                                                       //-------------------------------   |   |
        }                                                       //---------------------------------------   |
    }                                                       //-----------------------------------------------
}

void volunteerSelect(volunteerOrder *list, char listOfResults[][2]){    //�j�M���@��
    int j=0;
    for(j=0; j < list->teacherM; j++){          //��������@��----
        studentSelect(list, j, listOfResults);      //�ǥͿ��   |
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
    char listOfResults[10][2]={{""}};       //�s���׵��G [0]=�ǥ͡A[1]=�Ѯv
    volunteerSelect(&list, listOfResults);  //�̷ӧ��@�Ƿj�M
    output(listOfResults, list.studentN);   //��X����
}
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
