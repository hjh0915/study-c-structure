#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElemType {
    int weight;
    int parent, lchild, rchild;
} ElemType;

void Select(ElemType huffmanTree[], int min1, int min2, int n);
void PrintHtree(ElemType htree[], int n);

// 找到权值最小的两个根结点
void Select(ElemType huffmanTree[], int s1, int s2, int n) {
    int min1, min2;

    //遍历数组初始下标为 0
    int i = 0;
    //找到还没构建树的结点
    while(huffmanTree[i].parent != 0 && i <= n) {
        i++;
    }
    min1 = huffmanTree[i].weight;
    s1 = i;
    
    while(huffmanTree[i].parent != 0 && i <= n) {
        i++;
    }

    //对找到的两个结点比较大小，min2为大的，min1为小的
    if(huffmanTree[i].weight < min1) {
        min2 = min1;
        s2 = s1;
        min1 = huffmanTree[i].weight;
        s1 = i;
    }else {
        min2 = huffmanTree[i].weight;
        s2 = i;
    }

    // //两个结点和后续的所有未构建成树的结点做比较
    // for(int j=i+1; j<=n; j++) {

    //     //如果比最小的还小，将min2=min1，min1赋值新的结点的下标
    //     if(huffmanTree[j].weight < min1) {
    //         min2 = min1;
    //         min1 = huffmanTree[j].weight;
    //         s2 = s1;
    //         s1 = j;
    //     }
    //     //如果介于两者之间，min2赋值为新的结点的位置下标
    //     else if(huffmanTree[j].weight >= min1 && huffmanTree[j].weight < min2) {
    //         min2 = huffmanTree[j].weight;
    //         s2 = j;
    //     }
    // }
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

    for (k=n; k<2*n-1; k++) {
        Select(huffmanTree, i1, i2, k);  //权值最小的两个根结点下标为i1, i2
        huffmanTree[i1].parent = k;
        huffmanTree[i2].parent = k;
        huffmanTree[k].lchild = i1;
        huffmanTree[k].rchild = i2;
        huffmanTree[k].weight = huffmanTree[i1].weight + huffmanTree[i2].weight;
    }
}

//打印输出
void PrintHtree(ElemType htree[], int n) {

    for (int i=0; i<n; i++) {
        printf("%d \n", htree[i].weight);
    }
}

int main() {
    int w[4] = {2, 4, 5, 3};
    int n = 4;
    ElemType htree[2*n-1];

    CreateHtree(htree, w, n);
    // PrintHtree(htree, n);

    return 0;
}