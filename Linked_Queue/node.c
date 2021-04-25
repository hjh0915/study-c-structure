#include "./node.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化链队
void InitQueue(LinkQueue * Q) {
    Node * s = (Node *)malloc(sizeof(Node));
    s->next = NULL;
    Q->front = Q->rear = s;
}

// 判断front是否等于rear
int Empty(LinkQueue * Q) {
    if (Q->rear == Q->front) {
        return 1;
    } else {
        return 0;
    }
}

// 入队
int EnQueue(LinkQueue * Q, DataType x) {
    Node * s = (Node *)malloc(sizeof(Node));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;    //指向新结点
    
    return 1;
}

// 出队
int DeQueue(LinkQueue * Q, DataType * ptr) {
    Node * p;
    if (Q->rear == Q->front) {
        printf("下溢错误，删除失败\n");
        return 0; 
    } else {
        p = Q->front->next;
        *ptr = p->data;
        Q->front->next = p->next;

        if (p->next == NULL) {
            Q->rear = Q->front;
        }

        free(p);
        return 1;
    }
}

// 取队头元素
int GetHead(LinkQueue * Q, DataType * ptr) {
    Node * p = NULL;
    if (Q->rear == Q->front) {
        printf("下溢错误，取队头失败\n");
        return 0;
    } else {
        p = Q->front->next;
        *ptr = p->data;
        return 1;
    }
}

// 销毁
void DestroyQueue(LinkQueue * Q) {
    Node * p = Q->front;
    Node *temp;
    while (p != NULL) {
        temp = p->next;
        free(p);
        p = temp;
    }
}