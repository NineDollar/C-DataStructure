//
// Created by Nine_Dollar on 2021/4/28.
//
/**
 * p: 直接插入排序
 */
#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/28 14:44
 * @description 对记录数组r做直接插入排序
 * @param  length待排序记录的数目
 * @return
 */
void insertSort(Record r[], int length) {
    int i, j;
    for (i = 2; i <= length; i++) {
        r[0] = r[i];
        j = i - 1;
        while (r[0].key < r[j].key) {
            r[j + 1] = r[j];
            j = j - 1;
        }
        r[j + 1] = r[0];
    }
}

int main() {
    printf("直接插入排序\n");
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
    insertSort(r, len);
    printf("直接插入排序输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}

