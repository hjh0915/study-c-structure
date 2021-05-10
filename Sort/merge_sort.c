#include <stdio.h>

void Merge(int r[], int a[], int x1, int x2, int x3) {
    int i, j, k;
    i = x1;
    j = x2+1;
    k = x1;

    while ((i<=x2) && (j<=x3)) {
        if (r[i] <= r[j]) {
            a[k] = r[i];
            i++;
            k++;
            
        } else {
            a[k]=r[j];
            j++;
            k++;
        }

        while (i <= x2) {
            a[k++] = r[i++];
        }

        while (j <= x3) {
            a[k++] = r[j++];
        }
    }
}

void MergeSort(int r[], int a[], int m, int n) {
    int p;
    int t[20];

    if(m == n) {
        a[m] = r[m];
    } else {
        p = (m+n) / 2;
        MergeSort(r, t, m, p);    
        MergeSort(r, t, p+1, n);    
        Merge(t, a, m, p, n); 
    }
}

int main() {
    // int r[8] = {8, 3, 2, 6, 7, 1, 5, 4};
    // int s = 0;
    // int t = 8;

    // MergeSort(r, r, s, t);

    // for(int i=0; i<8; i++) {
    //     printf("%2d", r[i]);
    // }
    // printf("\n");

    // return 0;

    int a[9];
    int i;
    printf("请输入8个数：\n");
    for(i=1;i<=8;i++)
        scanf("%d",&a[i]);    //从键盘中输入10个数
    MergeSort(a,a,1,8);    //调用merge_sort()函数进行归并排序
    printf("排序后的顺序是：\n");
    for(i=1;i<=8;i++)
        printf("%5d",a[i]);    //输出排序后的数据
    printf("\n");
    return 0;
}