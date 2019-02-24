#include <stdio.h>
void outputM(int matrix[][10]){             //�L�X��Ӱ}�C[10][10]
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<10;j++){                 //�@��
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void setMatrix(int *row, int *col, int matrix[][10]){   //��J�x�}
    //printf("setMOK\n");
    int x=0, y=0;
    //printf("set x and y OK:%d,%d\n", x, y);
    scanf("%d%d", row, col);                            //��J�x�}�����e(row and col)
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


void input(int *row1, int *col1, int matrix1[][10], int *row2, int *col2, int matrix2[][10]){   //��J
    //printf("inputok\n");
    //outputM(matrix1);
    setMatrix(row1, col1, matrix1); //��J�Ĥ@�ӯx�}
    //printf("setM1OK:%d,%d\n", *row1, *col1);
    setMatrix(row2, col2, matrix2); //��J�ĤG�ӯx�}
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
    //�ϥ�type�ӧP�_�n�ϥ�+,-�٬O*
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

void testinput(int *row1, int *col1, int matrix1[][10], int *row2, int *col2, int matrix2[][10]){   //���ո�ơA�`�ٿ�J�ɶ�
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
    int matrix1[10][10]={0};    //�w�q: �x�}1
    int row1=0, col1=0;         //(�� �P �C)1
    //outputM(matrix1);           //��X�x�}1 #test
    int matrix2[10][10]={0};    //�x�}2
    int row2=0, col2=0;         //(�� �P �C)2
    //outputM(matrix2);           //��X�x�}2 #test
    int ans[10][10]={0};        //�����x�s
    int row=0, col=0;           //�̤j���d��
    //testinput(&row1, &col1, matrix1, &row2, &col2, matrix2);    //���եθ�ơA���N��J����
    input(&row1, &col1, matrix1, &row2, &col2, matrix2);    //��J�x�}�@�B�G����C�P��
    run(0, row, col, matrix1, matrix2, ans);    //����x�}���[�k type��0
    output(row ,col ,ans);                      //��X�[�k���G
    run(1, row, col, matrix1, matrix2, ans);    //����x�}����k type��1
    output(row ,col ,ans);                      //��X��k���G
    //run(2, row1, col1, matrix1, matrix2, ans);  //����x�}�����k type��2
    //output(row1 ,col1 ,ans);                    //��X���k���G
    printf("ERROR\n");
}
