#include <stdio.h>

int BinSearch1(int r[], int n, int k) {
    int mid = 1; 
    int low = 1;
    int high = n;
    while (low <= high) {
        mid = (low + high) / 2;
        if (k < r[mid]) {
            high = mid -1;
        }
        else if(k > r[mid]) {
            low = mid + 1;
        } 
        else {
            return mid;
        }
    }

    return 0;
}

// 递归算法
int BinSearch2(int r[], int low, int high, int k) {
    int mid;
    if (low > high) {
        return 0;
    } else {
        mid = (low + high) / 2;
        if (k < r[mid]) {
            return BinSearch2(r, low, mid-1, k);
        }
        else if (k > r[mid]) {
            return BinSearch2(r, mid+1, high, k);
        }
        else {
            return mid;
        }
    }
}

int main() {
    int r[9] = {7, 14, 18, 21, 23, 29, 31, 35, 38};
    int n = 9;
    int k = 14;

    int a = BinSearch1(r, n, k);
    printf("%d\n", a);

    int b = BinSearch2(r, 0, n, k);
    printf("%d\n", b);

    return 0;
}