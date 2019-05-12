#include <stdio.h>
#include <stdlib.h>
//022 結構(structure)練習2，邏輯閘
//2019/05/12 PM. 03:18 IBOTIAndy
//----------typedef----------
typedef struct gate_s{  //邏輯閘
    char name;          //邏輯名稱
    int x1;             //輸入1
    int x2;             //輸入2
    int y;              //輸出
}gate_t;
//---------/typedef----------

//----------input------------
void input(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate){}
//---------/input------------

//----------run--------------
void run(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate){}
//---------/run--------------

//----------output-----------
void output(gate_t P_Gate, gate_t Q_Gate, gate_t R_Gate){}
//----------output-----------

int main(){
    gate_t P_Gate, Q_Gate, R_Gate;
    input(&P_Gate, &Q_Gate, &R_Gate);
    run(&P_Gate, &Q_Gate, &R_Gate);
    output(P_Gate, Q_Gate, R_Gate);
//    printf("Hello world!\n");
    return 0;
}
