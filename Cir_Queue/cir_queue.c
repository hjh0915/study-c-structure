#include "./node.h"
#include <stdio.h>

int main() {
    DataType x;
    CirQueue Q;
    InitQueue(&Q);

    printf("对15, 10, 5进行入队操作, ");
    EnQueue(&Q, 15);
    EnQueue(&Q, 10);
    EnQueue(&Q, 5);

    if (GetHead(&Q, &x) == 1) {
        printf("当前队头元素为：%d\n", x);
    }

    if (DeQueue(&Q, &x) == 1) {
        printf("出队一次，出队元素为：%d\n", x);
    }

    if (GetHead(&Q, &x) == 1) {
        printf("当前队头元素为：%d\n", x);
    }
}