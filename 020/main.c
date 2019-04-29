#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//020 賓果遊戲
//2019/04/30 AM.01:29 IBOTIAndy
typedef struct{
    int bingoBoard[500][500];
    int x;
    int y;
    int winLine;
}bingoGame;

//----------input----------
void bingoBoardView(bingoGame *player){
    int x=0, y=0;
    for(y=0; y < player->y; y++){
        for(x=0; x < player->x; x++){
            printf("%d ", player->bingoBoard[y][x]);
        }
        printf("\n");
    }
}

void inputBingoBoard(bingoGame *player, int n){
    int x=0, y=0;
    for(y=0; y < n; y++){
        for(x=0; x < n; x++){
            scanf("%d", &player->bingoBoard[y][x]);
        }
    }
}

void input(bingoGame *player1, bingoGame *player2){
    int n=0;
    scanf("%d", &n);
    player1->x = n;
    player1->y = n;
    player2->x = n;
    player2->y = n;
    inputBingoBoard(player1, n);
    inputBingoBoard(player2, n);
//    bingoBoardView(player1);
//    bingoBoardView(player2);
}
//---------/input----------

int changeType(char selectNumber[]){
    int i=0, ans=0;
    while(selectNumber[i] != '\0'){
        ans = (ans * 10) + (selectNumber[i] - '0');
        i = i + 1;
    }
//    printf("ans = %d\n", ans);
    return ans;
}

void findSelectNumber(bingoGame *player, int select){
    int x=0, y=0;
    for(y=0; y < player->y; y++){
        for(x=0; x < player->x; x++){
            if(player->bingoBoard[y][x] == select){
                player->bingoBoard[y][x] = -1;
                break;
            }
        }
    }
}

void rowWin(bingoGame *player, int y){
    int x=0, connection=0;
    connection = 1;
    for(x=0; x < player->x; x++){
        if(player->bingoBoard[y][x] != -1){
            connection = 0;
            break;
        }
    }
    player->winLine = player->winLine + connection;
}

void columnWin(bingoGame *player, int x){
    int y=0, connection=0;
    connection = 1;
    for(y=0; y < player->y; y++){
        if(player->bingoBoard[y][x] != -1){
            connection = 0;
            break;
        }
    }
    player->winLine = player->winLine + connection;
}

void slashWin(bingoGame *player){
    int i=0, x=0, y=0, connection=0;
    connection = 2;
    for(i=0; i < player->x; i++){
        if(player->bingoBoard[i][i] != -1){
            connection = connection - 1;
            break;
        }
    }
    x = player->x - 1;
    for(y=0; y < player->y; y++, x--){
        if(player->bingoBoard[y][x] != -1){
            connection = connection - 1;
            break;
        }
    }
    player->winLine = player->winLine + connection;
}

void winHowMuch(bingoGame *player){
    int i=0;
    for(i=0; i < player->x; i++){
        rowWin(player, i);
        columnWin(player, i);
    }
    slashWin(player);
    //斜線
}

void run(bingoGame *player1, bingoGame *player2){
    int select=0;
    char *selectNumber;
    char selectLine[500]="";
    scanf("%c", &selectLine[0]);
    gets(selectLine);
    selectNumber = strtok(selectLine, " ");
    while(selectNumber != NULL){
        select = changeType(selectNumber);
        findSelectNumber(player1, select);          //圈出輸入的數字
        findSelectNumber(player2, select);          //圈出輸入的數字
        selectNumber = strtok(NULL, " ");
    }
    winHowMuch(player1);
    winHowMuch(player2);
//    printf("player1=%d\n", player1->winLine);
//    printf("player2=%d\n", player2->winLine);
}

int main(){
    bingoGame player1={{{0}}, 0, 0, 0};
    bingoGame player2={{{0}}, 0, 0, 0};
    input(&player1, &player2);
    run(&player1, &player2);
//    printf("Hello world!\n");
    return 0;
}
