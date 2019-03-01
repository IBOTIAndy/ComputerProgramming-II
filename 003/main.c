#include <stdio.h>
//003 長整數運算: +, -, *
//2019/02/23

//-----input-----
void input(int longNumber[], char inNumber[], int n){
    int i=0, j=0;
    scanf("%s", inNumber);
    for(i = 0; i < n; i++){
        if(inNumber[i] == '\0'){
            i = i - 1;
            break;
        }
    }
    for(j=0; i >= 0; i--, j++){
        longNumber[j] = inNumber[i] - '0';
    }
}
//----/input-----
////-----in_run-----
//int longNumberMath(int type, int Num1, int Num2, int *Carry){
//    int ans;
//    if(type == 0){      //加法
//        ans = Num1 + Num2 + *Carry;
//        *Carry = ans / 10;
//        ans = ans % 10;
//    }
//    else if(type == 1){ //減法
//        Num1 = Num1 + *Carry;   //減法進位為-1 所以用+的
//        *Carry = 0;             //進位完 Carry 歸零
//        if(Num1 < Num2){            //如果 被減數 比 減數 小
//            Num1 = Num1 + 10;       //個位數借位
//            *Carry = *Carry - 1;    //十位數借給個位數
//        }                           //
//        ans = Num1 - Num2;      //
//    }
//    return ans;
//}
//
//void longNumberMultiply(int longNumber1[], int longNumber2[], int mulans[], int n){
//    int i=0, j=0, Carry=0;    //i為直式乘法上方的數，j為直式乘法下方的數，n2為 n/2，Carry為兩個數相加後
//    for (i=0; i < n; i++){
//        for(j=0; j < n; j++){
//            mulans[i + j] = longNumberMath(0, mulans[i + j], longNumber1[i] * longNumber2[j], &Carry);
//        }
//    }
//    //mulans[n - 1] = Carry;
//}
//
//void isNegative(int longNumber1[], int longNumber2[], int *Negative, int n){
//    int i=0, x=0;
//    *Negative = 0;
//    for(i=n; i >= 0; i--){
//        if(longNumber1[i] != 0 || longNumber2[i] != 0){
//            break;
//        }
//    }
//    if(longNumber1[i] == 0){
//        for(i=i; i >= 0; i--){
//            x = longNumber1[i];
//            longNumber1[i] = longNumber2[i];
//            longNumber2[i] = x;
//        }
//        *Negative = 1;
//    }
//    if(*Number1 < *Number2){
//        x = *Number1;
//        *Number1 = *Number2;
//        *Number2 = x;
//        *Negative = 1;
//    }
//}
//
//void cutInt(int X, int longNumber[]){
//    int i = 0;
//    while(X > 0){
//        longNumber[i] = X % 10;
//        X = X / 10;
//        i = i + 1;
//    }
//}
//
//-----test-----
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
//----/test-----
////----/in_run-----
//void run(int longNumber1[], int longNumber2[], int *negative, int addans[], int subans[], int mulans[], int n){
//    int i = 0;
//    int addCarry = 0, subCarry = 0;
//    isNegative(longNumber1, longNumber2, negative);
//    //testLongNumberOutput(longNumber1, n);
//    //testLongNumberOutput(longNumber2, n);
//    for(i=0; i<n; i++){
//        addans[i] = longNumberMath(0, longNumber1[i], longNumber2[i], &addCarry);
//        subans[i] = longNumberMath(1, longNumber1[i], longNumber2[i], &subCarry);
//    }
//    longNumberMultiply(longNumber1, longNumber2, mulans, n);
//}
////----------output----------
//void longOutput(int ans[], int n){  //輸出長整數
//    int i = 0, noOneOut = 0;
//    noOneOut = 1;
//    for(i = n; i > 0; i--){     //輸出去除0的部分
//        if(ans[i - 1] != 0){    //當找到第一個不是0的數時
//            noOneOut = 0;
//            break;              //離開迴圈
//        }
//    }
//    while(i > 0){                   //將剩下的輸出完
//        printf("%d", ans[i - 1]);
//        i = i - 1;
//    }
//    if(noOneOut == 1){
//        printf("0");
//    }
//    printf("\n");   //結束時，換行
//}
//
//void output(int addans[], int negative, int subans[], int mulans[], int n){
//    longOutput(addans, n); //加法輸出
//    if(negative == 1){      //如果第一次輸入小於第二次輸入
//        printf("-");        //減法輸出前，先輸出負數
//    }
//    longOutput(subans, n); //減法輸出
//    longOutput(mulans, n); //乘法輸出
//}
////---------/output----------
//
//void testinput003(int longNumber1[], int longNumber2[]){
//    for(i=0;i<60;i++){
//        longNumber1[i] = 1;
//        longNumber2[i] = 1;
//    }
//}

int main(){
    int addans[120] = {0}, subans[120] = {0}, mulans[120] = {0};
    int longNumber1[60] = {0}, longNumber2[60] = {0};
    int inN = 0, outN = 0;
    int negative = 0;
    char inNumber[60] = " ";
    inN = 60;
    outN = 120;
    input(longNumber1, inNumber, inN);
    //testLongNumberOutput(longNumber1, inN);
    input(longNumber2, inNumber, inN);
    //testLongNumberOutput(longNumber2, inN);
    //testinput003(longNumber1, longNumber2);
    //run(longNumber1, longNumber2, &negative, addans, subans, mulans, inN);
    //testLongNumberOutput(addans, outN);
    //testLongNumberOutput(subans, outN);
    //testLongNumberOutput(mulans, outN);
    //output(addans, negative, subans, mulans, outN);
    return 0;
}
