#include <stdio.h>
#include <stdlib.h>
//015 老鼠走迷宮
//2019/04/05 IBOTIAndy PM. 03:28

//----------input----------
void input(char map[100][100], int *n){
    int i=0, j=0;
    char c=' ';                             //用 c 來去除空格與換行符號
    scanf("%d%c", n, &c);                   //輸入地圖的大小(正方形)
    for(i=0; i < *n; i++){
        for(j=0; j < *n; j++){
            scanf("%c%c", &map[i][j], &c);  //輸入地圖的樣子
        }
    }
}
//---------/input----------

//----------run----------
int mouse(char map[100][100], int x, int y, int end){   //老鼠
    if(map[y][x] == '1'){       //如果撞到牆
        return 1;
    }
    else if(map[y][x] == '#'){  //如果已經走過了
        return 1;
    }
    map[y][x] = '#';            //如果沒撞到也沒走過，紀錄走過
    if(x == end && y == end){   //如果走到出口
        return 0;               //結束
    }
    if(mouse(map, x    , y + 1, end) == 0){ //下
        return 0;
    }
    if(mouse(map, x    , y - 1, end) == 0){ //上
        return 0;
    }
    if(mouse(map, x - 1, y    , end) == 0){ //左
        return 0;
    }
    if(mouse(map, x + 1, y    , end) == 0){ //右
        return 0;
    }
    map[y][x] = '*';            //如果下上左右都不能走，記錄下來
    return 1;                   //並原路返回
}

void run(char map[100][100], int n){
    int x=0, y=0, end=0;
    x = 1;                  //起始位置為左上角
    y = 1;                  //
    end = n - 2;            //迷宮右下角為[n-2][n-2]的位置
    mouse(map, x, y, end);  //放入老鼠
}
//---------/run----------


//----------output----------
void output(char map[100][100], int n){ //輸出整張地圖
    int i=0, j=0;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){           //輸出一行
            printf("%c ", map[i][j]);
        }
        printf("\n");                   //輸出完一行 換行
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
