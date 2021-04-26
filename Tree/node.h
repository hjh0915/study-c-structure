typedef char DataType;

typedef struct BTNode {
    DataType data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

BTNode * CreateBTree(BTNode * root);    //建立二叉树
void PreOrder(BTNode * root);   //前序遍历
void InOrder(BTNode * root);    //中序遍历
void PostOrder(BTNode * root);  //后序遍历
// void LevelOrder(BTNode * root); //层序遍历
void DestroyBTree(BTNode * root);   //销毁