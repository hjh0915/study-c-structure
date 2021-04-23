#include "./node.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5] = {1, 3, 5, 4, 2};
    int i, x;
    SeqList L;

    // 建立顺序表
    CreateList(&L, a, 5);
    PrintList(&L);
    printf("\n");

    // 在第2个位置插入8
    Insert(&L, 2, 8);
    PrintList(&L);
    printf("当前顺序表的长度为：%d\n", Length(&L));

    // 输入查找的值
    printf("输入查找的值：");
    scanf("%d", &x);
    i = Locate(&L, x);
    if (0 == i) {
        printf("查找失败\n");
    } else {
        printf("值%d的位置为：%d\n", x, i);
    }

    // printf("输入查找第几个的值：", &i);
    // scanf("%d", &i);
    // if (Get(&L, i, &x) == 1) {
    //     printf("第%d个值是%d\n", i, x);
    // } else {
    //     printf("顺序表中没有第%d个值\n", i);
    // }

    //删除值
    printf("输入要删除的第几个值：");
    scanf("%d", &i);
    if (Delete(&L, i, &x) == 1) {
        printf("删除第%d个值是%d，删除后为：", i, x);
        PrintList(&L);
    } else {
        printf("删除失败\n");
    }

    return 0;
}