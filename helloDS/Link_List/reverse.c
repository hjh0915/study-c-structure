#include "./node.h"
#include <stdio.h>
#include <stdlib.h>

Node * Reverse(Node * first);

int main() {
    int a[5] = {1, 3, 4, 5, 2};

    Node * first, * final, *del, *first1;
    first = CreateListByTail(a, 5);
    PrintList(first);

    first1 = CreateListByTail(a, 5);
    del = DeleteTail(first1);
    PrintList(del);

    final = Reverse(first);
    PrintList(final);

    return 0;
}

// 实现链表倒序
Node * Reverse(Node * first) {
    int len = Length(first);
    int a[len];
    // Node * p = first, * o;
    Node * p;

    for (int i=0; i<len; i++) {
        p = DeleteTail(first);
        // while (p->next != NULL) {
        //     o = p;
        //     p = p->next;
        // }
        // o->next = NULL;

        a[i] = p->data;
        p = first;
    }
    free(p);

    Node * final;
    final = CreateListByTail(a, len);

    return final;
}