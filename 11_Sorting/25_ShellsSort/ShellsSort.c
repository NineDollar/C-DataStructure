//
// Created by Nine_Dollar on 2021/4/28.
//
/**
 * p: 希尔排序
 */

#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/28 19:41
 * @description 对数组r做一次希尔排序
 * @param  length数组长度,d为增量
 * @return
 */
void ShellInsert(Record r[], int length, int d) {
    int i, j;
    for (i = 1 + d; i <= length; i++) {
        if (r[i].key < r[i - d].key) {
            r[0] = r[i];
            for (j = i - d; j > 0 && r[0].key < r[j].key; j -= d) {  //后一项小于前一项
                r[j + d] = r[j];
            }
            r[j + d] = r[0];
        }
    }
}

/**
 * @time 2021/4/28 19:47
 * @description
 * @param  n为d的长度
 * @return
 */
void ShellSort(Record r[], int length, int d[], int n) {
    int i;
    for (i = 0; i <= n - 1; ++i) {
        ShellInsert(r, length, d[i]);
    }
}

int main() {
    printf("希尔排序\n");

    int i, j;
    Record r[20];
    int len, d[3] = {5, 3, 1};
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
    ShellSort(r, len, d, 3);
    printf("希尔排序输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}

