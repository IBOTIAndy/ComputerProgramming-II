#include <stdio.h>
#include <stdlib.h>
//016 魔術方塊操作
//2019/04/10 IBOTIAndy PM. 10:34
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
int notEnd(char input[]){
    if(input[0] == '-'){
        if(input[1] == '1'){
            if(input[2] == '\0'){   //如果是 -1
                return 0;           //結束程式
            }
        }
    }
    return 1;
}

void rotate(side *magicBlock, int lift, int right){  //旋轉
    int temporarily1=0, temporarily2=0;
    if(lift){
        temporarily1 = magicBlock->data[0][0];
        temporarily2 = magicBlock->data[0][1];

        magicBlock->data[0][0] = magicBlock->data[0][2];
        magicBlock->data[0][1] = magicBlock->data[1][2];

        magicBlock->data[0][2] = magicBlock->data[2][2];
        magicBlock->data[1][2] = magicBlock->data[2][1];

        magicBlock->data[2][2] = magicBlock->data[2][0];
        magicBlock->data[2][1] = magicBlock->data[1][0];

        magicBlock->data[2][0] = temporarily1;
        magicBlock->data[1][0] = temporarily2;
    }
    else if(right){
        temporarily1 = magicBlock->data[0][1];
        temporarily2 = magicBlock->data[0][2];

        magicBlock->data[0][1] = magicBlock->data[0][0];
        magicBlock->data[0][2] = magicBlock->data[1][0];

        magicBlock->data[0][0] = magicBlock->data[2][0];
        magicBlock->data[1][0] = magicBlock->data[2][1];

        magicBlock->data[2][0] = magicBlock->data[2][2];
        magicBlock->data[2][1] = magicBlock->data[1][2];

        magicBlock->data[2][2] = temporarily1;
        magicBlock->data[1][2] = temporarily2;
    }
}

void rotateTemporarily(side magicBlock, int x, int y, int *x1, int *x2, int *x3){   //暫存
    if(x != -1){        //如果是直向，紀錄剛直排的每個值
        *x1 = magicBlock.data[0][x];
        *x2 = magicBlock.data[1][x];
        *x3 = magicBlock.data[2][x];
    }
    else if(y != -1){   //如果是橫向，紀錄剛橫排的每個值
        *x1 = magicBlock.data[y][0];
        *x2 = magicBlock.data[y][1];
        *x3 = magicBlock.data[y][2];
    }
}

//-------Up & Down------
void rotateUpDown(side *inMagicBlock, int x1, int x2, int x3, int x){
    inMagicBlock->data[0][x] = x1;
    inMagicBlock->data[1][x] = x2;
    inMagicBlock->data[2][x] = x3;
}
//------/Up & Down------

//-----Lift & Right-----
void rotateLiftRight1(side *inMagicBlock, side outMagicBlock, int y){
    inMagicBlock->data[y][0] = outMagicBlock.data[y][0];
    inMagicBlock->data[y][1] = outMagicBlock.data[y][1];
    inMagicBlock->data[y][2] = outMagicBlock.data[y][2];
}
void rotateLiftRight2(side *inMagicBlock, int y1, int y2, int y3, int y){
    inMagicBlock->data[y][0] = y1;
    inMagicBlock->data[y][1] = y2;
    inMagicBlock->data[y][2] = y3;
}
//----/Lift & Right-----

int changeX(int x){
    if(x == 0){
        x = 2;
    }
    else if(x == 2){
        x = 0;
    }
    return x;
}

void rotateLine(side magicBlock[], int type, int side[], int x, int y){
    int x1=0, x2=0, x3=0;   //暫存
    int y1=0, y2=0, y3=0;   //暫存
    int t1=0, t2=0, t3=0;
    int backx=0;
    backx = changeX(x);
    if(type == 1 || type == 2){      //Up & Down
        rotateTemporarily(magicBlock[side[0]], x, -1, &x1, &x2, &x3);       //拿第一面
        rotateTemporarily(magicBlock[side[1]], x, -1, &t1, &t2, &t3);       //拿第二面
        rotateUpDown(&magicBlock[side[0]], t1, t2, t3, x);                  //將第二面放入第一面

        rotateTemporarily(magicBlock[side[2]], backx, -1, &t1, &t2, &t3);   //拿第三面
        rotateUpDown(&magicBlock[side[1]], t1, t2, t3, x);                  //將第三面放入第二面

        rotateTemporarily(magicBlock[side[3]], x, -1, &t1, &t2, &t3);       //拿第四面
        rotateUpDown(&magicBlock[side[2]], t1, t2, t3, backx);              //將第四面放入第三面

        rotateUpDown(&magicBlock[side[3]], x1, x2, x3, x);                  //將第一面放入第四面
    }
    else if(type == 3 || type == 4){ //Lift & Right
        rotateTemporarily(magicBlock[side[0]], y, -1, &y1, &y2, &y3);
        rotateLiftRight1(&magicBlock[side[0]], magicBlock[side[1]], y);
        rotateLiftRight1(&magicBlock[side[1]], magicBlock[side[2]], y);
        rotateLiftRight1(&magicBlock[side[2]], magicBlock[side[3]], y);
        rotateLiftRight2(&magicBlock[side[3]], y1, y2, y3, y);
    }
}

