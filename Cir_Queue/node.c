#include <stdio.h>
#include <stdlib.h>

#include "./node.h"

//初始化队
void InitQueue(CirQueue * Q) {
    Q->front = Q->rear = 0;
}

//入队
int EnQueue(CirQueue * Q, DataType x) {
    if ((Q->rear+1)%QueueSize == Q->front) {
        printf("上溢错误，插入失败\n");
        return 0;
    } else {
        Q->rear = (Q->rear+1) % QueueSize;
        Q->data[Q->rear] = x;
        return 1;
    }
}

//出队
int DeQueue(CirQueue * Q, DataType * ptr) {
    if (Q->rear == Q->front) {
        printf("下溢错误，删除失败\n");
        return 0;
    } else {
        Q->front = (Q->front+1) % QueueSize;
        *ptr = Q->data[Q->front];
    }
}

//取队头元素
int GetHead(CirQueue * Q, DataType * ptr) {
    int i;
    if (Q->rear == Q->front) {
        printf("下溢错误，取队头失败\n");
        return 0;
    } else {
        i = (Q->front+1) % QueueSize;
        *ptr = Q->data[i];
        return 1;
    }
}