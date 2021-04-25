typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *next;
} Node;

typedef struct LinkStack {
    struct Node * top;
} LinkStack;

void InitStack(LinkStack * S);   //初始化链栈
int Empty(LinkStack * S);       //判断top是否为NULL
void DestroyStack(LinkStack * S);  //销毁链栈
int Push(LinkStack * S, DataType x);     //入栈
int Pop(LinkStack * S, DataType * ptr);  //出栈
int GetTop(LinkStack * S, DataType * ptr);   //取栈顶元素