void selectSide(int side[], int x1, int x2, int x3, int x4){    //選擇會翻到的面
    side[0] = x1;
    side[1] = x2;
    side[2] = x3;
    side[3] = x4;
}

void run(side magicBlock[]){
    int side[4]={0};
    char input[5]={' '};
//    setTestOutput(magicBlock);
    scanf("%s", input);
    while(notEnd(input)){
        if(input[0] == '0'){
            if(input[1] == 'U'){
                selectSide(side, 1, 3, 4, 5);           //前拿下，下拿後，後拿上，上拿前
                rotateLine(magicBlock, 1, side, 0, -1); //左邊往上
                rotate(&magicBlock[0], 1, 0);           //左面向左旋轉
            }
            else if(input[1] == 'D'){
                selectSide(side, 1, 5, 4, 3);           //前拿上，上拿後，後拿下，下拿前
                rotateLine(magicBlock, 2, side, 0, -1); //左邊往下
                rotate(&magicBlock[0], 0, 1);           //左面向右旋轉
            }
            else if(input[1] == 'L'){
                selectSide(side, 1, 2, 4, 0);           //前拿右，右拿後，後拿左，左拿前
                rotateLine(magicBlock, 3, side, -1, 0); //上邊往左
                rotate(&magicBlock[5], 0, 1);           //上面向右旋轉
            }
            else if(input[1] == 'R'){
                selectSide(side, 1, 0, 4, 2);           //前拿左，左拿後，後拿右，右拿前
                rotateLine(magicBlock, 4, side, -1, 0); //上邊往右
                rotate(&magicBlock[5], 1, 0);           //上面向左旋轉
            }
        }
        else if(input[0] == '4'){
            if(input[1] == 'U'){
                selectSide(side, 1, 3, 4, 5);           //前拿下，下拿後，後拿上，上拿前
                rotateLine(magicBlock, 1, side, 1, -1); //中間往上
            }
            else if(input[1] == 'D'){
                selectSide(side, 1, 5, 4, 3);           //前拿上，上拿後，後拿下，下拿前
                rotateLine(magicBlock, 2, side, 1, -1); //中間往下
            }
            else if(input[1] == 'L'){
                selectSide(side, 1, 2, 4, 0);           //前拿右，右拿後，後拿左，左拿前
                rotateLine(magicBlock, 3, side, -1, 1); //中間往左
            }
            else if(input[1] == 'R'){
                selectSide(side, 1, 0, 4, 2);           //前拿左，左拿後，後拿右，右拿前
                rotateLine(magicBlock, 4, side, -1, 1); //中間往右
            }
        }
        else if(input[0] == '8'){
            if(input[1] == 'U'){
                selectSide(side, 1, 3, 4, 5);           //前拿下，下拿後，後拿上，上拿前
                rotateLine(magicBlock, 1, side, 2, -1); //右邊往上
                rotate(&magicBlock[2], 0, 1);           //右面向左旋轉
            }
            else if(input[1] == 'D'){
                selectSide(side, 1, 5, 4, 3);           //前拿上，上拿後，後拿下，下拿前
                rotateLine(magicBlock, 2, side, 2, -1); //右邊往下
                rotate(&magicBlock[2], 1, 0);           //右面向右旋轉
            }
            else if(input[1] == 'L'){
                selectSide(side, 1, 2, 4, 0);           //前拿右，右拿後，後拿左，左拿前
                rotateLine(magicBlock, 3, side, -1, 2); //下邊往左
                rotate(&magicBlock[3], 1, 0);           //下面向右旋轉
            }
            else if(input[1] == 'R'){
                selectSide(side, 1, 0, 4, 2);           //前拿左，左拿後，後拿右，右拿前
                rotateLine(magicBlock, 4, side, -1, 2); //下邊往右
                rotate(&magicBlock[3], 0, 1);           //下面向左旋轉
            }
        }
        else if(input[0] == 'C'){
            if(input[1] == 'L'){
                selectSide(side, 2, 3, 0, 5);           //右拿下，下拿左，左拿上，上拿右
                rotateLine(magicBlock, 1, side, 0, -1); //右面: 左邊往上
                rotate(&magicBlock[1], 1, 0);           //前面向左旋轉
            }
            else if(input[1] == 'R'){
                selectSide(side, 0, 3, 2, 5);           //左拿下，下拿右，右拿上，上拿左
                rotateLine(magicBlock, 1, side, 2, -1); //左面: 右邊往上
                rotate(&magicBlock[1], 0, 1);           //前面向右旋轉
            }
        }
//        setTestOutput(magicBlock);
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
