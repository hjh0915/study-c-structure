#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};

typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

int Length(List L);

List Reverse(List L);

int Length(List L) {
    struct Node *p = L;
    int count = 0;
    while (p != NULL) {
        p = p->Next;
        count++;
    }
    return count;
}

int main() {
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/*
1、先取到链表
2、遍历链表，把最后一个数据元素删除
3、以尾插法形成新链表
*/
List Reverse(List L) {
    struct Node *p = L;
    struct Node *o;

    int i;
    int len = Length(L);
    int a[len];

    for (i=0; i<len; i++) {
        while (p->Next != NULL) {
            o = p;
            p = p->Next;
        }
        o->Next = NULL;

        a[i] = p->Data;
        p = L;
    }

    struct Node *s = NULL;

    struct Node *first = malloc(sizeof(struct Node));
    first->Data = a[0];
    first->Next = NULL;

    struct Node *k = first;

    for (int i=1; i<len; i++) {
        s = malloc(sizeof(struct Node));
        s->Data = a[i];
        s->Next = NULL;

        while (k->Next != NULL) {
            k = k->Next;
        }
        k->Next = s;
    }

    return first;
}

//读取输入的数据
List Read() {

    //尾插法构建链表
    int a[5] = {1, 3, 4, 5, 2};
    struct Node *s = NULL;

    struct Node *first = malloc(sizeof(struct Node));
    first->Data = a[0];
    first->Next = NULL;

    struct Node *p = first;

    for (int i=1; i<5; i++) {
        s = malloc(sizeof(struct Node));
        s->Data = a[i];
        s->Next = NULL;

        while (p->Next != NULL) {
            p = p->Next;
        }
        p->Next = s;
    }

    return first;
}

void Print(List L) {
    
    struct Node *p = L;
    //此处的p是p->Next
    //第一个p指向自己
    while (p != NULL) {
        printf("%2d", p->Data);
        p = p->Next;
    }
    printf("\n");
}