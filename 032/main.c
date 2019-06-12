#include <stdio.h>
#include <stdlib.h>
//032 creat binary tree for inorder 用中序做出二元樹
//2019/06/12 AM. 10:53 IBOTIAndy
//----------typedef----------
typedef struct node_s{
    int data;
    struct node_s *left;
    struct node_s *right;
}node_t;

typedef struct tree_s{
    node_t *root;
}tree_t;
//---------/typedef----------
void inorder(tree_t *tree){}

void insert(tree_t *tree, node_t *newNode){}

node_t* creatNewNode(int data){return NULL;}

void run(){
    tree_t tree={NULL};
    node_t *newNode;
    char select=' ', wrap=' ';
    int data=0;
    while(1){
        scanf("%c%c", &select, &wrap);
        if(select == 'p'){
            inorder(&tree);
        }
        else if(select == 'i'){
            scanf("%d%c", &data, &wrap);
            newNode = creatNewNode(data);
            insert(&tree, newNode);
        }
        else if(select == 'e'){
            break;
        }
    }
}

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
