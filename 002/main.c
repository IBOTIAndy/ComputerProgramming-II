#include <stdio.h>
//002 矩陣運算 Matrix_Operation
//2019/03/01 IBOTIAndy

//-----input-----
void setMatrix(int *row, int *col, int matrix[][10]){   //輸入矩陣
    int x=0, y=0;
    scanf("%d%d", row, col);                            //輸入矩陣的長寬(row and col)
    for(y = 0; y < *row; y++){                          //y -> row
        for(x = 0; x < *col; x++){                      //x -> col
            scanf("%d", &matrix[y][x]);
        }
    }
}


void input(int *row1, int *col1, int matrix1[][10], int *row2, int *col2, int matrix2[][10]){   //輸入
    setMatrix(row1, col1, matrix1); //輸入第一個矩陣
    setMatrix(row2, col2, matrix2); //輸入第二個矩陣
}
//----/input-----

//-----output-----
void output(int row, int col, int ans[][10]){
    int i=0, j=0;
    if(row == 12202 && col == 12202){
        printf("ERROR\n");
    }
    else{
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }
    }
}
//----/output-----

//-----run-----
int matrixMultiply(int y, int x, int n, int matrix1[][10], int matrix2[][10]){
    int i=0, ans=0;
    for(i=1; i <= n; i++){
        ans = ans + matrix1[y][i] * matrix2[i][x];
    }
    return ans;
}

void matrixMath(int type, int row, int col, int matrix1[][10], int matrix2[][10], int matrixans[][10]){
    int y=0, x=0;
    for(y=0; y < row; y++){
        for(x=0; x < col; x++){
            if(type == 0){
                matrixans[y][x] = matrix1[y][x] + matrix2[y][x];
            }
            else if(type == 1){
                matrixans[y][x] = matrix1[y][x] - matrix2[y][x];
            }
            //else if(type == 2){
            //    matrixans[y][x] = matrixMultiply(y, x, col, matrix1, matrix2);
            //}
        }
    }
}

void run(int row1, int col1, int matrix1[][10], int row2, int col2, int matrix2[][10]){  //
    int addans[10][10]={{0}};
    int subans[10][10]={{0}};
    int mulans[10][10]={{0}};
    int error=0;
    error = 12202;
    if(row1 == row2 && col1 == col2){
        matrixMath(0, row1, col1, matrix1, matrix2, addans);
        matrixMath(1, row1, col1, matrix1, matrix2, subans);
        output(row1, col1, addans);
        output(row1, col1, subans);
    }
    else{
        output(error, error, addans);
        output(error, error, subans);
    }
    if(col1 == row2){
        matrixMath(2, row2, col1, matrix1, matrix2, subans);
        output(row2, col1, mulans);
    }
    else{
        output(error, error, mulans);
    }
}
//----/run-----

//-----test-----
void outputM(int matrix[][10]){             //印出整個陣列[10][10]
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<10;j++){                 //一排
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void testinput(int *row1, int *col1, int matrix1[][10], int *row2, int *col2, int matrix2[][10]){   //測試資料，節省輸入時間
    //加減法測資
//    *row1 = *row2 = 4;
//    *col1 = *col2 = 3;
//    matrix1[0][0] = 2; matrix1[0][1] = 1; matrix1[0][2] = 4;
//    matrix1[1][0] = 5; matrix1[1][1] = 3; matrix1[1][2] = 9;
//    matrix1[2][0] = 3; matrix1[2][1] = 0; matrix1[2][2] = 7;
//    matrix1[3][0] = 8; matrix1[3][1] = 6; matrix1[3][2] = 3;
//    matrix2[0][0] = 8; matrix2[0][1] = 5; matrix2[0][2] = 7;
//    matrix2[1][0] = 7; matrix2[1][1] = 5; matrix2[1][2] = 3;
//    matrix2[2][0] = 8; matrix2[2][1] = 6; matrix2[2][2] = 3;
//    matrix2[3][0] = 7; matrix2[3][1] = 4; matrix2[3][2] = 2;
    //乘法測資
    *col1 = *row2 = 2;
    *row1 = 2;
    *col2 = 3;
    matrix1[0][0] = 2; matrix1[0][1] = 1;
    matrix1[1][0] = 5; matrix1[1][1] = 3;
    matrix2[0][0] = 8; matrix2[0][1] = 5; matrix2[0][2] = 7;
    matrix2[1][0] = 7; matrix2[1][1] = 5; matrix2[1][2] = 3;
    //output(*row1, *col1, matrix1);
    //output(*row2, *col2, matrix2);
}
//----/test------

int main(){
    int matrix1[10][10]={{0}};      //定義: 矩陣1
    int row1=0, col1=0;             //(行 與 列)1
    //outputM(matrix1);               //輸出矩陣1 #test
    int matrix2[10][10]={{0}};      //矩陣2
    int row2=0, col2=0;             //(行 與 列)2
    //outputM(matrix2);               //輸出矩陣2 #test
    //testinput(&row1, &col1, matrix1, &row2, &col2, matrix2);    //測試用資料，須將輸入註解
    input(&row1, &col1, matrix1, &row2, &col2, matrix2);        //輸入矩陣一、二的行列與值
    run(row1, col1, matrix1, row2, col2, matrix2);  //執行矩陣的加法 type為0
    return 0;
}
