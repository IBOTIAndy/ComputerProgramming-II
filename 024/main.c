#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//024 ���� Linux Command-Line Interface
//2019/05/18 PM. 11:44 IBOTIAndy
//----------typedef----------
typedef struct file_s{  //�ɮ�
    char name[20];      //�ɮצW��
    char data[200];     //�ɮ׸��
}file_t;

typedef struct fileList_s{  //�ɮצC��
    file_t file[20];        //�ɮ�
    int n;                  //�ثe�ɮ׼ƶq
}fileList_t;

typedef struct parameterList_s{ //�Ѽư}�C
    char *parameter[20];        //�Ѽ�
    int n;                      //�ѼƼƶq
}parameterList_t;

typedef struct commandLine_s{       //���O
    char *command;                  //�ϥΪ����O
    parameterList_t parameterList;  //�Ѽ�s
}commandLine_t;

enum type{not, touch, vim, cat, head, tail};
//---------/typedef----------

//----------run--------------
//-------inputSet--------
void stringCut(char in[], commandLine_t *list){  //�r�����
    //�r�����
    //���X���O�A�Ѽ�
}

int selectType(char *command){return not;}
//------/inputSet--------

//-------operation-------
void create(fileList_t fileList, parameterList_t parameterList){}

void write(fileList_t fileList, parameterList_t parameterList){}

void read(fileList_t fileList, parameterList_t parameterList){}

void readHead(fileList_t fileList, parameterList_t parameterList){}

void readTail(fileList_t fileList, parameterList_t parameterList){}
//------/operation-------

void run(){
    fileList_t fileList={{{"", ""}}, 0};
    char in[50]="";
    enum type select=not;
    commandLine_t commandLine;
    gets(in);                                   //��J
    stringCut(in, &commandLine);                //���ο�J
    select = selectType(commandLine.command);   //��ܭn�ϥΪ����O
    if(select == touch){        //�إ��ɮ�
        create(fileList, commandLine.parameterList);
    }
    else if(select == vim){     //�ɮ׮Ѽg
        write(fileList, commandLine.parameterList);
    }
    else if(select == cat){     //�d���ɮ�
        read(fileList, commandLine.parameterList);
    }
    else if(select == head){    //�d���ɮ� �q�e���}�l
        readHead(fileList, commandLine.parameterList);
    }
    else if(select == tail){    //�t���ɮ� �q�᭱�}�l
        readTail(fileList, commandLine.parameterList);
    }
}
//---------/run--------------

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
