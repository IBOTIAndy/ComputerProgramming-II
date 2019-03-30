#include <stdio.h>

//013 貪食蛇
//2019/03/30 PM.03:30 IBOTIAndy
typedef struct snake{   //蛇的結構，會往尾巴的方向指
    int body[2];        //目前位置的座標
    int size;           //蛇的長度
    struct snake *tail; //往尾巴的方向指
}snake;

//----------test----------
void testOutputMap(char map[20][20], int n){    //輸出整張地圖 (空地與水果位置)
    int x=0, y=0;
    for(x=0; x < n; x++){
        for(y=0; y < n; y++){
            printf("%c ", map[x][y]);
        }
        printf("\n");
    }
}
//---------/test----------

//----------run----------

//-----input-----
void inputFruits(char map[20][20]){ //輸入水果的位置
    int i=0, n=0, x=0, y=0;         //
    scanf("%d", &n);                //輸入水果數量 (0 ~ 10)
    for(i=0; i < n; i++){           //直到所有水果都輸入了
        scanf("%d %d", &x, &y);     //輸入水果的座標，左上角為 (0,0) (x,y)
        map[x][y] = '#';            //'#' 代表水果
    }
}
//----/input-----

//-----output-----
void printSnake(snake *head){   //輸出蛇的長度與座標
    int i=0;                                            //
    snake *now = head;                                  //新增一個指標來往蛇的尾巴指
    printf("%d\n", head->size);                         //輸出蛇的長度
    for(i=0; i < head->size; i++){                      //輸出次數 = 長度
        printf("%d %d\n", now->body[0], now->body[1]);  //輸出座標
        now = now->tail;                                //指向下一個身體位置
    }
}
//----/output-----

//-----map-----
void mapReset(char map[20][20]){        //地圖重置
    int x=0, y=0, n=0;
    n = 20;
    for(x=0; x < n; x++){               //掃描整個地圖(x)
        for(y=0; y < n; y++){           //掃描整個地圖(y)
            if(x == 0 || x == 19){      //如果是在邊線
                map[x][y] = '1';        //設定成牆壁
            }
            else if(y == 0 || y == 19){ //如果是在邊線
                map[x][y] = '1';        //設定成牆壁
            }
            else{                       //如果不是邊線
                map[x][y] = '0';        //設定為空地
            }
        }
    }
}
//----/map-----

//-----game-----
int isGameOver(char map[20][20], snake *head, int next){return 0;}

int eatFruit(char map[20][20], snake *head, int next){return 0;}

void growingUp(snake *head){}

void move(snake *head){}
//----/game-----

void run(char map[20][20], snake *head){
    int next=0;
    next = 4;               //初始方向為右
    mapReset(map);          //重置地圖
    testOutputMap(map, 20); //輸出地圖 (測試用)
    inputFruits(map);       //輸入水果
    testOutputMap(map, 20); //輸出地圖 (測試用)
    scanf("%d", &next);     //第一次輸入
    while(next != -1){                      //如果直接結束
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
    snake head={{9, 9}, 1, NULL};
    char map[20][20]={{' '}};
    run(map, &head);
    return 0;
}
