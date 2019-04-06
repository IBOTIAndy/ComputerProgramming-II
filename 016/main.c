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
void setSide(side *blockSide, int i){}

void setMagicBlock(side magicBlock[]){}
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
    run(magicBlock);
//    printf("Hello world!\n");
    return 0;
}
