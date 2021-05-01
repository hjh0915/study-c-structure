#include <stdio.h>

void BubbleSort(int r[], int n) {
    int j, exchange, bound;
    exchange = n;
    while (exchange != 0) {
        bound = exchange;
        exchange = 0;

        for(j=0; j<bound; j++) {
            if(r[j] > r[j+1]) {
                r[0] = r[j];
                r[j] = r[j+1];
                r[j+1] = r[0];
                exchange = j;
            }
        }
    }
}

int main() {
    int r[8] = {50, 13, 55, 97, 27, 38, 49, 65};
    int n = 8;

    BubbleSort(r, n);

    for(int i=0; i<n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
}