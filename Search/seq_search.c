#include <stdio.h>

int SeqSearch(int r[], int n, int k) {
    int i = n;
    r[0] = k;
    while (r[i] != k) {
        i--;
    }

    return i;   //查找元素的位置
}

int main() {
    int r[4] = {3, 1, 6, 100};
    int n = 4;
    int k = 1;
    int a;

    a = SeqSearch(r, n, k);

    printf("%d\n", a);

    return 0;
}