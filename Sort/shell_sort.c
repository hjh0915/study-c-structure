#include <stdio.h>

void ShellSort(int r[], int n) {
    int d, i, j;
    for(d=n/2; d>=1; d=d/2) {
        for(i=d+1; i<=n; i++) {
            r[0] = r[i];
            for(j=i-d; j>0 && r[0]<r[j]; j=j-d) {
                r[j+d] = r[j];
            }

            r[j+d] = r[0];
        }
    }
}

int main() {
    int r[10] = {59, 20, 17, 36, 98, 14, 23, 83, 13, 28};
    int n = 10;

    ShellSort(r, n);

    for(int i=0; i<n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
}