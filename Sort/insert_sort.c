#include <stdio.h>

void InsertSort(int r[], int n) {
    int i, j;
    for(i=2; i<=n; i++) {
        r[0] = r[i];

        for(j=i-1; r[0]<r[j]; j--) {
            r[j+1] = r[j];
        }

        r[j+1] = r[0];
    }
}

int main() {
    int r[7] = {12, 15, 9, 20, 6, 31, 24};
    int n = 7;

    InsertSort(r, n);

    for (int i=0; i<n; i++) {
        printf("%d \n", r[i]);
    }
}