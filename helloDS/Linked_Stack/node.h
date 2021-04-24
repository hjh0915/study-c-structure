typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *next;
} Node;

// void InitStack(Node * top);   //初始化链栈
// int Empty(Node * top);       //判断top是否为NULL
// void DestroyStack(Node * top);  //销毁链栈
void Push(Node * top, DataType x);     //入栈
// int Pop(Node * top, DataType * ptr);  //出栈
// int GetTop(Node * top, DataType * ptr);   //取栈顶元素