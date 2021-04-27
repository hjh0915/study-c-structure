#include "./node.h"
#include <stdio.h>
#include <stdlib.h>


// 建立二叉树
BTNode * CreateBTree(BTNode * root) {
    char ch;
	scanf("%c",&ch);
    if (ch == '#') {
        root = NULL;
    } else {
        root = (BTNode *)malloc(sizeof(BTNode));
        root->data = ch;
        root->lchild = CreateBTree(root->lchild);
        root->rchild = CreateBTree(root->rchild);
    }

    return root;
}

// 前序遍历
void PreOrder(BTNode * root) {
    if (root == NULL) {
        return;
    } else {
        printf("%c ", root->data);  //根
        PreOrder(root->lchild);     //左子树
        PreOrder(root->rchild);      //右子树
    }
}

// 中序遍历
void InOrder(BTNode * root) {
    if (root == NULL) {
        return;
    } else {
        InOrder(root->lchild);      //左子树
        printf("%c ", root->data);  //根
        InOrder(root->rchild);      //右子树
    }
}

// 后序遍历
void PostOrder(BTNode * root) {
    if (root == NULL) {
        return;
    } else {
        PostOrder(root->lchild);    //左子树
        PostOrder(root->rchild);    //右子树
        printf("%c ", root->data);  //根
    }
}


Queue Q;

void initilize() { //初始化队列
    Q.front = 0;
    Q.rear = 0;
}
 
void Push(struct BTNode * root) { //入队
    Q.numQ[++Q.rear] = root;
}
 
struct BTNode * Pop() { //出队
    return Q.numQ[++Q.front];
}
 
int empty() { //判断对列是否为空
    return Q.rear == Q.front;
}

// 层次遍历，求二叉树的最大宽度
void LevelOrder(BTNode * root) {
    // BTNode *q = NULL, *Q[MaxSize];
    // int front, rear = -1;      // 初始化
    // if(root == NULL) {
    //     return;
    // } else {
    //     // rear++;
    //     Q[++rear] = root;     // 根指针入队
        
    //     while (front != rear) {
    //         // front++;
    //         q = Q[++front];   //出队
    //         printf("%c", q->data);
    //         if (q->lchild != NULL) {
    //             // rear++;
    //             Q[++rear] = q->lchild;
    //         }
    //         if (q->rchild != NULL) {
    //             // rear++;
    //             Q[++rear] = q->rchild;
    //         }
    //     }
    // }

    struct BTNode * temp;
    Push(root);
    while (!empty()) {
        temp = Pop();
        printf("%c ", temp->data);  //输出队首结点
        if (temp->lchild)     //把Pop掉的结点的左子结点加入队列
            Push(temp->lchild);
        if (temp->rchild)    //把Pop掉的结点的右子结点加入队列
            Push(temp->rchild);
    }
}

// 销毁
void DestroyBTree(BTNode * root) {
    if (root == NULL) {
        return;
    } else {
        DestroyBTree(root->lchild);
        DestroyBTree(root->rchild);
        free(root);
    }
}