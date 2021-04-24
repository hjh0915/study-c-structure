#include "./node.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 初始化链栈
void InitStack(Node * top) {
    top = NULL;
}

// int Empty(Node * top) {
//     if (top == NULL) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// 销毁链栈
// void DestroyStack(Node * top) {
//     Node *p = top;
//     while (top != NULL) {
//         top = top->next;
//         free(p);
//         p = top;
//     }
// }

// 入栈
void Push(Node * top, DataType x) {
    Node * s = (Node *)malloc(sizeof(Node));    // 分配结点存储
    s->data = x;
    s->next = top;
    top = s;
}

// 出栈
// int Pop(Node * top, DataType * ptr) {
//     Node * p = top;
//     if (top == NULL) {
//         printf("下溢错误，删除失败\n");
//         return 0;
//     } else {
//         *ptr = top->data;   // 存储栈顶元素
//         top = top->next;    // 摘链
//         free(p);
//         return 1;
//     }
// }

// // 取栈顶元素
// int GetTop(Node * top, DataType * ptr) {
//     if (top == NULL) {
//         printf("下溢错误，取栈顶失败\n");
//         return 0;
//     } else {
//         *ptr = top->data;
//         return 1;
//     }
// }