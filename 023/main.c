#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//023 ����Ū��
//2019/05/15 PM. 02:05 IBOTIAndy
//----------typedef----------
typedef struct file_s{
    char name[50];
    int list[100];
}file_t;
//---------/typedef----------

//----------write------------
int duplicateFileName(file_t file[], char name[]){
    int i=0;
    while(file[i].name[0] != '\0'){
        if(strcmp(file[i].name, name) == 0){
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

void writeFile(file_t file[], char name[], int list[]){ //�g�J�ɮ�
    int i=0, j=0;
    while(1){                           //���Ŧ�
        if(file[i].name[i] == '\0'){    //�p�G�O�Ū�
            strcpy(file[i].name, name); //�N�W�ټg�J
            break;                      //���X�j��
        }
        i = i + 1;
    }
    while(1){                       //�g�J���
        file[i].list[j] = list[j];  //�N�Ʀr�g�J
        if(list[j] == -1){          //�p�G�O�����Ÿ�
            break;                  //���X�j��
        }
        j = j + 1;
    }
}

void write(file_t file[]){  //�g�J�Ҧ�
    char name[50]="";           //�Ȧs���W��
    int list[100]={0};          //�Ȧs�����
    int i=0;
    scanf("%c", &name[0]);      //�h������r��
    printf("Mod: write:\n");    //UI
    printf("name: ");           //UI
    gets(name);                 //���ɮצW��
    printf("data:\n");          //UI
    while(1){                   //�g�J���
        scanf("%d", &list[i]);  //�N��Ƽg�J�Ȧs��
        if(list[i] == -1){      //�p�G�O�����Ÿ�
            break;              //���X
        }
        i = i + 1;
    }
    if(duplicateFileName(file, name)){  //�p�G�����ƪ��ɮצW��
        printf("Error\n");              //��X���~
    }
    else{                               //�p�G�S�����ƪ��ɮצW��
        writeFile(file, name, list);    //�s��
    }
//    printf("%s\n", file[0].name);
//    printf("%d %d %d\n", file[0].list[0], file[0].list[1], file[0].list[2]);
}
//---------/write------------

//----------read-------------
void read(){}
//---------/read-------------

//----------edit-------------
void edit(){}
//---------/edit-------------

void run(file_t file[]){
    int select=0;
    while(1){
        printf("Select mod:\n");    //���ծɨϥ�
        printf("1. write\n");       //UI
        printf("2. read\n");        //UI
        printf("3. edit\n");        //UI
        printf("4. exit\n");        //UI
        scanf("%d", &select);       //��ܼҦ�
        printf("\n");               //UI
        if(select == 1){
            write(file);
        }
        else if(select == 2){
//            read(file);
        }
        else if(select == 3){
//            edit(file);
        }
        else if(select == 4){
            break;
        }
        printf("\n");
    }
}

int main(){
    file_t file[20]={{"", {0}}};
    run(file);
//    printf("Hello world!\n");
    return 0;
}
