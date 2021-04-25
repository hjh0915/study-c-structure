#define QueueSize 100

typedef int DataType;
typedef struct CirQueue {
    DataType data[QueueSize];
    int front, rear;
} CirQueue;

void InitQueue(CirQueue * Q);   //初始化
int Empty(CirQueue * Q);    //判断front是否等于rear
int EnQueue(CirQueue * Q, DataType x);  //入队
int DeQueue(CirQueue * Q, DataType * ptr);  //出队
int GetHead(CirQueue * Q, DataType * ptr);  //取队头元素