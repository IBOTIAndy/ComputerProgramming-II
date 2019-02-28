#include <stdio.h>
//003 長整數運算: +, -, *
//2019/02/23
void cutInt(int X, int longNumber[]){
    int i = 0;
    while(X > 0){
        longNumber[i] = X % 10;
        X = X / 10;
        i = i + 1;
    }
}

void input(int *Number){
    scanf("%d", Number);
//    if(inX1 < inX2){
//        inY = inX1;
//        inX1 = inX2;
//        inX2 = inY;
//    }
}


int longNumberMath(int type, int Num1, int Num2, int *Carry){
    int ans;
    if(type == 0){      //加法
        ans = Num1 + Num2 + *Carry;
        *Carry = ans / 10;
        ans = ans % 10;
    }
    else if(type == 1){ //減法
        Num1 = Num1 + *Carry;   //減法進位為-1 所以用+的
        *Carry = 0;             //進位完 Carry 歸零
        if(Num1 < Num2){            //如果 被減數 比 減數 小
            Num1 = Num1 + 10;       //個位數借位
            *Carry = *Carry - 1;    //十位數借給個位數
        }                           //
        ans = Num1 - Num2;      //
    }
    return ans;
}
void isNegative(int *Number1, int *Number2, int *Negative){
    int x = 0;
    *Negative = 0;
    if(Number1 < Number2){
        x = *Number1;
        *Number1 = *Number2;
        *Number2 = x;
        *Negative = 1;
    }
}
void run(int Number1, int Number2, int *Negative, int addans[], int subans[], int mulans[]){
    int longNumber1[60] = {0}, longNumber2[60] = {0};
    int i = 0;
    int addCarry = 0, subCarry = 0, mulCarry = 0;
    isNegative(&Number1, &Number2, Negative);
    cutInt(Number1, longNumber1);
    cutInt(Number2, longNumber2);
    for(i=0; i<60; i++){
        addans[i] = longNumberMath(0, longNumber1[i], longNumber2[i], &addCarry);
        subans[i] = longNumberMath(1, longNumber1[i], longNumber2[i], &subCarry);
        //lmulans[i] = longNumberMath(2, longNumber1[i], longNumber2[i], &mulCarry);
    }
}
void longOutput(int ans[], int n){  //輸出長整數
    int i = 0;
    for(i = n; i > 0; i--){     //輸出去除0的部分
        if(ans[i - 1] != 0){    //當找到第一個不是0的數時
            break;              //離開迴圈
        }
    }
    while(i > 0){                   //將剩下的輸出完
        printf("%d", ans[i - 1]);
        i = i - 1;
    }
    printf("\n");   //結束時，換行
}

void output(int addans[], int negative, int subans[], int mulans[]){
    longOutput(addans, 60); //加法輸出
    if(negative == 1){      //如果第一次輸入小於第二次輸入
        printf("-");        //減法輸出前，先輸出負數
    }
    longOutput(subans, 60); //減法輸出
    //longOutput(mulans, 60); //乘法輸出
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

void testinput003(int *Number1, int *Number2){
    *Number1 = 186978448;
    *Number2 = 484312244;
}

void main(){
    int addans[60] = {0}, subans[60] = {0}, mulans[60] = {0};
    int number1 = 0, number2 = 0;
    int negative = 0;
    input(&number1);
    input(&number2);
    //testinput003(&number1, &number2);
    //testLongNumberOutput(longNumber1, 60);
    //testLongNumberOutput(longNumber2, 60);
    run(number1, number2, &negative, addans, subans, mulans);
    //testLongNumberOutput(addans, 60);
    //testLongNumberOutput(subans, 60);
    //testLongNumberOutput(mulans, 60);
    output(addans, negative, subans, mulans);
}
