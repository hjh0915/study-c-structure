#include "./node.h"

#include <stdio.h>
#include <stdlib.h>

// 初始化链栈
void InitStack(LinkStack * S) {
    S->top = NULL;
}

int Empty(LinkStack * S) {
    if (S->top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// 销毁链栈
void DestroyStack(LinkStack * S) {
    Node *p = S->top;
    while (S->top != NULL) {
        S->top = S->top->next;
        free(p);
        p = S->top;
    }
}

// 入栈
int Push(LinkStack * S, DataType x) {
    Node * temp;
    temp = (Node *)malloc(sizeof(Node));    // 分配结点存储
    if (temp == NULL) {
        return 0;
    } else {
        temp->data = x;
        temp->next = S->top;
        S->top = temp;

        return 1;
    }
}

// 出栈
int Pop(LinkStack * S, DataType * ptr) {
    Node * p = S->top;
    if (S->top == NULL) {
        printf("下溢错误，删除失败\n");
        return 0;
    } else {
        *ptr = S->top->data;   // 存储栈顶元素
        S->top = S->top->next;    // 摘链
        free(p);
        return 1;
    }
}

// 取栈顶元素
int GetTop(LinkStack * S, DataType * ptr) {
    if (S->top == NULL) {
        printf("下溢错误，取栈顶失败\n");
        return 0;
    } else {
        *ptr = S->top->data;
        return 1;
    }
}