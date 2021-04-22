#include <stdlib.h>
#include <stdio.h>

#include "./node.h"

// 初始化一个链表
Node * InitList() {
    Node * first = (Node *)malloc(sizeof(Node));
    first->next = NULL;
    return first;
}

//判断链表是否只有头节点
int Empty(Node * first) {
    if (first->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// 遍历链表
void PrintList(Node * first) {
    Node * p = first->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 链表的长度
int Length(Node * first) {
    Node * p = first->next;
    int count = 0;
    while (p != NULL) {
        p = p->next;
        count++;
    }

    return count;
}

// 按值查找
int Locate(Node * first, DataType x) {
    Node * p = first->next;
    int count = 1;
    while (p != NULL) {
        if (p->data == x) return count;
        p = p->next;
        count++;
    }

    return 0;
}

// 按位查找
int Get(Node * first, int i, DataType * ptr) {
    Node * p = first->next;
    int count = 1;
    while (p != NULL && count < i) {
        p = p->next;
        count++;
    }
    if (p == NULL) {
        printf("位置错误，查找失败\n");
        return 0;
    } else {
        * ptr = p->data;
        return 1;
    }
};

// 链表中间插入
int Insert(Node * first, int i, DataType x) {
    Node * s = NULL;
    Node * p = first;
    int count = 0;

    while (p != NULL && count < i-1) {
        p = p->next;
        count++;
    }

    if (p == NULL) {
        printf("位置错误，插入失败\n");
        return 0;
    } else {
        s = (Node *)malloc(sizeof(Node));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }
}

// 头插法
Node * CreateListByHead(DataType a[], int n) {
    Node * s = NULL;
    Node * first = (Node *)malloc(sizeof(Node));

    first->next = NULL;
    for(int i=0; i<n; i++) {
        s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        s->next = first->next;
        first->next = s;
    }

    return first;
}

// 尾插法
Node * CreateListByTail(DataType a[], int n) {
    Node * s = NULL;
    Node * r = NULL;
    Node * first = (Node *)malloc(sizeof(Node));
    r = first;
    for (int i=0; i<n; i++) {
        s = (Node *)malloc(sizeof(Node));
        s->data = a[i];
        r->next = s;
        r = s;
    }

    r->next = NULL;
    return first;
}

// 删除中间结点
int DeleteMid(Node * first, int i, DataType * ptr) {
    Node * p = first, * q = NULL;
    int count = 0;
    DataType x;

    while (p != NULL && count < i-1) {
        p = p->next;
        count++;
    }

    if (p == NULL || p->next == NULL) {
        printf("位置错误，删除失败\n");
        return 0;
    } else {
        q = p->next;
        *ptr = q->data;
        free(q);    //释放空间
        return 1;
    }
}

// 删除最后一个结点
Node * DeleteTail(Node * first) {
    Node * p = first, * o;

    while (p->next != NULL) {
        o = p;
        p = p->next;
    }
    o->next = NULL;
    free(p);
    // p = first;

    return first;
}

// 销毁链表
void DestroyList(Node * first) {
    Node * p = first;
    while(first != NULL) {
        first = first->next;
        free(p);
        p = first;
    }
}