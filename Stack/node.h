#define MaxSize 100

typedef int DataType;
typedef struct SeqStack {
    DataType data[MaxSize];
    int top;
} SeqStack;

void InitStack(SeqStack * S);   //初始化顺序栈
int Empty(SeqStack * S);       //判断top是否为-1
int Push(SeqStack * S, DataType x);     //入栈
int Pop(SeqStack * S, DataType * ptr);  //出栈
int GetTop(SeqStack * S, DataType * ptr);   //取栈顶元素