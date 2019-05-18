#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//024 ���� Linux Command-Line Interface
//2019/05/19 AM. 03:12 IBOTIAndy
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

enum type{not_e, touch_e, vim_e, cat_e, head_e, tail_e, exit_e};
//---------/typedef----------

//----------run--------------
//-------inputSet--------
void parameterCut(parameterList_t *parameterList){  //���ΰѼ�
    int i=0;
    parameterList->parameter[i] = strtok(NULL, " ");        //�����@��
    while(parameterList->parameter[i] != NULL){             //��������F��
        i = i + 1;
        parameterList->parameter[i] = strtok(NULL, " ");    //�~�����
    }                       //�]���������ɭ� i �|�b�Ū����Ӧ�l �ҥH:
    parameterList->n = i;   //�ѼƼƶq�� i
}

void stringCut(char in[], commandLine_t *list){  //�r�����
    list->command = strtok(in, " ");        //�Ĥ@�����ΡA�����O
    parameterCut(&(list->parameterList));   //���ΰѼ�
}

int selectType(char *command){  //��ܭn�ϥΪ����O
    //�]���ϥΦC�| �ҥH�����^�Ǩ����ܼ� (27��)
    if(!strcmp(command, "touch")){      //�إ��ɮ�
        return touch_e;
    }
    else if(!strcmp(command, "vim")){   //�ɮ׮Ѽg
        return vim_e;
    }
    else if(!strcmp(command, "cat")){   //�d���ɮ�
        return cat_e;
    }
    else if(!strcmp(command, "head")){  //�d���ɮ� �q�e���}�l
        return head_e;
    }
    else if(!strcmp(command, "tail")){  //�t���ɮ� �q�᭱�}�l
        return tail_e;
    }
    else if(!strcmp(command, "exit")){  //���}
        return exit_e;
    }
    return not_e;
}
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
    enum type select=not_e;
    commandLine_t commandLine;
    while(1){
        gets(in);                                   //��J
        stringCut(in, &commandLine);                //���ο�J
        select = selectType(commandLine.command);   //��ܭn�ϥΪ����O
        if(select == touch_e){      //�إ��ɮ�
            create(fileList, commandLine.parameterList);
        }
        else if(select == vim_e){   //�ɮ׮Ѽg
            write(fileList, commandLine.parameterList);
        }
        else if(select == cat_e){   //�d���ɮ�
            read(fileList, commandLine.parameterList);
        }
        else if(select == head_e){  //�d���ɮ� �q�e���}�l
            readHead(fileList, commandLine.parameterList);
        }
        else if(select == tail_e){  //�t���ɮ� �q�᭱�}�l
            readTail(fileList, commandLine.parameterList);
        }
        else if(select == exit_e){  //����
            break;
        }
    }
}
//---------/run--------------

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
