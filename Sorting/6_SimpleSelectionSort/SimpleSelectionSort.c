//
// Created by Nine_Dollar on 2021/4/29.
//
/**
 * p: 简单选择排序（直接排序）
 */

#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/29 19:48
 * @description 选择排序
 * @param
 * @return
 */
void SelectSort(Record r[], int length) {
    int i, k, j;
    int n;
    Record temp;
    n = length;
    for (i = 1; i <= n - 1; ++i) {
        k = i;
        for (j = i + 1; j <= n; ++j) {
            if (r[j].key < r[k].key) {
                k = j;
            }
        }
        if (k != i) {
            temp = r[i];
            r[i] = r[k];
            r[k] = temp;
        }
    }
}

int main() {
    printf("简单选择排序（直接排序）\n");
    int i, j;
    Record r[20];
    int len;
    printf("输入待排序记录的长度：");
    fflush(stdout);
    scanf("%d", &len);
    rewind(stdin);
    printf("输入%d个记录的关键字值\n", len);
    fflush(stdout);
    for (i = 1; i <= len; i++) {
        printf("请输入第%d个关键字值:", i);
        fflush(stdout);
        scanf("%d", &j);
        rewind(stdin);
        r[i].key = j;
    }
    SelectSort(r, len);
    printf("简单选择排序输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}

