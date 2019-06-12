#include <stdio.h>
#include <stdlib.h>
//032 creat binary tree for inorder 用中序做出二元樹
//2019/06/12 PM. 02:15 IBOTIAndy
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

//-----inorder-----
void printTree(node_t *node){   //輸出
    if(node == NULL){           //如果找完了
        return;                 //回上一層
    }
    printTree(node->left);      //左
    printf("%d ", node->data);  //中
    printTree(node->right);     //右
}

void inorder(tree_t *tree){ //輸出
    if(tree->root == NULL){     //如果沒有樹
        printf("null");         //輸出 null
    }
    else{
        printTree(tree->root);  //輸出樹
    }
    printf("\n");               //輸出完換行
}
//----/inorder-----

node_t* creatNewNode(int data){
    node_t *newNode=NULL;
    newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//-----insert-----
node_t* findLeaf(node_t *currently, node_t *newNode){   //找葉節點   leaf = 葉節點
    if(currently == NULL){  //如果找到葉節點
        return newNode;     //回傳新的節點
    }
    if(newNode->data <= currently->data){   //left(newData <= nowData)  往左
        currently->left = findLeaf(currently->left, newNode);   //接收下一階回傳回來的位置
    }
    else{                                   //right(newData > nowData) 往右
        currently->right = findLeaf(currently->right, newNode); //接收下一階回傳回來的位置
    }
    return currently;   //回傳目前位置給上一次  (消除build警告)
}

int insert(tree_t *tree, node_t *newNode){  //輸入 小的放左；大的放右
    if(tree->root == NULL){         //如果這棵樹甚麼都沒有
        tree->root = newNode;       //直接將新節點給根
        return 1;                   //跳出
    }
    findLeaf(tree->root, newNode);  //找到葉節點 (遞迴)
    return 0;                       //離開
}
//----/insert-----

void run(){
    tree_t tree={NULL};
    node_t *newNode;
    char select=' ', wrap=' ';              //select = 選擇模式，wrap = 去除換行字元('\n')
    int data=0;                             //輸入的資料
    while(1){
        scanf("%c%c", &select, &wrap);      //選擇模式
        if(select == 'p'){                  //p = print
            inorder(&tree);                 //中序搜尋法 輸出
        }
        else if(select == 'i'){             //i = insert
            scanf("%d%c", &data, &wrap);    //輸入資料名稱
            newNode = creatNewNode(data);   //將資料建立成檔案
            insert(&tree, newNode);         //輸入
        }
        else if(select == 'e'){             //e = exit
            break;                          //離開無限迴圈
        }
    }
}

int main(){
    run();
//    printf("Hello world!\n");
    return 0;
}
