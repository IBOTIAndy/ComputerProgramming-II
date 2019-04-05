#include <stdio.h>
#include <stdlib.h>
//015 �ѹ����g�c
//2019/04/05 IBOTIAndy PM. 03:28

//----------input----------
void input(char map[100][100], int *n){
    int i=0, j=0;
    char c=' ';                             //�� c �ӥh���Ů�P����Ÿ�
    scanf("%d%c", n, &c);                   //��J�a�Ϫ��j�p(�����)
    for(i=0; i < *n; i++){
        for(j=0; j < *n; j++){
            scanf("%c%c", &map[i][j], &c);  //��J�a�Ϫ��ˤl
        }
    }
}
//---------/input----------

//----------run----------
int mouse(char map[100][100], int x, int y, int end){   //�ѹ�
    if(map[y][x] == '1'){       //�p�G������
        return 1;
    }
    else if(map[y][x] == '#'){  //�p�G�w�g���L�F
        return 1;
    }
    map[y][x] = '#';            //�p�G�S����]�S���L�A�������L
    if(x == end && y == end){   //�p�G����X�f
        return 0;               //����
    }
    if(mouse(map, x    , y + 1, end) == 0){ //�U
        return 0;
    }
    if(mouse(map, x    , y - 1, end) == 0){ //�W
        return 0;
    }
    if(mouse(map, x - 1, y    , end) == 0){ //��
        return 0;
    }
    if(mouse(map, x + 1, y    , end) == 0){ //�k
        return 0;
    }
    map[y][x] = '*';            //�p�G�U�W���k�����ਫ�A�O���U��
    return 1;                   //�í����^
}

void run(char map[100][100], int n){
    int x=0, y=0, end=0;
    x = 1;                  //�_�l��m�����W��
    y = 1;                  //
    end = n - 2;            //�g�c�k�U����[n-2][n-2]����m
    mouse(map, x, y, end);  //��J�ѹ�
}
//---------/run----------


//----------output----------
void output(char map[100][100], int n){ //��X��i�a��
    int i=0, j=0;
    for(i=0; i < n; i++){
        for(j=0; j < n; j++){           //��X�@��
            printf("%c ", map[i][j]);
        }
        printf("\n");                   //��X���@�� ����
    }
}
//---------/output----------


int main(){
    char map[100][100]={{'0'}};
    int n=0;
    input(map, &n);
    run(map, n);
    output(map, n);
//    printf("Hello world!\n");
    return 0;
}
