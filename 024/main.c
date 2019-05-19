#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//024 ���� Linux Command-Line Interface
//2019/05/19 PM. 02:55 IBOTIAndy
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

enum type{not_e, touch_e, vim_e, cat_e, head_e, tail_e, rm_e, ls_e, exit_e};
//---------/typedef----------

//----------run--------------
//-------inputSet--------
//-----strtok-----
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
//----/strtok-----

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
    else if(!strcmp(command, "rm")){    //�����ɮ�
        return rm_e;
    }
    else if(!strcmp(command, "ls")){    //�C�X�����ɮ�
        return ls_e;
    }
    else if(!strcmp(command, "exit")){  //���}
        return exit_e;
    }
    return not_e;
}
//------/inputSet--------

//-------operation-------
//-----createFile-----
void createNewFile(file_t *file, char *fileName){   //�إ߷s���ɮ�
    strcpy(file->name, fileName);   //�N�ɦW�g�J�ɮ�
}

void create(fileList_t *fileList, parameterList_t parameterList){   //�إ��ɮסA�ݤ䴩�@���إߦh���ɮ�
    int i=0;
    for(i=0; i < parameterList.n; i++){                                                 //����Ҧ��ѼƳ��ϥΧ�
        createNewFile(&(fileList->file[fileList->n + i]), parameterList.parameter[i]);  //�إ߷s���ɮ� (�ɮצ�m, �Ѽ�)
    }
    fileList->n = fileList->n + parameterList.n;    //�ɮ��`�� = �ثe�ɮ׼� + �ѼƼƶq
}
//----/createFile-----

void write(fileList_t fileList, parameterList_t parameterList){}

void read(fileList_t fileList, parameterList_t parameterList){}

void readHead(fileList_t fileList, parameterList_t parameterList){}

void readTail(fileList_t fileList, parameterList_t parameterList){}

void removeFile(fileList_t *fileList, parameterList_t parameterList){}

void listFiles(fileList_t fileList){}
//------/operation-------

//-------view------------
void viewFileData(fileList_t fileList){
    int i=0;
    for(i=0; i < fileList.n; i++){
        printf("%d.%s\n", i + 1, fileList.file[i].name);
        printf("%s\n", fileList.file[i].data);
    }
    printf("\n");
}
//------/view------------

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
            create(&fileList, commandLine.parameterList);
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
        else if(select == rm_e){    //�����ɮ�
            removeFile(&fileList, commandLine.parameterList);
        }
        else if(select == ls_e){    //�C�X�ɮצC��
            listFiles(fileList);
        }
        else if(select == exit_e){  //����
            break;
        }
        viewFileData(fileList);     //�ˬd�ɮץΡA�ݸ�Ƽg�J�������T
    }
}
//---------/run--------------

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
