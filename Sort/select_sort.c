#include <stdio.h>

void SelectSort(int r[], int n) {
    int i, j, index;
    int temp;

    for(i=0; i<n-1; i++) {
        index = i;

        for(j=i+1; j<n; j++) {
            if(r[j] < r[index]) {
                index = j;
            }
        }
        if(index != i) {
            temp = r[i];
            r[i] = r[index];
            r[index] = temp;
        }
    }
}

int main() {
    int r[7] = {49, 27, 65, 97, 76, 13, 38};
    int n = 7;

    SelectSort(r, n);

    for(int i=0; i<n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
}