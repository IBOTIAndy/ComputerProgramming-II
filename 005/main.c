#include <stdio.h>
#include <string.h>
//005 �d�߾ǥ;Ǵ����Z��
//2019/03/11_PM.11:27
typedef struct{     //�ҵ{���c
    char name[20];  //�ҵ{�W��
    int credit;     //�ҵ{�Ǥ�
    int grade;      //�ҵ{���Z
}course;

typedef struct{         //�ǥ͵��c
    int ID;             //�ǥ;Ǹ�
    char name[10];      //�ǥͩm�W
    int course;         //�ǥͭ׽Ҽƶq
    course courses[10]; //�ǥͭ׽ҽҵ{
    int creditsum;      //�ǥ;Ǥ��[�`
    int creditsafe;     //�ǥ͹�o�Ǥ�
    float gradeaverage; //�ǥ��`����
    int rank;           //�ǥͦW��
}student;

//-----input-----   //�ǥ͸�ƿ�J
course* inputCourses(){         //��J�ҵ{���
    course data={"", 0, 0};     //���إߤ@�ӪŪ��ҵ{
    course *courses=&data;      //�إ߽ҵ{���СA���V�Žҵ{
    scanf("%s", data.name);     //�]�w�ҵ{�W��
    scanf("%d", &data.credit);  //�]�w�ҵ{�Ǥ�
    scanf("%d", &data.grade);   //�]�w�ҵ{���Z
    return courses;             //�^�ǽҵ{���е��ǥͪ��ҵ{�}�C
}

void inputStudent(student *students){           //��J�ǥ͸��
    int i=0;
    scanf("%d", &students->ID);                 //�]�w�ǥ;Ǹ�
    scanf("%s", students->name);                //��J�ǥͩm�W
    scanf("%d", &students->course);             //��J�ǥͭ׽Ҽƶq
    for(i=0; i < students->course; i++){        //�����J�ҵ{�A�����F�׽ҽҵ{�ƶq
        students->courses[i] = *inputCourses(); //�����ҵ{����
    }
}

void input(student students[], int *n){ //��J���
    int i=0;
    scanf("%d", n);                     //��J�ǥͼƶq
    for(i=0; i < *n; i++){              //�����J�ǥ͸�ơA�����F�]�w���ǥͼƶq
        inputStudent(students + i);     //�a�J�ǥͫ��СA�H�x�s��J���ǥ͸��
    }
}
//----/input-----

//-----intputDataOutput-----    //�ˬd��J���L���~��
void inputDataOutputCourse(course *courses){    //��X�ǥͪ��Ҧ��ҵ{
    printf("    %s %d %d\n", courses->name, courses->credit, courses->grade);
}

void inputDataOutputStudent(student *students){         //��X�ǥ͸��
    int i=0;
    printf("�Ǹ�: %d\n", students->ID);                 //�ǥ;Ǹ�
    printf("�m�W: %s\n", students->name);               //�ǥͩm�W
    printf("�׽Ҽƶq: %d\n", students->course);         //�׽Ҽƶq
    printf("�׽ҦC��:\n");
    for(i=0; i < students->course; i++){                //�j�M�ǥͪ��Ҧ��ҵ{
        inputDataOutputCourse(&students->courses[i]);   //��X�ǥͪ��ҵ{
    }
    printf("��o�Ǥ�: %d\n", students->creditsafe);     //�ǥ͹�o�Ǥ�
    printf("�`����: %.2f\n", students->gradeaverage);   //�ǥ��`����
    printf("�ƦW: %d\n", students->rank);               //�ǥͦW��
    printf("\n");
}

void inputDataOutput(student students[], int n){        //��X�Ҧ��ǥ͸��
    int i=0;
    for(i=0; i < n; i++){                               //�j�M�Ҧ��ǥ�
        inputDataOutputStudent(&students[i]);           //��X�ǥ͸��
    }
}
//----/intputDataOutput-----

//-----output-----  //���G��X
void outputCourse(course courses){  //��X�ҵ{��T
    printf("%s %d %d\n", courses.name, courses.credit, courses.grade);
}

void output(student students[], int i){                     //��X��Ӿǥ͸��
    int j=0;
    printf("%d %s\n", students[i].ID, students[i].name);    //��X�ǥ;Ǹ��B�m�W
    for(j=0; j < students[i].course; j++){                  //��X�ǥͩҦ��ҵ{��T
        outputCourse(students[i].courses[j]);               //��X�ҵ{
    }
    printf("%d\n", students[i].creditsafe);                 //��X��o�Ǥ�
    printf("%.2f\n", students[i].gradeaverage);             //��X�`����
    printf("%d\n", students[i].rank);                       //��X�W��
}
//----/output-----

