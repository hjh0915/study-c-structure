#include <stdio.h>
#include <stdlib.h>
#include "./node.h"

// 初始化顺序栈
void InitStack(SeqStack * S) {
    // S = malloc(sizeof(SeqStack));
    S->top = -1;
}

// 判断栈是否为空
int Empty(SeqStack * S) {
    if (S->top == -1) {
        return 1;
    } else {
        return 0;
    }
    // return (S->top == -1 ? 1: 0);
}

// 入栈
int Push(SeqStack * S, DataType x) {
    if (S->top == MaxSize-1) {
        printf("上溢错误，插入失败\n");
        return 0;
    } else {
        // S->data[(S->top)++] = x;  //top栈顶位置先+1,再在top处压入x
        // S->top = S->top + 1;
        S->top++;
        S->data[S->top] = x;
        return 1;
    }
}

//出栈
int Pop(SeqStack * S, DataType * ptr) {
    if (S->top == -1) {
        printf("下溢错误，删除失败\n");
        return 0;
    } else {
        // *ptr = S->data[S->top--];
        *ptr = S->data[S->top];
        S->top--;
        return 1;
    }
}

// 取栈顶元素
int GetTop(SeqStack * S, DataType * ptr) {
    if(S->top == -1) {
        printf("下溢错误，取栈顶失败\n");
        return 0;
    } else {
        *ptr = S->data[S->top];
        return 1;
    }
}