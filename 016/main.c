#include <stdio.h>
#include <stdlib.h>
//016 魔術方塊操作
//2019/04/06 IBOTIAndy PM. 03:00
typedef struct{
    int data[3][3];
}side;
//typedef struct{
//    side block[6];
//}magicBlock;

//----------set----------
//-----setTest-----
void setTestOutput(side magicBlock[]){  //確認輸出正不正確
    int side=0, i=0, j=0;
    for(side=0; side < 6; side++){
        printf("\nSide%d:\n", side + 1);
        for(i=0; i < 3; i++){
            for(j=0; j < 3; j++){
                printf("%d ", magicBlock[side].data[i][j]);
            }
            printf("\n");
        }
    }
}
//----/setTest-----
void reverseSide(side *side5){              //改變背面的設定
    int temporarily[3]={0};
    temporarily[0] = side5->data[0][0];
    temporarily[1] = side5->data[0][1];
    temporarily[2] = side5->data[0][2];
    side5->data[0][0] = side5->data[2][0];
    side5->data[0][1] = side5->data[2][1];
    side5->data[0][2] = side5->data[2][2];
    side5->data[2][0] = temporarily[0];
    side5->data[2][1] = temporarily[1];
    side5->data[2][2] = temporarily[2];
}

void setSide(side *blockSide, int side){        //設定一個面
    int i=0, j=0, n=0, x=0;
    n = 3;
    side = side * 10;                           //代表的面
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            blockSide->data[i][j] = side + x;   //
            x = x + 1;
        }
    }
}

void setMagicBlock(side magicBlock[]){  //設定魔術方塊
    int i=0, n=0;
    n = 6;                              //方塊為6面
    for(i=0; i < n; i++){
        setSide(&magicBlock[i], i + 1); //每次設定一個面
    }
    reverseSide(&magicBlock[4]);        //背面特殊排列
}
//---------/set----------


//----------run----------
void rotate(){  //旋轉
}

void rotateUp(){}
void rotateDown(){}
void rotateLift(){}
void rotateRight(){}

int notEnd(char input[]){return 0;}

void run(side magicBlock[]){
    char input[5]={' '};
    scanf("%s", input);
    while(notEnd(input)){
        if(input[0] == '0'){

        }
        else if(input[0] == '4'){

        }
        else if(input[0] == '8'){

        }
        else if(input[0] == 'C'){

        }
        scanf("%s", input);
    }
}
//---------/run----------

int main(){
    side magicBlock[6];
    setMagicBlock(magicBlock);
//    setTestOutput(magicBlock);          //測試有沒有正確寫入
    run(magicBlock);
//    printf("Hello world!\n");
    return 0;
}
