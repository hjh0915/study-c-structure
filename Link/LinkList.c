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

// List Reverse(List L);

int main() {
    List L1;
    L1 = Read();
    // L2 = Reverse(L1);
    Print(L1);
    // Print(L2);
    return 0;
}

//尾插法
// List Reverse(List L) {

// }

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