#include <stdio.h>
#include <stdlib.h>

#include "./node.h"

//初始化顺序表 
void InitList(SeqList * L) {
    L->length = 0;
}

//建立顺序表
int CreateList(SeqList * L, DataType a[], int n) {
    if (n > MaxSize) {
        printf("顺序表的空间不够，无法建立顺序表\n");
        return 0;
    }

    for (int i=0; i<n; i++) {
        L->data[i] = a[i];
    }
    L->length = n;
    return 1;
}

//判断顺序表是否长度为0
int Empty(SeqList * L) {
    if (L->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

//顺序表的长度
int Length(SeqList * L) {
    return L->length;
}

//遍历顺序表
void PrintList(SeqList * L) {
    for (int i=0; i<L->length; i++) {
        printf("%d ", L->data[i]);
    }
}

//按值查找
int Locate(SeqList * L, DataType x) {
    for (int i=0; i<L->length; i++) {
        if (L->data[i] == x) {
            return i+1;
        }
    }
    return 0;
}

//按位查找
int Get(SeqList * L, int i, DataType * ptr) {
    if (i<1 || i>L->length) {
        printf("查找位置非法，查找失败\n");
        return 0;
    } else {
        *ptr = L->data[i-1];
        return 1;
    }
}

//插入
int Insert(SeqList * L, int i, DataType x) {
    if (L->length >= MaxSize) {
        printf("上溢错误，插入失败\n");
        return 0;
    }
    if (i<1 || i>L->length+1) {
        printf("位置错误，插入失败\n");
        return 0;
    }
    for (int j = L->length; j>=i; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = x;
    L->length++;

    return 1;
}

//删除
int Delete(SeqList * L, int i, DataType * ptr) {
    if (L->length == 0) {
        printf("下溢错误，删除失败\n");
        return 0;
    }
    if (i<1 || i>L->length) {
        printf("位置错误，删除失败\n");
        return 0;
    }
    *ptr = L->data[i-1];

    for (int j=i; j<L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return 1;
}