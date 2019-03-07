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

//void longNumberMath(longNumber number1, longNumber number2){
//
//}

//-----test-----
void testIntput(longNumber *number1, longNumber *number2){
    number1->negative = 0;  number2->negative = 0;
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

int main(){
    longNumber number1={0,{0},20,{0},20}, number2={0,{0},20,{0},20};
    //input006(&number1);
    //input006(&number2);
    testIntput(&number1, &number2);
    printf("in the main funtion:\n");
    outputInputtest(number1);
    outputInputtest(number2);
//    longNumberMath(number1, number2);
    return 0;
}
