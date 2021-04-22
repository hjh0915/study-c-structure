#include "./node.h"
#include <stdio.h>
#include <stdlib.h>

Node * Reverse(Node * first);

int main() {
    int a[5] = {1, 3, 4, 5, 2};

    Node * first, * final;
    first = CreateListByTail(a, 5);
    PrintList(first);

    DataType value;
    int found;

    found = Get(first, 3, &value);
    if (found) {
        printf("%d\n", value);
    }

    // DataType dvalue;
    // int found2, b[5];
    // for(int i=0; i<5; i++) {
    //     found2 = Delete(first, i+1, &dvalue);
    //     if (found2) {
    //         // printf("%d\n", dvalue);
    //         b[i] = dvalue;
    //     }
    // }

    // for(int j=0; j<5; j++) {
    //     printf("%d ", b[j]);
    // }
    // printf("\n");

    // final = CreateListByHead(b, 5);
    // PrintList(final);

    final = Reverse(first);
    PrintList(final);

    return 0;
}

Node * Reverse(Node * first) {
    int len = Length(first);
    int a[len];

    DataType value;
    int found;

    for (int i=0; i<len; i++) {
        found = Delete(first, i+1, &value);
        if (found) {
            a[i] = value;
        }
    }

    Node *final;
    final = CreateListByHead(a, len);

    return final;
}