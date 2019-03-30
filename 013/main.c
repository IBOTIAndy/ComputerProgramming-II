#include <stdio.h>
#include <stdlib.h>
//013 �g���D
//2019/03/30 PM.10:38 IBOTIAndy
typedef struct snake{   //�D�����c�A�|�����ڪ���V��
    int body[2];        //�ثe��m���y��
    int size;           //�D������
    int facing;         //�D�Y���諸��V�A�@�}�l�� �k(4)
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
        scanf("%d %d", &y, &x);     //��J���G���y�СA���W���� (0,0) (x,y)
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
        printf("%d %d\n", now->body[1], now->body[0]);  //��X�y��  ����X y�b �A��X x�b
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
void findNext(snake *head, int next, int *x, int *y){   //���U�@�Ӧ�m
    *x = head->body[0];     //�����o�Y����m
    *y = head->body[1];     //
    if(next == 1){      //�W
        *y = *y - 1;    //y ���W�@�� -1
    }
    else if(next == 2){ //�U
        *y = *y + 1;    //y ���U�@�� +1
    }
    else if(next == 3){ //��
        *x = *x - 1;    //x �����@�� -1
    }
    else if(next == 4){ //�k
        *x = *x + 1;    //x ���k�@�� +1
    }
}

//---Gameover---
int bumpBody(snake *now, int x, int y){         //���쨭��A���j  ���y����P�_���S���Q����
    if(now->body[0] == x && now->body[1] == y){ //�p�G���쨭��
        return 1;                               //
    }
    else if(now->tail == NULL){                 //�p�G����ڤF
        return 0;                               //
    }
    else{                                       //����S�Q����
        return bumpBody(now->tail, x, y);       //���U�@�Ӧ�m��
    }
}

int isGameOver(char map[20][20], snake *head, int x, int y){    //�C������
    if(map[x][y] == '1'){               //�p�G�������
        return 1;                       //�����C��
    }
    else if(map[x][y] == '#'){          //�p�G�Y����G
        return 0;                       //���|�����C��
    }
    else{                               //�S������]�S�Y����G
        return bumpBody(head, x, y);    //�P�_�O���O���쨭��  ����^��1 �����C��
    }
}
//--/Gameover---

//---snakeMove---
void move(int xy[2], int x, int y){ //�N���ڲ��V����A���鲾�V�Y...
    xy[0] = x;
    xy[1] = y;
}

void moveRecursuvely(snake *now, int x, int y){                 //�D���e����
    if(now->tail != NULL){                                      //�p�G�٨S�����
        moveRecursuvely(now->tail, now->body[0], now->body[1]); //�����ڪ���m�a�J
    }
    move(now->body, x, y);                                      //�N�᭱������Χ��ک��e�����@��
}
//--/snakeMove---

//---eatFruit---
int eatFruit(char map[20][20], int x, int y){   //�Y����G�F��
    if(map[x][y] == '#'){   //�Y����G�F
        map[x][y] = '0';    //�N���G�Y��
        return 1;
    }
    return 0;
}

void growingUp(snake *now){ //�Y����G  ����  #���j
    now->size = now->size + 1;                          //���j size +1
    if(now->tail == NULL){                              //�p�G�����ڤF
        snake *tail = malloc(sizeof(snake));            //�s�W�@��snake
        move(tail->body, now->body[0], now->body[1]);   //�N���ڪ���m���s������
        tail->size = 1;                                 //��l��
        tail->facing = 4;                               //��l��
        tail->tail = NULL;                              //��l�� ���VNULL
//        printf("{%d, %d}\n", tail->body[0], tail->body[1]);
        now->tail = tail;                               //�ª����ڦ������� ���V�s����
    }
    else{                                               //�p�G�٨S������
        growingUp(now->tail);                           //�����ګ�
    }
}
//--/eatFruit---
//----/game-----

void run(char map[20][20], snake *head){
    int next=0, nextX=0, nextY=0;
    mapReset(map);          //���m�a��
//    testOutputMap(map, 20); //��X�a�� (���ե�)
    inputFruits(map);       //��J���G
//    testOutputMap(map, 20); //��X�a�� (���ե�)
    scanf("%d", &next);     //�Ĥ@����J
    while(next != -1){              //�p�G��������
        if(next == 0){              //�L�X�D�����׻P�y��
            printSnake(head);       //��X�D����m
        }
        else if(next == 5){         //�p�G�n�e�i
            findNext(head, head->facing, &nextX, &nextY);   //���D�n�����U�@��y��
            if(isGameOver(map, head, nextX, nextY)){        //�p�G������Φۤv�A�C������
//                printf("Gameover~\n");
                break;                                      //���X�j��
            }
            else if(eatFruit(map, nextX, nextY)){           //�S�Y����G
                growingUp(head);                            //�[����
            }
            moveRecursuvely(head, nextX, nextY);            //����  ���j����ڡA�q���ڶ}�l���Y����
        }
        else{                       //��ثe�������V
            head->facing = next;    //���ܳD�Y���V����m
        }
        scanf("%d", &next);         //���ƿ�J
    }
    printSnake(head);       //��X�D����m
}
//---------/run----------

int main(){
    snake head={{9, 9}, 1, 4, NULL};
    char map[20][20]={{' '}};
    run(map, &head);
    return 0;
}
