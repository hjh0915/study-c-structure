#define MaxSize 100

typedef char DataType;

typedef struct BTNode {
    DataType data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

typedef struct Queue{
    struct BTNode* numQ[MaxSize];
    int front;
    int rear;
}Queue;

BTNode * CreateBTree(BTNode * root);    //建立二叉树
void PreOrder(BTNode * root);   //前序遍历
void InOrder(BTNode * root);    //中序遍历
void PostOrder(BTNode * root);  //后序遍历
void LevelOrder(BTNode * root); //层序遍历
void DestroyBTree(BTNode * root);   //销毁

void initilize();   //初始化队列
void Push(struct BTNode * root);   //入队
struct BTNode * Pop(); //出队
int empty();    //判断对列是否为空