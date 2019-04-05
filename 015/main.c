#include <stdio.h>
#include <stdlib.h>
//015 老鼠走迷宮
//2019/04/05 IBOTIAndy PM. 02:00

//----------input----------
void input(char map[100][100], int *n){
    int i=0, j=0;
    char c=' '; //用 c 來去除空格與換行符號
    scanf("%d%c", n, &c);
    for(i=0; i < *n; i++){
        for(j=0; j < *n; j++){
            scanf("%c%c", &map[i][j], &c);
        }
    }
}
//---------/input----------

//----------run----------
void run(char map[100][100], int n){}
//---------/run----------


//----------output----------
void output(char map[100][100], int n){
    int i=0, j=0;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}
//---------/output----------


int main(){
    char map[100][100]={{'0'}};
    int n=0;
    input(map, &n);
    run(map, n);
    output(map, n);
//    printf("Hello world!\n");
    return 0;
}
