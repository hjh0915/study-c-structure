#include <stdio.h>

void Sift(int r[], int k, int m) {
    int i, j, temp;
    i = k;
    j = 2 * i;

    while(j <= m) {
        if (j<m && r[j] <r[j+1]) {
            j++;
        }
        
        if (r[i] < r[j]) {
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
}

void HeapSort(int r[], int n) {
    int i;
    
    for (i=n/2; i>0; i--) {
        Sift(r, i, n);
    }

    int x;
    for(i=n; i>1; i--) {
        x = r[1];
        r[1] = r[i];
        r[i] = x;//将堆顶记录与未排序的最后一个记录交换
        Sift(r, 1, i-1);//重新调整为顶堆
    }

}

int main() {
    int r[8] = {36, 30, 18, 40, 32, 45, 22, 50};
    int n = 8;

    HeapSort(r, n);

    for(int i=0; i<n; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
}