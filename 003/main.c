#include <stdio.h>
//003 ����ƹB��: +, -, *
//2019/03/01_P.M.06:26

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
    return ans;
}

void longNumberMultiply(int longNumber1[], int longNumber2[], int mulans[], int n){
    int i=0, j=0, Carry=0;    //i���������k�W�誺�ơAj���������k�U�誺�ơAn2�� n/2�ACarry����ӼƬۥ[��
    for (i=0; i < n; i++){
        for(j=0; j < n; j++){
            mulans[i + j] = longNumberMath(0, mulans[i + j], longNumber1[i] * longNumber2[j], &Carry);
        }
    }
    //mulans[n - 1] = Carry;
}

void isNegative(int longNumber1[], int longNumber2[], int *Negative, int n){
    int type = 0, i=0, x=0;
    *Negative = 0;
    for(i = n - 1; i >= 0; i--){
        if(type == 0){
            if(longNumber1[i] != 0 || longNumber2[i] != 0){
                if(longNumber1[i] == 0){        //�Ĥ@����ĤG���u �ݭn�洫��m
                    type = 2;                   //Number1 < Number2
                    *Negative = 1;
                    break;
                }
                else if(longNumber2[i] == 0){   //�ĤG����Ĥ@���u ���Υ洫��m
                    type = 3;                   //Number1 > Number2
                    *Negative = 0;
                    break;
                }
                else{                           //����@�˪� �P�_��h��
                    i++;        //���U�@���P�_�� �|���쥿�T������Ʀ�m
                    type = 1;
                }
            }
        }
        else if(type == 1){
            if(longNumber1[i] < longNumber2[i]){
                type = 2;
                *Negative = 1;
                break;
            }
            else if(longNumber1[i] > longNumber2[i]){
                type = 3;
                *Negative = 0;
                break;
            }
        }
    }
    if(type == 2){  //��ӱ`��ƥ洫��m �{��
        for(i = n - 1; i >= 0; i--){
            x = longNumber1[i];
            longNumber1[i] = longNumber2[i];
            longNumber2[i] = x;
        }
    }
    //printf("type = %d, Neg = %d", type, *Negative);
}
//----/in_run-----
void run(int longNumber1[], int longNumber2[], int *negative, int addans[], int subans[], int mulans[], int n){
    int i = 0;
    int addCarry = 0, subCarry = 0;
    isNegative(longNumber1, longNumber2, negative, n);
    for(i=0; i<n; i++){
        addans[i] = longNumberMath(0, longNumber1[i], longNumber2[i], &addCarry);
        subans[i] = longNumberMath(1, longNumber1[i], longNumber2[i], &subCarry);
    }
    longNumberMultiply(longNumber1, longNumber2, mulans, n);
}
//----/run-----
//----------output----------
void longOutput(int ans[], int n){  //��X�����
    int i = 0, noOneOut = 0;
    noOneOut = 1;
    for(i = n; i > 0; i--){     //��X�h��0������
        if(ans[i - 1] != 0){    //����Ĥ@�Ӥ��O0���Ʈ�
            noOneOut = 0;
            break;              //���}�j��
        }
    }
    while(i > 0){                   //�N�ѤU����X��
        printf("%d", ans[i - 1]);
        i = i - 1;
    }
    if(noOneOut == 1){
        printf("0");
    }
    printf("\n");   //�����ɡA����
}

void output(int addans[], int negative, int subans[], int mulans[], int n){
    longOutput(addans, n); //�[�k��X
    if(negative == 1){      //�p�G�Ĥ@����J�p��ĤG����J
        printf("-");        //��k��X�e�A����X�t��
    }
    longOutput(subans, n); //��k��X
    longOutput(mulans, n); //���k��X
}
//---------/output----------

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
void testinput003(int longNumber1[], int longNumber2[]){
    longNumber1[8] = 1; longNumber2[8] = 4;
    longNumber1[7] = 8; longNumber2[7] = 8;
    longNumber1[6] = 6; longNumber2[6] = 4;
    longNumber1[5] = 9; longNumber2[5] = 3;
    longNumber1[4] = 7; longNumber2[4] = 1;
    longNumber1[3] = 8; longNumber2[3] = 2;
    longNumber1[2] = 4; longNumber2[2] = 2;
    longNumber1[1] = 4; longNumber2[1] = 4;
    longNumber1[0] = 8; longNumber2[0] = 4;
}
//----/test-----

int main(){
    int addans[120] = {0}, subans[120] = {0}, mulans[120] = {0};
    int longNumber1[60] = {0}, longNumber2[60] = {0};
    int inN = 0, outN = 0;
    int negative = 0;
    char inNumber[60] = " ";
    inN = 60;
    outN = 120;
    input(longNumber1, inNumber, inN);
    input(longNumber2, inNumber, inN);
    //testinput003(longNumber1, longNumber2);
    //testLongNumberOutput(longNumber1, inN);
    //testLongNumberOutput(longNumber2, inN);
    run(longNumber1, longNumber2, &negative, addans, subans, mulans, inN);
    //testLongNumberOutput(addans, outN);
    //testLongNumberOutput(subans, outN);
    //testLongNumberOutput(mulans, outN);
    output(addans, negative, subans, mulans, outN);
    return 0;
}
