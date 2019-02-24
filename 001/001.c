#include <stdio.h>
//001 ¤­¤l´Ñ   [Y][X]
//2019/02/23

//----------input----------
void input001(int checkerboard[][10]){
    int y = 0, x = 0;
    for(y = 0; y < 10; y++){
        for(x = 0; x < 10; x++){
            scanf("%d", &checkerboard[y][x]);
        }
    }
}
//---------/input-----run----------
int updown(table[][10], int x, int y){
    int i = 0, n = 0, haveFlag = 0;
    if(y < 4){
        n = y;
    }
    else{
        n = 4;
    }
    for(i = 1; i < n + 1; i++){
        if(table[y - i][x] == 1){
            haveFlag++;
        }
        else{
            break;
        }
    }
    if(y > 5){
        n = 9 - y;
    }
    else{
        n = 4;
    }
    for(i = 1; i < n; i++){
        if(table[y + i][x] == 1){
            haveFlag++;
        }
        else{
            break;
        }
    }
    return haveFlag;
}
int RightLift(table[][10], int x, int y){
    int i = 0, n = 0, haveFlag = 0;
    if(x < 4){
        n = x;
    }
    else{
        n = 4;
    }
    for(i = 1; i < n + 1; i++){
        if(table[y][x - 1] == 1){
            haveFlag++;
        }
        else{
            break;
        }
    }
    if(x > 5){
        n = 9 - x;
    }
    else{
        n = 4;
    }
    for(i = 1; i < n; i++){
        if(table[y][x + i] == 1){
            haveFlag++;
        }
        else{
            break;
        }
    }
    return haveFlag;
}




void run(int table[][10], int x, int y){
    for()
}

void select(int table[][10]){
    int y = 0, x = 0;
    for(y = 0; y < 10; y++){
        for(x = 0; x < 10; x++){
            run(table, x, y);
        }
    }
}

//----------/run-----test----------
void testArray2Output(int array2[][10], int y, int x){
    int i = 0, j = 0;
    for(i = 0; i < y; i++){
        for(j = 0; j < x; j++){
            printf("%d ", array2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void testinput001(int checkerboard[][10]){
    checkerboard[0][8] = 1; checkerboard[1][6] = 1;
    checkerboard[1][7] = 1; checkerboard[2][6] = 1;
    checkerboard[3][6] = 1; checkerboard[3][7] = 1;
    checkerboard[3][8] = 1; checkerboard[3][9] = 1;
    checkerboard[4][4] = 1; checkerboard[4][6] = 1;
    checkerboard[6][3] = 1; checkerboard[7][3] = 1;
    checkerboard[8][2] = 1; checkerboard[8][3] = 1;
    checkerboard[8][4] = 1; checkerboard[8][5] = 1;
    checkerboard[9][3] = 1;
}
//----------/test----------
void main(){
    int checkerboard[10][10] = {0};
    //input001(checkerboard);
    testinput001(checkerboard);
    testArray2Output(checkerboard, 10, 10);
    select(checkerboard);
}
