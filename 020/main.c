#include <stdio.h>
#include <stdlib.h>
//020 »«ªG¹CÀ¸
//2019/04/28 AM.03:48 IBOTIAndy
typedef struct{
    int bingoBoard[500][500];
    int x;
    int y;
    int winLine;
}bingoGame;

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

void run(bingoGame *player1, bingoGame *player2){}

int main(){
    bingoGame player1={{{0}}, 0, 0, 0};
    bingoGame player2={{{0}}, 0, 0, 0};
    input(&player1, &player2);
    run(&player1, &player2);
//    printf("Hello world!\n");
    return 0;
}
