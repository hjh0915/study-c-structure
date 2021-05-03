#include <stdio.h>

void InsertSort(int r[], int n) {
    int i, j;
    for (i=1; i<n; i++) {
        if (r[i] < r[i-1]) {      //若第i个元素大于i-1元素则直接插入；反之，需要找到适当的插入位置后在插入。
            j= i-1;
            int x = r[i];
            while (j>-1 && x < r[j]) {  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                r[j+1] = r[j];
                j--;
            }
            r[j+1] = x;      //插入到正确位置
        }
    }
}

int main() {
    int r[7] = {12, 15, 9, 20, 6, 31, 24};
    int n = 7;

    InsertSort(r, n);

    for (int i=0; i<n; i++) {
        printf("%d ", r[i]);
    }

    printf("\n");
}