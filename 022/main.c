#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//022 結構(structure)練習2，邏輯閘
//2019/05/12 PM. 06:27 IBOTIAndy
//----------typedef----------
typedef struct gate_s{  //邏輯閘
    char name;          //邏輯名稱
    int x1;             //輸入1
    int x2;             //輸入2
    int y;              //輸出
}gate_t;
//---------/typedef----------

//----------input------------
void setGate(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate, int x[], char type[]){
    P_Gate->name = type[0];
    P_Gate->x1 = P_Gate->x2 = x[0];
    Q_Gate->name = type[1];
    Q_Gate->x1 = x[1];
    R_Gate->name = type[2];
    R_Gate->x1 = x[2];
}

int changeType(char cut[]){
    int ans=0, i=0;
    while(cut[i] != '\0'){
        ans = (ans * 10) + (cut[i] - '0');
        i = i + 1;
    }
    return ans;
}

void input(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate){
    int i=0;
    int x[3]={0};
    char type[3]={' '};
    char in[10]="";
    char *cut;
    gets(in);
    cut = strtok(in, ",");
    while(cut != NULL){
        x[i] = changeType(cut);
        cut = strtok(NULL, ",");
        i = i + 1;
    }
//    printf("%d %d %d\n", x[0], x[1], x[2]);
    gets(in);
    i = 0;
    cut = strtok(in, ",");
    while(cut != NULL){
        type[i] = cut[0];
        cut = strtok(NULL, ",");
        i = i + 1;
    }
//    printf("%c %c %c\n", type[0], type[1], type[2]);
    setGate(P_Gate, Q_Gate, R_Gate, x, type);
}

void inputView(gate_t P_Gate, gate_t Q_Gate, gate_t R_Gate){
    printf("P_Gate->%c: x1=%d, x2=%d\n", P_Gate.name, P_Gate.x1, P_Gate.x2);
    printf("Q_Gate->%c: x1=%d, x2=%d\n", Q_Gate.name, Q_Gate.x1, Q_Gate.x2);
    printf("R_Gate->%c: x1=%d, x2=%d\n", R_Gate.name, R_Gate.x1, R_Gate.x2);
}
//---------/input------------

//----------run--------------
void run(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate){}
//---------/run--------------

//----------output-----------
void output(gate_t P_Gate, gate_t Q_Gate, gate_t R_Gate){}
//----------output-----------

int main(){
    gate_t P_Gate={' ', -1, -1, -1};
    gate_t Q_Gate={' ', -1, -1, -1};
    gate_t R_Gate={' ', -1, -1, -1};
    input(&P_Gate, &Q_Gate, &R_Gate);
//    inputView(P_Gate, Q_Gate, R_Gate);
    run(&P_Gate, &Q_Gate, &R_Gate);
    output(P_Gate, Q_Gate, R_Gate);
//    printf("Hello world!\n");
    return 0;
}
