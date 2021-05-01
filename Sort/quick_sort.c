#include <stdio.h>
#define n 7

int Partition(int r[], int first, int end) {
    int i = first;
    int j = end;
    int temp;

    while (i < j) {
        while(i<j && r[i]<=r[j]) {
            j--;
        }
        if(i < j) {
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i++;
        }
        while(i<j && r[i]<=r[j]) {
            i++;
        }
        if(i < j) {
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            j--;
        }
    }

    return i;
}

void QuickSort(int r[], int first, int end) {
    if(first < end) {
        int pivot = Partition(r, first, end);
        QuickSort(r, first, pivot-1);
        QuickSort(r, pivot+1, end);
    }
}

int main() {
    int r[n] = {23, 13, 35, 6, 19, 50, 28};
    int first = 0;
    int end = n-1;

    QuickSort(r, first, end);

    for(int i=0; i<7; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
}