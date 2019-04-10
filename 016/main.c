#include <stdio.h>
#include <stdlib.h>
//016 �]�N����ާ@
//2019/04/10 IBOTIAndy PM. 10:34
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
int notEnd(char input[]){
    if(input[0] == '-'){
        if(input[1] == '1'){
            if(input[2] == '\0'){   //�p�G�O -1
                return 0;           //�����{��
            }
        }
    }
    return 1;
}

void rotate(side *magicBlock, int lift, int right){  //����
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

void rotateTemporarily(side magicBlock, int x, int y, int *x1, int *x2, int *x3){   //�Ȧs
    if(x != -1){        //�p�G�O���V�A�����誽�ƪ��C�ӭ�
        *x1 = magicBlock.data[0][x];
        *x2 = magicBlock.data[1][x];
        *x3 = magicBlock.data[2][x];
    }
    else if(y != -1){   //�p�G�O��V�A�������ƪ��C�ӭ�
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
    int x1=0, x2=0, x3=0;   //�Ȧs
    int y1=0, y2=0, y3=0;   //�Ȧs
    int t1=0, t2=0, t3=0;
    int backx=0;
    backx = changeX(x);
    if(type == 1 || type == 2){      //Up & Down
        rotateTemporarily(magicBlock[side[0]], x, -1, &x1, &x2, &x3);       //���Ĥ@��
        rotateTemporarily(magicBlock[side[1]], x, -1, &t1, &t2, &t3);       //���ĤG��
        rotateUpDown(&magicBlock[side[0]], t1, t2, t3, x);                  //�N�ĤG����J�Ĥ@��

        rotateTemporarily(magicBlock[side[2]], backx, -1, &t1, &t2, &t3);   //���ĤT��
        rotateUpDown(&magicBlock[side[1]], t1, t2, t3, x);                  //�N�ĤT����J�ĤG��

        rotateTemporarily(magicBlock[side[3]], x, -1, &t1, &t2, &t3);       //���ĥ|��
        rotateUpDown(&magicBlock[side[2]], t1, t2, t3, backx);              //�N�ĥ|����J�ĤT��

        rotateUpDown(&magicBlock[side[3]], x1, x2, x3, x);                  //�N�Ĥ@����J�ĥ|��
    }
    else if(type == 3 || type == 4){ //Lift & Right
        rotateTemporarily(magicBlock[side[0]], y, -1, &y1, &y2, &y3);
        rotateLiftRight1(&magicBlock[side[0]], magicBlock[side[1]], y);
        rotateLiftRight1(&magicBlock[side[1]], magicBlock[side[2]], y);
        rotateLiftRight1(&magicBlock[side[2]], magicBlock[side[3]], y);
        rotateLiftRight2(&magicBlock[side[3]], y1, y2, y3, y);
    }
}

void selectSide(int side[], int x1, int x2, int x3, int x4){    //��ܷ|½�쪺��
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
                selectSide(side, 1, 3, 4, 5);           //�e���U�A�U����A�᮳�W�A�W���e
                rotateLine(magicBlock, 1, side, 0, -1); //���䩹�W
                rotate(&magicBlock[0], 1, 0);           //�����V������
            }
            else if(input[1] == 'D'){
                selectSide(side, 1, 5, 4, 3);           //�e���W�A�W����A�᮳�U�A�U���e
                rotateLine(magicBlock, 2, side, 0, -1); //���䩹�U
                rotate(&magicBlock[0], 0, 1);           //�����V�k����
            }
            else if(input[1] == 'L'){
                selectSide(side, 1, 2, 4, 0);           //�e���k�A�k����A�᮳���A�����e
                rotateLine(magicBlock, 3, side, -1, 0); //�W�䩹��
                rotate(&magicBlock[5], 0, 1);           //�W���V�k����
            }
            else if(input[1] == 'R'){
                selectSide(side, 1, 0, 4, 2);           //�e�����A������A�᮳�k�A�k���e
                rotateLine(magicBlock, 4, side, -1, 0); //�W�䩹�k
                rotate(&magicBlock[5], 1, 0);           //�W���V������
            }
        }
        else if(input[0] == '4'){
            if(input[1] == 'U'){
                selectSide(side, 1, 3, 4, 5);           //�e���U�A�U����A�᮳�W�A�W���e
                rotateLine(magicBlock, 1, side, 1, -1); //�������W
            }
            else if(input[1] == 'D'){
                selectSide(side, 1, 5, 4, 3);           //�e���W�A�W����A�᮳�U�A�U���e
                rotateLine(magicBlock, 2, side, 1, -1); //�������U
            }
            else if(input[1] == 'L'){
                selectSide(side, 1, 2, 4, 0);           //�e���k�A�k����A�᮳���A�����e
                rotateLine(magicBlock, 3, side, -1, 1); //��������
            }
            else if(input[1] == 'R'){
                selectSide(side, 1, 0, 4, 2);           //�e�����A������A�᮳�k�A�k���e
                rotateLine(magicBlock, 4, side, -1, 1); //�������k
            }
        }
        else if(input[0] == '8'){
            if(input[1] == 'U'){
                selectSide(side, 1, 3, 4, 5);           //�e���U�A�U����A�᮳�W�A�W���e
                rotateLine(magicBlock, 1, side, 2, -1); //�k�䩹�W
                rotate(&magicBlock[2], 0, 1);           //�k���V������
            }
            else if(input[1] == 'D'){
                selectSide(side, 1, 5, 4, 3);           //�e���W�A�W����A�᮳�U�A�U���e
                rotateLine(magicBlock, 2, side, 2, -1); //�k�䩹�U
                rotate(&magicBlock[2], 1, 0);           //�k���V�k����
            }
            else if(input[1] == 'L'){
                selectSide(side, 1, 2, 4, 0);           //�e���k�A�k����A�᮳���A�����e
                rotateLine(magicBlock, 3, side, -1, 2); //�U�䩹��
                rotate(&magicBlock[3], 1, 0);           //�U���V�k����
            }
            else if(input[1] == 'R'){
                selectSide(side, 1, 0, 4, 2);           //�e�����A������A�᮳�k�A�k���e
                rotateLine(magicBlock, 4, side, -1, 2); //�U�䩹�k
                rotate(&magicBlock[3], 0, 1);           //�U���V������
            }
        }
        else if(input[0] == 'C'){
            if(input[1] == 'L'){
                selectSide(side, 2, 3, 0, 5);           //�k���U�A�U�����A�����W�A�W���k
                rotateLine(magicBlock, 1, side, 0, -1); //�k��: ���䩹�W
                rotate(&magicBlock[1], 1, 0);           //�e���V������
            }
            else if(input[1] == 'R'){
                selectSide(side, 0, 3, 2, 5);           //�����U�A�U���k�A�k���W�A�W����
                rotateLine(magicBlock, 1, side, 2, -1); //����: �k�䩹�W
                rotate(&magicBlock[1], 0, 1);           //�e���V�k����
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
//    setTestOutput(magicBlock);          //���զ��S�����T�g�J
    run(magicBlock);
//    printf("Hello world!\n");
    return 0;
}
