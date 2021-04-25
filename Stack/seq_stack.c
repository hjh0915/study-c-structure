#include "./node.h"
#include <stdio.h>

int main() {
    DataType x;
    SeqStack S;
    InitStack(&S);
    printf("对15, 10, 5进行入栈操作，");
    Push(&S, 15);
    Push(&S, 10);
    Push(&S, 5);
    if (GetTop(&S, &x) == 1) {
        printf("当前栈顶为：%d\n", x);
    }

    if(Pop(&S, &x) == 1) {
        printf("出栈一次，删除元素：%d\n", x);
    }

    if (GetTop(&S, &x) == 1) {
        printf("取出当前栈顶为：%d\n", x);
    }
}