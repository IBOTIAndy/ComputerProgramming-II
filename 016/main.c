#include <stdio.h>
#include <stdlib.h>
//016 �]�N����ާ@
//2019/04/06 IBOTIAndy PM. 03:00
typedef struct{
    int data[3][3];
}side;
//typedef struct{
//    side block[6];
//}magicBlock;

//----------set----------
//-----setTest-----
void setTestOutput(side magicBlock[]){  //�T�{��X�������T
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
void reverseSide(side *side5){              //���ܭI�����]�w
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

void setSide(side *blockSide, int side){        //�]�w�@�ӭ�
    int i=0, j=0, n=0, x=0;
    n = 3;
    side = side * 10;                           //�N����
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            blockSide->data[i][j] = side + x;   //
            x = x + 1;
        }
    }
}

void setMagicBlock(side magicBlock[]){  //�]�w�]�N���
    int i=0, n=0;
    n = 6;                              //�����6��
    for(i=0; i < n; i++){
        setSide(&magicBlock[i], i + 1); //�C���]�w�@�ӭ�
    }
    reverseSide(&magicBlock[4]);        //�I���S��ƦC
}
//---------/set----------


//----------run----------
void rotate(){  //����
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
//    setTestOutput(magicBlock);          //���զ��S�����T�g�J
    run(magicBlock);
//    printf("Hello world!\n");
    return 0;
}
