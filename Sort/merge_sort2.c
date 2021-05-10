#include <stdio.h>

void Merge(int r[], int s, int m, int t) {
    int n;
    int r1[n];
    int i = s;
    int j = m+1;
    int k = s;

    while (i<=m && j<=t) {
        if (r[i] <= r[j]) {
            // r1[k++] = r[i++];
            r1[k] = r[i];
            i++;
            k++;
        } else {
            // r1[k++] = r[j++];
            r1[k] = r1[j];
            k++;
            j++;
        }
    }

    while (i <= m) {
        r1[k++] = r[i++];
    }

    while (j <= t) {
        r1[k++] = r[j++];
    }

    for (i=s; i<t; i++) { 
        r[i] = r1[i];
    }
}

void MergePass(int r[], int n, int h) {
    int i = 1;
    int k;

    while (i <= n-2*h+1) {
        Merge(r, i, i+h-1, i+2*h-1);
        i = i+2*h;
    }

    if (i < n-h+1) {
        Merge(r, i, i+h-1, n);
    }
}

void MergeSort(int r[], int n) {
    int h = 1;
    while (h < n) {
        MergePass(r, n, h);
        h = 2*h;
    }
}

int main() {
    int r[8] = {8, 3, 2, 6, 7, 1, 5, 4};
    int n = 8;

    MergeSort(r, n);

    for(int i=1; i<=n; i++) {
        printf("%d ", r[i]);
    }

    printf("\n");
}