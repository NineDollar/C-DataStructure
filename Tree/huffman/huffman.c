//
// Created by Nine_Dollar on 2021/4/21.
//
/**
 * p: 赫夫曼树(哈夫曼树,最优二叉树)
 */
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "predefined.h"

#define MAXLEN 100

typedef struct {
    int weight;  //整数
    int parent, lchild, rchild;
} HTNode;

typedef HTNode HFMT[MAXLEN];
int n;

/**
 * @time 2021/4/22 16:10
 * @description 初始化
 * @param
 * @return
 */
Status InitHFMT(HFMT T) {
    int i;
    printf("请输入共多少个权值（小于100）：");
    fflush(stdout);
    scanf("%d", &n);
    rewind(stdin);
    for (i = 0; i < 2 * n - 1; i++) {
        T[i].weight = 0;
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].parent = -1;
    }
    return OK;
}

/**
 * @time 2021/4/22 16:10
 * @description 输入权值
 * @param
 * @return
 */
Status InputWeight(HFMT T) {
    int w;
    int i;
    for (i = 0; i < n; i++) {
        printf("输入第%d个权值：", i + 1);
        fflush(stdout);
        scanf("%d", &w);
        rewind(stdin);
        T[i].weight = w;
    }
    return OK;
}

/**
 * @time 2021/4/22 16:37
 * @description 造出最小的两个权值
 * @param
 * @return
 */
Status SelectMin(HFMT T, int i, int *p1, int *p2) {
    long min1 = 99999;
    long min2 = 99999;
    int j;
    for (j = 0; j <= i; j++) {
        if (T[j].parent == -1) {
            if (min1 > T[j].weight) {  //找到最小的权值
                min1 = T[j].weight;
                *p1 = j;
            }
        }
    }
    for (j = 0; j <= i; j++) {
        if (T[j].parent == -1) {
            if (min2 > T[j].weight && j != (*p1)) {
                min2 = T[j].weight;
                *p2 = j;
            }
        }
    }
    return OK;
}

/**
 * @time 2021/4/22 16:33
 * @description 构造哈夫曼树，T[2*n-1]为根结点
 * @param
 * @return
 */
Status CreatHFMT(HFMT T) {
    int i, p1, p2;
    InitHFMT(T);
    InputWeight(T);
    for (i = n; i < 2 * n - 1; i++) {
        SelectMin(T, i - 1, &p1, &p2);
        T[p1].parent = T[p2].parent = i;
        T[i].lchild = T[p1].weight;
        T[i].rchild = T[p2].weight;
        T[i].weight = T[p1].weight + T[p2].weight;
    }
    return OK;
}

/**
 * @time 2021/4/22 16:33
 * @description 输出向量状态表
 * @param
 * @return
 */
Status PrintHFMT(HFMT T) {
    printf("哈夫曼树的各边显示：\n");
    int i;
    for (i = 0; i < 2 * n - 1; i++) {
        if (T[i].lchild != -1) {
            printf("(%d<-%d->%d)", T[i].lchild, T[i].weight, T[i].rchild);
            printf("\n");
        }
    }
    return OK;
}

Status hfnode(HFMT T, int i, int j) {
    j = T[i].parent;
    if (T[j].rchild == T[i].weight) {
        printf("1");
    } else {
        printf("0");
    }
    if (T[j].parent != -1) {
        i = j, hfnode(T, i, j);
    }
    return OK;
}

/**
 * @time 2021/4/22 16:32
 * @description 求解哈夫曼树,从叶子节点到根节点
 * @param
 * @return
 */
Status huffmannode(HFMT T) {
    printf("输入权值的对应哈夫曼编码：\n");
    int i, j, a;
    for (i = 0; i < n; i++) {  //输出哈夫曼编码
        j = 0;
        a = i;
        printf("%i:", T[i].weight);
        hfnode(T, i, j);
        i = a;
        printf("\n");
    }
    return OK;
}

int main() {
    printf("赫夫曼树\n");
    HFMT HT;
    CreatHFMT(HT);
    PrintHFMT(HT);
    huffmannode(HT);
    printf("\n");
    return TRUE;
}

