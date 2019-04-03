#include <stdio.h>
#include <stdlib.h>
//014
//
typedef struct{
    int data[9][9]; //地圖資料
    int N;          //Row, Y, 列
    int M;          //Column, X, 行
}citymap;

void setmap(int map[9][9], int N, int M){
    int i=0, j=0;
    for(i=0; i < N; i++){
        for(j=0; j < M; j++){
            scanf("%d", &(map[i][j]));
        }
    }
}

void input(citymap *map){
    scanf("%d", &(map->N));
    scanf("%d", &(map->M));
    setmap(map->data, map->N, map->M);
}

int main(){
    citymap map={{{0}}, 0, 0};
    input(&map);
//    printf("Hello world!\n");
    return 0;
}
