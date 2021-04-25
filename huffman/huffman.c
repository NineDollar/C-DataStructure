//
// Created by Nine_Dollar on 2021/4/21.
//
/**
 * p: 
 */
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
#include "predefined.h"

#define MAXLEN 100

typedef struct {
    int weight;  //无符号整数
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

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

    for (i = 0; i < 2 * n - 1; ++i) {
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
    for (i = 0; i < n; ++i) {
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
Status Select(HFMT T, int i, int *p1, int *p2) {
    long min1 = 99999;
    long min2 = 99999;
    int j;
    for (j = 0; j <= i; j++) {
        if (T[j].parent == -1) {
            if (min1 > T[i].weight) {  //找到最小的权值
                min1 = T[j].weight;
                *p1 = j;
            }
        }
    }
    for (j = 0; j <= i; j++) {
        if (T[i].parent == -1) {
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
        Select(T, i - 1, &p1, &p2);
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
    printf("哈夫曼树的各边显示：");
    int i = 0, k = 0;
    for (i = 0; i < 2 * n - 1; i++) {
        while (T[i].lchild != -1) {
            if (!(k % 2)) {
                printf("\n");
            }
            printf("\t\t(%d,%d),(%d,%d)", T[i].weight, T[i].lchild, T[i].weight, T[i].rchild);
            k++;
            break;
        }
        printf("\n");
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
 * @description 求解哈夫曼树
 * @param
 * @return
 */
Status huffmannode(HFMT T) {
    printf("\t\t输入权值的对应哈夫曼编码：");
    int i, j, a, k = 0;
    for (i = 0; i < n; i++) {
        j = 0;
        a = i;
        if (!(k % 2)) {
            printf("\n");
        }
        printf("\t\t%i:", T[i].weight);
        k++;
        hfnode(T, i, j);
        i = a;
    }
    return OK;
}


int main() {
    HFMT HT;
    CreatHFMT(HT);
    PrintHFMT(HT);
    huffmannode(HT);
    printf("\n");
    return TRUE;
}

