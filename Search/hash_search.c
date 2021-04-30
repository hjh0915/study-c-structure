#define HashSize 10
#include <stdio.h>
#include <stdlib.h>

int m = 0;

int Hash(int key){
    m = HashSize;
	return key % m;	//除留余数法
}

int HashSearch1(int ht[], int m, int k, int *p) {
    int i = 0;
    int j = 0;
    int flag = 0;

    j = Hash(k);
    i = j;
    while (ht[i] != 0 && flag == 0) {
        if (ht[i] == k) {
            *p = i;
            return 1;
        } else {
            i = (i+1) % m;
        }
        if (i == j) {
            flag = 1;   //表已满
        }
    }

    if (flag == 1) {
        printf("溢出");
        
    } else {
        ht[i] = k;
        *p = i;
        return 0;
    }
}

void PrintHash(int ht[]){
	int i;
	for(i=0; i<HashSize; i++)
		printf("%d ",ht[i]);
	printf("\n");
}

int main() {
    int ht[10] = {47, 7, 29, 11, 16, 92, 22, 8, 3};
    int m = HashSize;
    int k = 2;
    int p;
    int found;
    found = HashSearch1(ht, m, k, &p);
    printf("%d\n", p);

    PrintHash(ht);
}