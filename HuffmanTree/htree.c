#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElemType {
    int weight;
    int parent, lchild, rchild;
} ElemType;

void Select(ElemType huffmanTree[], int min1, int min2);

void CreateHtree(ElemType huffmanTree[], int w[], int n) {
    int i, k, i1, i2;

    for (i=0; i<2*n-1; i++) {
        huffmanTree[i].parent = -1;
        huffmanTree[i].lchild = -1;
        huffmanTree[i].rchild = -1;
    }

    for (i=0; i<n; i++) {
        huffmanTree[i].weight = w[i];

        for (k=n; k<2*n-1; k++) {
            Select(huffmanTree, i1, i2);  //权值最小的两个根结点下标为i1, i2
            huffmanTree[k].weight = huffmanTree[i1].weight + huffmanTree[i2].weight;
            huffmanTree[i1].parent =k;
            huffmanTree[i2].parent = k;
            huffmanTree[k].lchild = i1;
            huffmanTree[k].rchild = i2;
        }
    }
}

// 找到权值最小的两个根结点
void Select(ElemType huffmanTree[], int min1, int min2) {
    int n;
    int left, right;
    left = right = 0;

    for (int i=0; i<=n; i++) {
        //如果是根节点
        if(huffmanTree[i].parent == 0) {
            if (huffmanTree[i].weight < min1) {
                min2 = min1;
                right = left;
                min1 = huffmanTree[i].weight;
                left = i;
            } else if (huffmanTree[i].weight < min2) {
                min2 = huffmanTree[i].weight;
                right = i;
            }
        }
    }
    //两个结点和后续的所有未构建成树的结点做比较
    for(int j=i+1; j<=n; j++) {
        //如果有父结点，直接跳过，进行下一个
        if(huffmanTree[j].parent != 0) {
            continue;
        }
        //如果比最小的还小，将min2=min1，min1赋值新的结点的下标
        if(huffmanTree[j].weight < min1) {
            min2 = min1;
            min1 = huffmanTree[j].weight;
            right = left;
            left = j;
        }
        //如果介于两者之间，min2赋值为新的结点的位置下标
        else if(huffmanTree[j].weight >= min1 && huffmanTree[j].weight < min2) {
            min2 = huffmanTree[j].weight;
            right = j;
        }
    }
}

//打印输出
void PrintHtree(ElemType htree[], int n) {
    for (int i=0; i<=n; i++) {
        if (htree[i].parent == -1) {
            
        }
    }
}

int main() {
    int w[5] = {2, 8, 7, 6, 5};
    int n = 5;
    ElemType htree;

    CreateHtree(htree, w, n);

    return 0;
}