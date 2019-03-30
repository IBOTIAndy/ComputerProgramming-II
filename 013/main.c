#include <stdio.h>

//013 �g���D
//2019/03/30 PM.03:30 IBOTIAndy
typedef struct snake{   //�D�����c�A�|�����ڪ���V��
    int body[2];        //�ثe��m���y��
    int size;           //�D������
    struct snake *tail; //�����ڪ���V��
}snake;

//----------test----------
void testOutputMap(char map[20][20], int n){    //��X��i�a�� (�Ŧa�P���G��m)
    int x=0, y=0;
    for(x=0; x < n; x++){
        for(y=0; y < n; y++){
            printf("%c ", map[x][y]);
        }
        printf("\n");
    }
}
//---------/test----------

//----------run----------

//-----input-----
void inputFruits(char map[20][20]){ //��J���G����m
    int i=0, n=0, x=0, y=0;         //
    scanf("%d", &n);                //��J���G�ƶq (0 ~ 10)
    for(i=0; i < n; i++){           //����Ҧ����G����J�F
        scanf("%d %d", &x, &y);     //��J���G���y�СA���W���� (0,0) (x,y)
        map[x][y] = '#';            //'#' �N����G
    }
}
//----/input-----

//-----output-----
void printSnake(snake *head){   //��X�D�����׻P�y��
    int i=0;                                            //
    snake *now = head;                                  //�s�W�@�ӫ��Шө��D�����ګ�
    printf("%d\n", head->size);                         //��X�D������
    for(i=0; i < head->size; i++){                      //��X���� = ����
        printf("%d %d\n", now->body[0], now->body[1]);  //��X�y��
        now = now->tail;                                //���V�U�@�Ө����m
    }
}
//----/output-----

//-----map-----
void mapReset(char map[20][20]){        //�a�ϭ��m
    int x=0, y=0, n=0;
    n = 20;
    for(x=0; x < n; x++){               //���y��Ӧa��(x)
        for(y=0; y < n; y++){           //���y��Ӧa��(y)
            if(x == 0 || x == 19){      //�p�G�O�b��u
                map[x][y] = '1';        //�]�w�����
            }
            else if(y == 0 || y == 19){ //�p�G�O�b��u
                map[x][y] = '1';        //�]�w�����
            }
            else{                       //�p�G���O��u
                map[x][y] = '0';        //�]�w���Ŧa
            }
        }
    }
}
//----/map-----

//-----game-----
int isGameOver(char map[20][20], snake *head, int next){return 0;}

int eatFruit(char map[20][20], snake *head, int next){return 0;}

void growingUp(snake *head){}

void move(snake *head){}
//----/game-----

void run(char map[20][20], snake *head){
    int next=0;
    next = 4;               //��l��V���k
    mapReset(map);          //���m�a��
    testOutputMap(map, 20); //��X�a�� (���ե�)
    inputFruits(map);       //��J���G
    testOutputMap(map, 20); //��X�a�� (���ե�)
    scanf("%d", &next);     //�Ĥ@����J
    while(next != -1){                      //�p�G��������
        if(next == 0){                      //�L�X�D�����׻P�y��
            printSnake(head);
        }
        if(isGameOver(map, head, next)){    //�p�G������Φۤv�A�C������
            break;
        }
        else if(eatFruit(map, head, next)){ //�Y����G
            growingUp(head);                //�[����
        }
        else{                               //����
            move(head);
        }
        scanf("%d", &next);                 //���ƿ�J
    }
}
//---------/run----------

int main(){
    snake head={{9, 9}, 1, NULL};
    char map[20][20]={{' '}};
    run(map, &head);
    return 0;
}