//-----main-----
//----gradeMath---- //�Ǥ��B���Z�B�W���p��
void creditSum(student *students){  //�Ǥ��B��o�Ǥ��[�`
    int i=0, n=0, credit=0;
    int ansSum=0, ansSafe=0;
    n = students->course;           //�̤j�Ȭ��ǥͽҵ{�ƶq
    for(i=0; i < n; i++){                       //�j�M�ǥͪ��Ҧ��ҵ{
        credit = students->courses[i].credit;   //�����Ǥ�
        if(students->courses[i].grade >= 60){   //�p�G�ӽҵ{����F60��
            ansSafe = ansSafe + credit;         //��o�Ǥ��[�`
        }
        ansSum = ansSum + credit;               //�Ҧ��Ǥ��[�`
    }
    students->creditsum = ansSum;   //�x�s�Ǥ��[�`
    students->creditsafe = ansSafe; //�x�s��o�Ǥ��[�`
}
void gradeAverage(student *students){   //�p���`����
    int i=0, n=0, credit=0, grade=0;
    float ans=0.0;
    n = students->course;               //�̤j�Ȭ��׽ҽҼ�
    for(i=0; i < n; i++){                       //�j�M�Ҧ��ҵ{
        credit = students->courses[i].credit;   //�O���Ǥ�
        grade = students->courses[i].grade;     //�������Z
        ans = ans + (credit * grade);           //�[�v���������ҵ{�� (�Ǥ� ���H ���Z) ��ۥ[
    }   //�`��������: ans = (course[0].(credit * grade) + course[1].(credit * grade) + ...) / creditSum;
    ans = ans / students->creditsum;        //���Z�[�v ���H �`�Ǥ�
    ans = (int)((ans * 100) + 0.5) / 100.0; //�|�ˤ��J���p�ƲĤG��
    students->gradeaverage = ans;           //���Z�g�J�ǥ͸��
}

//---ranking---
void reset(int first[], int n){ //���]��ܪ��ǥ�
    int i=0;                    //
    for(i=0; i < n; i++){       //
        first[i] = -1;          //�]��-1 �קK����Ĥ@��ǥ�
    }
}

void ranking(student students[], int n){    //�ƦW
    int i=0, j=0, k=0, first[10]={0};
    float firstGradesum=0.0;            //�̰����Z
    for(i=0; i < n; i++){   //�q�W��0~�W��n(�ǥͼƶq)
        reset(first, 10);   //���]�H��ܪ��ǥͦ�m
        firstGradesum = 0;  //�C�ӦW�������s�k�s�̰���
        for(j=0, k=0; j < n; j++){                              //�C�Ӿǥͳ��n�ˬd�`���Z���h��
            if(students[j].rank == 0){                          //�٨S���W�����ǥ͡A�W���|�O0
                if(students[j].gradeaverage == firstGradesum){  //�p�G���Z�ۦP
                    k = k + 1;                                  //
                    first[k] = j;                               //�O���ǥͪ���m(�ĴX��ǥ�)
                }
                else if(students[j].gradeaverage > firstGradesum){  //�p�G�s���Z�j��̤j���Z
                    k = 0;                                          //������m�k�s
                    reset(first, 10);                               //���]�H��ܪ��ǥͦ�m
                    firstGradesum = students[j].gradeaverage;       //�̰������
                    first[k] = j;                                   //�O���ǥͪ���m(�ĴX��ǥ�)
                }
            }
        }
        for(k=0; k < n; k++){                       //�N�P�ˤ��ƪ��ǥͳ]�w���P�˪��W��
            if(first[k] != -1){                     //�p�G�O�P�˦W�����ǥ�
                students[first[k]].rank = i + 1;    //�]�w�W��
            }
        }
    }
}
//--/ranking---

void gradeMath(student students[], int n){  //�ǥͦ��Z�p��
    int i=0;
    for(i=0; i < n; i++){               //�j�M�Ҧ��ǥ�
        creditSum(&(students[i]));      //�p��ǥͪ��Ǥ�
        gradeAverage(&(students[i]));   //�p��ǥ��`����
    }
    ranking(students, n);               //�p��ǥͪ��ƦW
}
//---/gradeMath----

//----inputLoop---- //���ƿ�J�P�d��
int selectID(student students[], int inID, int *i, int n){  //�M��ǥ�
    *i = 0;     //�C���j�M�e�k�s
    while(*i < n){                      //�j�M�Ҧ��ǥͪ�������ǥͳ���L
        if(students[*i].ID == inID){    //�p�G�ǥͪ��Ǹ� �O��J���Ǹ�
            return 1;                   //�^�ǵ�if(1)�A��@True
        }
        *i = *i + 1;                    //��U�@��ǥ�
    }
    return 0;                           //�S���P��J�ۦP���ǥ͡A�^��if(0)�A��@False
}

void run(student students[], int n){        //����'
    int in=0, i=0;
    gradeMath(students, n);                 //����ǥ͸�ƹB��
    scanf("%d", &in);                       //�Ĥ@����JID(�Ǹ�)
    while(in != 0){                         //�p�G��J���O0(����)�A�������
        if(selectID(students, in, &i, n)){  //�p�G���������ǥ�
            output(students, i);            //��X�ǥͦ��Z��
        }
        else{                               //�p�G�S�����ǥ�
            printf("ERROR\n");              //��XERROR
        }
        scanf("%d", &in);                   //�A����JID(�Ǹ�)
    }
}
//---/inputLoop----
//----/main-----

int main(){
    int n;  //�x�s�ǥ��`��
    student students[10]={{0, "", 0, {}, 0, 0, 0}}; //�w�q�ǥͰ}�C�õ�����l��
    input(students, &n);            //��J�����ǥͪ���T
    //inputDataOutput(students, 3);   //�ˬd��: ��X�ǥ͸�ơA�T�{�����`�g�J
    run(students, n);               //���楻���\��A���ư���
    //inputDataOutput(students, 3);   //�ˬd��: ��X�ǥ͸��(�h�[��o�Ǥ��B�`�����B�ƦW)
//    printf("Hello world!\n");
    return 0;
}
