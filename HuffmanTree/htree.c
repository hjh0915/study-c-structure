#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElemType {
    int weight;
    int parent, lchild, rchild;
} ElemType;

void Select(ElemType huffmanTree[], int *s1, int *s2, int n);
void PrintHtree(ElemType htree[], int n);

// 找到权值最小的两个根结点
void Select(ElemType huffmanTree[], int *s1, int *s2, int n) {
    *s1 = n;
    *s2 = n+1;
}

void CreateHtree(ElemType huffmanTree[], int w[], int n) {
    int i, k, i1, i2;

    for (i=0; i<2*n-1; i++) {
        huffmanTree[i].parent = -1;
        huffmanTree[i].lchild = -1;
        huffmanTree[i].rchild = -1;
    }

    for (i=0; i<n; i++) {
        huffmanTree[i].weight = w[i];
    }

    i = 0;
    for (k=n; k<2*n-1; k++) {
        Select(huffmanTree, &i1, &i2, 2*i);  //权值最小的两个根结点下标为i1, i2

        huffmanTree[k].weight = huffmanTree[i1].weight + huffmanTree[i2].weight;
        huffmanTree[i1].parent = k;
        huffmanTree[i2].parent = k;
        huffmanTree[k].lchild = i1;
        huffmanTree[k].rchild = i2;

        i++;
    }
}

//打印输出
void PrintHtree(ElemType htree[], int n) {

    for (int i=0; i<n; i++) {
        printf("%d \n", htree[i].weight);
    }
}

int main() {
    int w[4] = {2, 3, 4, 5};
    int n = 4;
    ElemType htree[2*n-1];

    CreateHtree(htree, w, n);
    PrintHtree(htree, 2*n-1);

    return 0;
}