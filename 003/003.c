#include <stdio.h>
//003 ����ƹB��: +, -, *
//2019/02/23
void cutInt(int X, int longNumber[]){
    int i = 0;
    while(X > 0){
        longNumber[i] = X % 10;
        X = X / 10;
        i = i + 1;
    }
}

void input(int longNumber[]){
    int inX = 0;
    scanf("%d", &inX);
    cutInt(inX, longNumber);
}

int longNumberMath(int type, int Num1, int Num2, int *Carry){
    int ans;
    if(type == 0){      //�[�k
        ans = Num1 + Num2 + *Carry;
        *Carry = ans / 10;
        ans = ans % 10;
    }
    else if(type == 1){ //��k
        Num1 = Num1 + *Carry;   //��k�i�쬰-1 �ҥH��+��
        *Carry = 0;             //�i�짹 Carry �k�s
        if(Num1 < Num2){            //�p�G �Q��� �� ��� �p
            Num1 = Num1 + 10;       //�Ӧ�ƭɦ�
            *Carry = *Carry - 1;    //�Q��ƭɵ��Ӧ��
        }                           //
        ans = Num1 - Num2;      //
    }
    else if(type == 2){ //���k
        ans = Num1 * Num2 + *Carry;
        *Carry = ans / 10;
        ans = ans % 10;
    }

    return ans;
}

void run(int longNumber1[], int longNumber2[], int addans[], int subans[], int mulans[]){
    int i = 0;
    int addCarry = 0;
    int subCarry = 0;
    int mulCarry = 0;
    for(i=0; i<60; i++){
        addans[i] = longNumberMath(0, longNumber1[i], longNumber2[i], &addCarry);
        subans[i] = longNumberMath(1, longNumber1[i], longNumber2[i], &subCarry);
        mulans[i] = longNumberMath(2, longNumber1[i], longNumber2[i], &mulCarry);
    }
}

void testLongNumberOutput(int NumberArray[], int n){
    int i = 0;
    n = n - 1;
    for(i = 0; n >= i; n--){
        printf("%d ", NumberArray[n]);
        if(n % 10 == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void testinput003(int NumberArray1[], int NumberArray2[]){
    NumberArray1[0] = 8;    NumberArray1[1] = 4;    NumberArray1[2] = 4;
    NumberArray1[3] = 8;    NumberArray1[4] = 7;    NumberArray1[5] = 9;
    NumberArray1[6] = 6;    NumberArray1[7] = 8;    NumberArray1[8] = 1;
    NumberArray2[0] = 4;    NumberArray2[1] = 4;    NumberArray2[2] = 2;
    NumberArray2[3] = 2;    NumberArray2[4] = 1;    NumberArray2[5] = 3;
    NumberArray2[6] = 4;    NumberArray2[7] = 8;    NumberArray2[8] = 4;
}

void main(){
    int longNumber1[60] = {0}, longNumber2[60] = {0};
    int addans[60] = {0}, subans[60] = {0}, mulans[60] = {0};
    //input(longNumber1);
    testinput003(longNumber1, longNumber2);
    //testLongNumberOutput(longNumber1, 60);
    //testLongNumberOutput(longNumber2, 60);
    run(longNumber1, longNumber2, addans, subans, mulans);
    testLongNumberOutput(addans, 60);
    testLongNumberOutput(subans, 60);
    testLongNumberOutput(mulans, 60);
    //output();

}
