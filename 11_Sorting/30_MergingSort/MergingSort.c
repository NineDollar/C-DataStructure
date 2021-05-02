//
// Created by Nine_Dollar on 2021/4/29.
//
/**
 * p: 归并排序，主要用于外部排序
 */

#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/29 21:43
 * @description 合并成有序序列,存放在r2
 * @param
 * @return
 */
void Merge(Record r1[], int low, int mid, int high, Record r2[]) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while ((i <= mid) && (j <= high)) {  //归并
        if (r1[i].key <= r1[j].key) {
            r2[k] = r1[i];
            ++i;
        } else {
            r2[k] = r1[j];
            ++j;
        }
        ++k;
    }
//    若右剩余的,放入r2中
    while (i <= mid) {
        r2[k] = r1[i];
        k++;
        i++;
    }
    while (j <= high) {
        r2[k] = r1[j];
        k++;
        j++;
    }
}

/**
 * @time 2021/4/29 21:44
 * @description r1排序后放在r3中,r2为辅助空间
 * @param
 * @return
 */
void MSort(Record r1[], int low, int high, Record r3[]) {
    int mid;
    Record r2[20];
    if (low == high) {
        r3[low] = r1[low];
    } else {
        mid = (low + high) / 2;
        MSort(r1, low, mid, r2);
        MSort(r1, mid + 1, high, r2);
        Merge(r2, low, mid, high, r3);
    }
}

/**
 * @time 2021/4/29 21:40
 * @description 对数组r做归并排序
 * @param  n长度
 * @return
 */
void MergeSort(Record r[], int n) {
    MSort(r, 1, n, r);
}

int main() {
    printf("归并排序\n");
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
    MergeSort(r, len);
    printf("归并排序输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}