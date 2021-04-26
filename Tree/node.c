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