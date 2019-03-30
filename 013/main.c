#include <stdio.h>

//013 貪食蛇
//2019/03/30 PM.03:30 IBOTIAndy
typedef struct snake{   //蛇的結構，會往尾巴的方向指
    int body[2];        //目前位置的座標
    int size;           //蛇的長度
    int facing;         //蛇頭面對的方向，一開始為 右(4)
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
void findNext(snake *head, int next, int *x, int *y){   //找到下一個位置
    *x = head->body[0];     //先取得頭的位置
    *y = head->body[1];     //
    if(next == 1){      //上
        *y = *y - 1;    //y 往上一格 -1
    }
    else if(next == 2){ //下
        *y = *y + 1;    //y 往下一格 +1
    }
    else if(next == 3){ //左
        *x = *x - 1;    //x 往左一格 -1
    }
    else if(next == 4){ //右
        *x = *x + 1;    //x 往右一格 +1
    }
}
int isGameOver(char map[20][20], snake *head){return 0;}

int eatFruit(char map[20][20], snake *head){return 0;}

void move(int xy[2], int x, int y){ //將尾巴移向身體，身體移向頭...
    xy[0] = x;
    xy[1] = y;
}

void moveRecursuvely(snake *now, int x, int y){                 //蛇往前移動
    if(now->tail != NULL){                                      //如果還沒到尾巴
        moveRecursuvely(now->tail, now->body[0], now->body[1]); //往尾巴的位置帶入
    }
    move(now->body, x, y);                                      //將後面的身體或尾巴往前面推一格
}

void growingUp(snake *head){}
//----/game-----

void run(char map[20][20], snake *head){
    int next=0, nextX=0, nextY=0;
    mapReset(map);          //重置地圖
    testOutputMap(map, 20); //輸出地圖 (測試用)
    inputFruits(map);       //輸入水果
    testOutputMap(map, 20); //輸出地圖 (測試用)
    scanf("%d", &next);     //第一次輸入
    while(next != -1){              //如果直接結束
        if(next == 0){              //印出蛇的長度與座標
            printSnake(head);       //輸出蛇的位置
        }
        else if(next == 5){                                 //如果要前進
            findNext(head, head->facing, &nextX, &nextY);   //找到蛇要走的下一格座標
            if(isGameOver(map, head)){                      //如果撞到牆或自己，遊戲結束
                break;                                      //跳出迴圈
            }
            else if(eatFruit(map, head)){                   //吃到水果
                growingUp(head);                            //加長度
            }
            else{                                           //移動
                moveRecursuvely(head, nextX, nextY);        //遞迴到尾巴，從尾巴開始往頭移動
            }
        }
        else{                       //轉目前的面對方向
            head->facing = next;    //改變蛇頭面向的位置
        }
        scanf("%d", &next);         //重複輸入
    }
}
//---------/run----------

int main(){
    snake head={{9, 9}, 1, 4, NULL};
    char map[20][20]={{' '}};
    run(map, &head);
    return 0;
}
