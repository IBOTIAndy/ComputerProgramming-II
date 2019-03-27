#include <stdio.h>

//013 貪食蛇
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
    next = 4;           //初始方向為右
    mapReset(map);
    inputFruits(map);
    scanf("%d", &next);
    while(next != -1){                      //如果直接結束
        mapUpdate(map, head);               //更新地圖
        if(next == 0){                      //印出蛇的長度與座標
            printSnake(head);
        }
        if(isGameOver(map, head, next)){    //如果撞到牆或自己，遊戲結束
            break;
        }
        else if(eatFruit(map, head, next)){ //吃到水果
            growingUp(head);                //加長度
        }
        else{                               //移動
            move(head);
        }
        scanf("%d", &next);                 //重複輸入
    }
}
//---------/run----------

int main(){
    snake head={{0}, NULL};
    char map[20][20]={'0'};
    run(map, &head);
    return 0;
}
