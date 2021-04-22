#include "./node.h"

int main() {
    int b[5] = {1, 3, 2, 5, 4};
    
    Node * first, * final;
    first = CreateListByHead(b, 5);

    PrintList(first);

    first = CreateListByTail(b, 5);

    PrintList(first);

    final = DeleteTail(first);
    PrintList(final);

    return 0;
}