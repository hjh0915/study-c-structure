#include "./node.h"
#include <stdio.h>

int main() {
    // DataType x;
    Node * top = NULL;
    // InitStack(top);

    printf("对15进行入栈操作，");
    Push(top, 15);
    printf("%d", top->data);

    // Push(top, 10);
    // Push(top, 5);

    // int a[3];
    // for(int i=0; i<3; i++) {
    //     a[i] = top->data;
    // }
    // for (int j=0; j<3; j++) {
    //     printf("%d ", a[j]);
    // }

    // if (GetTop(top, &x) == 1) {
    //     printf("当前栈顶为：%d\n", x);
    // }

    // if (Pop(top, &x) == 1) {
    //     printf("出栈一次，删除元素：%d\n", x);
    // }

    // if (GetTop(top, &x) == 1) {
    //     printf("取出当前栈顶为：%d\n", x);
    // }

    // DestroyStack(top);
    return 0;
}