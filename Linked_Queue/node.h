typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node * next;
} Node;

typedef struct LinkQueue {
    Node *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue * Q);  //初始化
int Empty(LinkQueue * Q);   //判断front是否等于rear
int EnQueue(LinkQueue * Q, DataType x);  //入队
int DeQueue(LinkQueue * Q, DataType * ptr);  //出队
int GetHead(LinkQueue * Q, DataType * ptr);  //取队头元素
void DestroyQueue(LinkQueue * Q);   //销毁