#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//022 結構(structure)練習2，邏輯閘
//2019/05/12 PM. 08:57 IBOTIAndy
//----------typedef----------
typedef struct gate_s{  //邏輯閘
    char name;          //邏輯名稱
    int x1;             //輸入1
    int x2;             //輸入2
    int y;              //輸出
}gate_t;
//---------/typedef----------

//----------input------------
void setGate(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate, int x[], char type[]){ //設定邏輯閘
    P_Gate->name = type[0];         //
    P_Gate->x1 = P_Gate->x2 = x[0]; //
    Q_Gate->name = type[1];         //
    Q_Gate->x1 = x[1];              //
    R_Gate->name = type[2];         //
    R_Gate->x1 = x[2];              //
}

int changeType(char cut[]){ //將字串改為整數
    int ans=0, i=0;
    while(cut[i] != '\0'){                  //直到字串找完
        ans = (ans * 10) + (cut[i] - '0');  //轉為整數
        i = i + 1;
    }
    return ans; //回傳答案
}

void input(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate){ //輸入
    int i=0;
    int x[3]={0};
    char type[3]={' '};
    char in[10]="";
    char *cut;
    gets(in);       //輸入三個 x -----取得輸入--------
    cut = strtok(in, ",");          //切割
    while(cut != NULL){             //直到切割完
        x[i] = changeType(cut);     //將字串轉為整數
        cut = strtok(NULL, ",");    //再繼續切割
        i = i + 1;
    }
//    printf("%d %d %d\n", x[0], x[1], x[2]);     //----
    gets(in);   //輸入三個邏輯閘的狀態----取得輸入------------
    i = 0;                              //將 i 重置為 1
    cut = strtok(in, ",");              //切割
    while(cut != NULL){                 //直到切割完
        type[i] = cut[0];               //記錄下狀態
        cut = strtok(NULL, ",");        //再繼續切割
        i = i + 1;
    }
//    printf("%c %c %c\n", type[0], type[1], type[2]);    //----
    setGate(P_Gate, Q_Gate, R_Gate, x, type);   //設定邏輯閘
}

void inputView(gate_t P_Gate, gate_t Q_Gate, gate_t R_Gate){    //檢查輸入有沒有錯誤
    printf("P_Gate->%c: x1=%d, x2=%d\n", P_Gate.name, P_Gate.x1, P_Gate.x2);
    printf("Q_Gate->%c: x1=%d, x2=%d\n", Q_Gate.name, Q_Gate.x1, Q_Gate.x2);
    printf("R_Gate->%c: x1=%d, x2=%d\n", R_Gate.name, R_Gate.x1, R_Gate.x2);
}
//---------/input------------

//----------run--------------
int notGate(gate_t *gate){      //NOT閘判斷
    if(gate->name == 'E'){      //如果沒有NOT閘
        return gate->x1;        //直接通過
    }
    else if(gate->name == 'N'){ //如果有NOT閘
        if(gate->x1 == 1){      //如果是 1
            return 0;           //改為 0
        }
        else if(gate->x1 == 0){ //如果是 0
            return 1;           //改為 1
        }
    }
    return -1;
}

int andorGate(gate_t *gate){        //及閘 與 或閘
    if(gate->name == 'A'){          //及閘
        if(gate->x1 == gate->x2){   //兩個相等-> 1 1 = 1, 0 0 = 0
            return gate->x1;        //
        }
        else{                       //兩個不相等-> AND = 0
            return 0;               //
        }
    }
    else if(gate->name == 'O'){     //或閘
        if(gate->x1 == gate->x2){   //兩個相等-> 1 1 = 1, 0 0 = 0
            return gate->x1;        //
        }
        else{                       //兩個不相等-> OR = 1
            return 1;               //
        }
    }
    return -1;
}

void run(gate_t *P_Gate, gate_t *Q_Gate, gate_t *R_Gate){   //運算
    P_Gate->y = notGate(P_Gate);    //反閘
//    printf("%d\n", P_Gate->y);
    Q_Gate->x2 = P_Gate->y;         //P 的結果再跟Q閘判斷
    Q_Gate->y = andorGate(Q_Gate);  //
//    printf("%d\n", Q_Gate->y);
    R_Gate->x2 = Q_Gate->y;         //Q 的結果再跟R閘判斷
    R_Gate->y = andorGate(R_Gate);  //
//    printf("%d\n", R_Gate->y);
}
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
