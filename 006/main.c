#include <stdio.h>

//006 以陣列實做長浮點小數的運算
//2019/03/06 IBOTIAndy
typedef struct{
    int negative;
    int integer[20];
    int integerN;
    int decimal[20];
    int decimalN;
}longNumber;
//-----input-----
void input006(longNumber *number){
    char in[50]="";
    int type=0, i=0, j=0, n=0;
    scanf("%s", in);
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
    //printf("in the input funtion:\n");
    //outputInputtest(number);
    //printf("\n");
}
//----/input-----

//void longNumberMath(longNumber number1, longNumber number2){
//
//}

//-----test-----
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

int main(){
    longNumber number1={0,{0},20,{0},20}, number2={0,{0},20,{0},20};
    input006(&number1);
    input006(&number2);
    printf("in the main funtion:\n");
    outputInputtest(number1);
    outputInputtest(number2);
//    longNumberMath(number1, number2);
    return 0;
}
