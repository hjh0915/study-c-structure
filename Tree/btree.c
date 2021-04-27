#include "./node.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    BTNode * root = NULL;
    root = CreateBTree(root);

    printf("该二叉树的根节点是：%c\n", root->data);
    printf("\n前序遍历：");
    PreOrder(root);

    printf("\n中序遍历：");
    InOrder(root);

    printf("\n后序遍历：");
    PostOrder(root);

    printf("\n层次遍历: ");
    LevelOrder(root);

    DestroyBTree(root);
    return 0;
}