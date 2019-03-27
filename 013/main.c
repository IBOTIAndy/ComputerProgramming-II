#include <stdio.h>

//013 �g���D
//2019/03/28 AM.00:35 IBOTIAndy
typedef struct snake{
    int body[2];
    struct snake *tail;
}snake;

//----------run----------

//-----input-----
void inputFruits(char map[20][20]){}
//----/input-----

//-----output-----
void printSnake(snake *head){}
//----/output-----

//-----map-----
void mapReset(char map[20][20]){}

void mapUpdate(char map[20][20], snake *head){}
//----/map-----

//-----game-----
int isGameOver(char map[20][20], snake *head, int next){}

int eatFruit(char map[20][20], snake *head, int next){}

void growingUp(snake *head){}

void move(snake *head){}
//----/game-----

void run(char map[20][20], snake *head){
    int next=0;
    next = 4;           //��l��V���k
    mapReset(map);
    inputFruits(map);
    scanf("%d", &next);
    while(next != -1){                      //�p�G��������
        mapUpdate(map, head);               //��s�a��
        if(next == 0){                      //�L�X�D�����׻P�y��
            printSnake(head);
        }
        if(isGameOver(map, head, next)){    //�p�G������Φۤv�A�C������
            break;
        }
        else if(eatFruit(map, head, next)){ //�Y����G
            growingUp(head);                //�[����
        }
        else{                               //����
            move(head);
        }
        scanf("%d", &next);                 //���ƿ�J
    }
}
//---------/run----------

int main(){
    snake head={{0}, NULL};
    char map[20][20]={'0'};
    run(map, &head);
    return 0;
}
