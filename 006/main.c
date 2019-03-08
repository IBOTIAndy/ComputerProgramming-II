#include <stdio.h>

//006 以陣列實做長浮點小數的運算
//2019/03/06 IBOTIAndy
typedef struct{
    int negative;
    int integer[50];
    int integerN;
    int decimal[50];
    int decimalN;
}longNumber;



//-----input-----
void inputStateMachine(longNumber *number, char in[]){
    int type=0, i=0, j=0;
    j = number->integerN;
    for(i=0; in[i] != '\0'; i++, j--){
        if(type == 0){
            if(in[i] != '-'){
                i = i - 1;
                number->negative = 0;
            }
            else{
                number->negative = 1;
            }
            type = 1;
        }
        else if(type == 1){
            if(in[i] != '.'){
                number->integer[j] = in[i] - '0';
            }
            else{
                j = number->decimalN;
                type = 2;
            }
        }
        else if(type == 2){
            number->decimal[j] = in[i] - '0';
        }
    }
}

void input006(longNumber *number){
    char in[50]="";
    scanf("%s", in);
    inputStateMachine(number, in);
}
//----/input-----

//-----test-----
void testIntput(longNumber *number1, longNumber *number2){
    number1->negative = 0;  number2->negative = 0;
    number1->integerN = 20; number2->integerN = 20;
    number1->decimalN = 20; number2->decimalN = 20;
    inputStateMachine(number1, "4964658486415446456.41564657844548181");
    inputStateMachine(number2, "4656746465456451144.45641189184856484");
}

void outputInputtest(longNumber number){
    int i=0;
    printf("integer:\n");
    for(i=number.integerN - 1; i >=0; i--){
        printf("%d ", number.integer[i]);
        if(i % 10 == 0){
            printf("\n");
        }
    }
    printf("decimal:\n");
    for(i=number.decimalN - 1; i >= 0; i--){
        printf("%d ", number.decimal[i]);
        if(i % 10 == 0){
            printf("\n");
        }
    }
}
//----/test-----

//-----Math-----
int longNumberAlign(int number[], int n){
    int i=0, j=0;
    if(number[0] != 0){
        return 0;
    }
    for(i=0; i < n; i++){
        if(number[i] == 0){
            j = j + 1;
        }
        else{
            break;
        }
    }
    for(i=0; j < n; i++, j++){
        number[i] = number[j];
    }
    while(i < n){
        number[i] = 0;
        i = i + 1;
    }
    return 1;
}

int specificSize(longNumber *number1, longNumber *number2, int n){ //比大小
    int type=0, i=0, x=0;
    for(i = n - 1; i >= 0; i--){
        if(type == 0){
            if(number1->integer[i] != 0 || number2->integer[i] != 0){
                if(number1->integer[i] == 0){        //第一條比第二條短 需要交換位置
                    type = 2;                   //Number1 < Number2
                    break;
                }
                else if(number2->integer[i] == 0){   //第二條比第一條短 不用交換位置
                    type = 3;                   //Number1 > Number2
                    break;
                }
                else{                           //兩條一樣長 判斷更多種
                    i++;        //讓下一次判斷時 會指到正確的長整數位置
                    type = 1;
                }
            }
        }
        else if(type == 1){
            if(number1->integer[i] < number2->integer[i]){
                type = 2;
                break;
            }
            else if(number1->integer[i] > number2->integer[i]){
                type = 3;
                break;
            }
        }
    }
    if(type == 1){
        for(i = n - 1; i >= 0; i--){
            if(number1->decimal[i] < number2->decimal[i]){
                type = 2;
                break;
            }
            else if(number1->decimal[i] > number2->decimal[i]){
                type = 3;
                break;
            }
        }
    }
    if(type == 2){  //兩個常整數交換位置 程式
        for(i = n - 1; i >= 0; i--){
            x = number1->integer[i];
            number1->integer[i] = number2->integer[i];
            number2->integer[i] = x;
            x = number1->decimal[i];
            number1->decimal[i] = number2->decimal[i];
            number2->decimal[i] = x;
        }
        return 1;   //有交換
    }
    return 0;       //沒交換
}

int AdderSubtractor(int type, int Num1, int Num2, int *carry){
    int ans;
    if(type == 0){      //加法
        ans = Num1 + Num2 + *carry;
        *carry = ans / 10;
        ans = ans % 10;
    }
    else if(type == 1){ //減法
        Num1 = Num1 + *carry;   //減法進位為-1 所以用+的
        *carry = 0;             //進位完 Carry 歸零
        if(Num1 < Num2){            //如果 被減數 比 減數 小
            Num1 = Num1 + 10;       //個位數借位
            *carry = *carry - 1;    //十位數借給個位數
        }                           //
        ans = Num1 - Num2;      //
    }
    return ans;
}

void longNumberMathadd(longNumber number1, longNumber number2, longNumber *ans, int n){
    int i=0, type=0, carry=0;
    if(number1.negative != number2.negative){
        if(specificSize(&number1, &number2, n / 2)){
            ans->negative = number2.negative;
        }
        else{
            ans->negative = number1.negative;
        }
        type = 1;
    }
    else{
        ans->negative = number1.negative;
        type = 0;
    }
    for(i=0; i < n; i++){   //n=40
        if(i < 20){
            ans->decimal[i + 20] = AdderSubtractor(type, number1.decimal[i], number2.decimal[i], &carry);
        }
        else{
            ans->integer[i - 20] = AdderSubtractor(type, number1.integer[i - 20], number2.integer[i - 20], &carry);
        }
    }
}

void longNumberMathsub(longNumber number1, longNumber number2, longNumber *ans, int n){
    if(number2.negative == 0){
        number2.negative = 1;
    }
    else{
        number2.negative = 0;
    }
    longNumberMathadd(number1, number2, ans, n);
}

//void longNumberMathmul(longNumber number1, longNumber number2, longNumber *ans, int n){
//
//}

void longNumberMath(longNumber number1, longNumber number2){
    longNumber addAns={0,{0},40,{0},40}, subAns={0,{0},40,{0},40}, mulAns={0,{0},40,{0},40};
    longNumberAlign(number1.integer, number1.integerN);
    longNumberAlign(number2.integer, number2.integerN);
    longNumberMathadd(number1, number2, &addAns, addAns.integerN);
    longNumberMathsub(number1, number2, &subAns, subAns.integerN);
    //outputInputtest(addAns);
    //outputInputtest(subAns);
    //outputInputtest(mulAns);
}
//----/Math-----


int main(){
    longNumber number1={0,{0},0,{0},0}, number2={0,{0},0,{0},0};
    input006(&number1);
    input006(&number2);
    //testIntput(&number1, &number2);
    //  printf("in the main funtion:\n");
    //outputInputtest(number1);
    //outputInputtest(number2);
    longNumberMath(number1, number2);
    return 0;
}
