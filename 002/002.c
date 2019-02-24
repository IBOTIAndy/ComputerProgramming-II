#include <stdio.h>
void outputM(int matrix[][10]){             //印出整個陣列[10][10]
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<10;j++){                 //一排
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void setMatrix(int *row, int *col, int matrix[][10]){   //輸入矩陣
    //printf("setMOK\n");
    int x=0, y=0;
    //printf("set x and y OK:%d,%d\n", x, y);
    scanf("%d%d", row, col);                            //輸入矩陣的長寬(row and col)
    //outputM(matrix);
    //printf("input:row=%d,col=%d\n", *row, *col);
    for(y = 0; y < *row; y++){                          //y -> row
        //printf("in for y:y=%d, row=%d\n", y, *row);
        for(x = 0; x < *col; x++){                      //x -> col
            scanf("%d", &matrix[y][x]);
            //printf("in for x:x=%d, row=%d, mat[%d][%d]=%d\n", x, *col, y, x, matrix[y][x]);
        }
        //printf("for(x) end\n");
        //outputM(matrix);
    }
    //printf("for(y) end\n");
}


void input(int *row1, int *col1, int matrix1[][10], int *row2, int *col2, int matrix2[][10]){   //輸入
    //printf("inputok\n");
    //outputM(matrix1);
    setMatrix(row1, col1, matrix1); //輸入第一個矩陣
    //printf("setM1OK:%d,%d\n", *row1, *col1);
    setMatrix(row2, col2, matrix2); //輸入第二個矩陣
    //printf("setM2OK:%d,%d\n", *row2, *col2);
}

void output(int row, int col, int ans[][10]){
    int i=0, j=0;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void run(int type, int row, int col, int matrix1[][10], int matrix2[][10], int ans[][10]){  //
    //使用type來判斷要使用+,-還是*
    int y=0,x=0;
    for(y = 0; y < row; y++){
        for(x = 0; x < col; x++){
            if(type == 0){
                ans[y][x] = matrix1[y][x] + matrix2[y][x];
            }
            else if(type == 1){
                ans[y][x] = matrix1[y][x] - matrix2[y][x];
            }
            else if(type == 2){
                ans[y][x] = matrix1[y][x] * matrix2[y][x];
            }
        }
    }
}

void testinput(int *row1, int *col1, int matrix1[][10], int *row2, int *col2, int matrix2[][10]){   //測試資料，節省輸入時間
    *row1 = *row2 = 4;
    *col1 = *col2 = 3;
    matrix1[0][0] = 2; matrix1[0][1] = 1; matrix1[0][2] = 4;
    matrix1[1][0] = 5; matrix1[1][1] = 3; matrix1[1][2] = 9;
    matrix1[2][0] = 3; matrix1[2][1] = 0; matrix1[2][2] = 7;
    matrix1[3][0] = 8; matrix1[3][1] = 6; matrix1[3][2] = 3;
    matrix2[0][0] = 8; matrix2[0][1] = 5; matrix2[0][2] = 7;
    matrix2[1][0] = 7; matrix2[1][1] = 5; matrix2[1][2] = 3;
    matrix2[2][0] = 8; matrix2[2][1] = 6; matrix2[2][2] = 3;
    matrix2[3][0] = 7; matrix2[3][1] = 4; matrix2[3][2] = 2;
    output(*row1, *col1, matrix1);
    output(*row2, *col2, matrix2);
}

int specificSize(number1, number2){
    if(number1 >= number2){
        return number1;
    }
    else{
        return number2;
    }
}

void main(){
    int matrix1[10][10]={0};    //定義: 矩陣1
    int row1=0, col1=0;         //(行 與 列)1
    //outputM(matrix1);           //輸出矩陣1 #test
    int matrix2[10][10]={0};    //矩陣2
    int row2=0, col2=0;         //(行 與 列)2
    //outputM(matrix2);           //輸出矩陣2 #test
    int ans[10][10]={0};        //答案儲存
    int row=0, col=0;           //最大的範圍
    //testinput(&row1, &col1, matrix1, &row2, &col2, matrix2);    //測試用資料，須將輸入註解
    input(&row1, &col1, matrix1, &row2, &col2, matrix2);    //輸入矩陣一、二的行列與值
    run(0, row, col, matrix1, matrix2, ans);    //執行矩陣的加法 type為0
    output(row ,col ,ans);                      //輸出加法結果
    run(1, row, col, matrix1, matrix2, ans);    //執行矩陣的減法 type為1
    output(row ,col ,ans);                      //輸出減法結果
    //run(2, row1, col1, matrix1, matrix2, ans);  //執行矩陣的乘法 type為2
    //output(row1 ,col1 ,ans);                    //輸出乘法結果
    printf("ERROR\n");
}
