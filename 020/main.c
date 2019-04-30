#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//020 賓果遊戲
//2019/04/30 PM.02:25 IBOTIAndy
typedef struct{
    int bingoBoard[500][500];   //賓果盤
    int x;                      // x 座標的最大值
    int y;                      // y 座標的最大值
    int winLine;                //連了幾條線
}bingoGame;

//----------input------------
void bingoBoardView(bingoGame *player){                 //看賓果盤有沒有填錯
    int x=0, y=0;
    for(y=0; y < player->y; y++){                       //將整個賓果盤都看過
        for(x=0; x < player->x; x++){                   //
            printf("%d ", player->bingoBoard[y][x]);    //輸出賓果盤的樣子
        }
        printf("\n");
    }
}

void inputBingoBoard(bingoGame *player, int n){     //在賓果盤上填上數字
    int x=0, y=0;
    for(y=0; y < n; y++){                           //將整個賓果盤都填滿
        for(x=0; x < n; x++){                       //
            scanf("%d", &player->bingoBoard[y][x]); //填上數字
        }
    }
}

void input(bingoGame *player1, bingoGame *player2){ //輸入
    int n=0;
    scanf("%d", &n);                //輸入賓果盤的大小
    player1->x = n;                 //將賓果盤的大小寫入
    player1->y = n;                 //...
    player2->x = n;                 //...
    player2->y = n;                 //...
    inputBingoBoard(player1, n);    //玩家一將自己的賓果盤填滿
    inputBingoBoard(player2, n);    //玩家二將自己的賓果盤填滿
//    bingoBoardView(player1);        //檢查玩家一的賓果盤
//    bingoBoardView(player2);        //檢查玩家二的賓果盤
}
//---------/input------------

//-----------run-------------
int changeType(char selectNumber[]){    //將字串數字改為整數
    int i=0, ans=0;
    while(selectNumber[i] != '\0'){             //直到字串沒有東西
        ans = (ans * 10) + (selectNumber[i] - '0'); //答案進位加上個位數 ans=12 number=3 => 12 * 10 + 3
        i = i + 1;
    }
//    printf("ans = %d\n", ans);                  //確認用，檢查答案
    return ans;                                 //回傳答案
}

void findSelectNumber(bingoGame *player, int select){   //找到數字並做記號
    int x=0, y=0;
    for(y=0; y < player->y; y++){           //直排掃描
        for(x=0; x < player->x; x++){           //橫排掃描
            if(player->bingoBoard[y][x] == select){ //如果找到數字
                player->bingoBoard[y][x] = -1;      //做記號(改為 -1)
                break;                              //跳出(節省計算時間)
            }
        }
    }
}

//-----winHowMuch-----
void rowWin(bingoGame *player, int y){  //橫排搜尋(y 固定)
    int x=0, connection=0;
    connection = 1;                     //連線數量設定為一條
    for(x=0; x < player->x; x++){       //直到整行找完
        if(player->bingoBoard[y][x] != -1){ //如果有一個沒有圈到
            connection = 0;                 //沒有連線
            break;                          //跳出迴圈
        }
    }
    player->winLine = player->winLine + connection; //目前連線數量 + 這次連線數量
}

void columnWin(bingoGame *player, int x){   //直排搜尋(x 固定)
    int y=0, connection=0;
    connection = 1;                     //連線數量設定為一條
    for(y=0; y < player->y; y++){       //直到整條找完
        if(player->bingoBoard[y][x] != -1){ //如果有一個沒有圈到
            connection = 0;                 //沒有連線
            break;                          //跳出迴圈
        }
    }
    player->winLine = player->winLine + connection; //目前連線數量 + 這次連線數量
}

void slashWin(bingoGame *player){   //斜線連線，左上右下、右上左下
    int i=0, x=0, y=0, connection=0;
    connection = 2;                     //連線數量設定為兩條
    for(i=0; i < player->x; i++){       //#找左上到右下#
        if(player->bingoBoard[i][i] != -1){ //如果有一個沒有圈到
            connection = connection - 1;    //連線數量 - 1
            break;                          //跳出迴圈
        }
    }
    x = player->x - 1;                  //#找右上到左下#，將 x 改為從最右邊開始
    for(y=0; y < player->y; y++, x--){  //y 增加(往下), x 減少(往左)
        if(player->bingoBoard[y][x] != -1){ //如果有一個沒圈到
            connection = connection - 1;    //連線數量 - 1
            break;                          //跳出迴圈
        }
    }
    player->winLine = player->winLine + connection; //目前連線數量 + 這次連線數量
}

void winHowMuch(bingoGame *player){ //計算贏了多少(連線連多少條)
    int i=0;
    for(i=0; i < player->x; i++){   //掃描整個賓果盤
        rowWin(player, i);          //橫排，i 當作 y 使用(上下固定位置)
        columnWin(player, i);       //直排，i 當作 x 使用(左右固定位置)
    }
    slashWin(player);               //斜線
}
//----/winHowMuch-----

void run(bingoGame *player1, bingoGame *player2){   //執行
    int select=0;
    char *selectNumber;
    char selectLine[500]="";
    scanf("%c", &selectLine[0]);            //過濾上一次輸入的'\n'
    gets(selectLine);                       //輸入一整串由空格隔開的數字
    selectNumber = strtok(selectLine, " "); //將數字切割出來
    while(selectNumber != NULL){            //如果還有數字，直到數字都執行完畢
        select = changeType(selectNumber);      //將切下來的數字，把型態從字元轉成整數
        findSelectNumber(player1, select);      //圈出玩家一賓果盤上的數字
        findSelectNumber(player2, select);      //圈出玩家二賓果盤上的數字
        selectNumber = strtok(NULL, " ");       //繼續將數字切割出來
    }
    winHowMuch(player1);                    //計算玩家一連了幾條線
    winHowMuch(player2);                    //計算玩家二連了幾條線
//    printf("player1=%d\n", player1->winLine);   //確認用，輸出玩家一連線數量
//    printf("player2=%d\n", player2->winLine);   //確認用，輸出玩家二連線數量
}
//---------/run--------------

//----------output-----------
void output(bingoGame player1, bingoGame player2){  //輸出結果(Player? wins "連線數量", Player? loses "連線數量")
    if(player1.winLine > player2.winLine){      //如果玩家一勝利
        printf("Player1 wins %d, Player2 loses %d", player1.winLine, player2.winLine);
    }           //玩家一先輸出
    else if(player1.winLine < player2.winLine){ //如果玩家二勝利
        printf("Player2 wins %d, Player1 loses %d", player2.winLine, player1.winLine);
    }           //玩家二先輸出
    else{                                       //平手
        printf("Draw %d", player1.winLine);
    }           //平手, 連了幾條線
}
//---------/output-----------

int main(){
    bingoGame player1={{{0}}, 0, 0, 0};
    bingoGame player2={{{0}}, 0, 0, 0};
    input(&player1, &player2);          //輸入(輸入n, 玩家一、二的賓果盤)
    run(&player1, &player2);            //執行(將選到的數字刪除、計算連了幾條線)
    output(player1, player2);           //輸出(輸出勝負與連了幾條線)
//    printf("Hello world!\n");
    return 0;
}
