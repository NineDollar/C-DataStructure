//
// Created by Nine_Dollar on 2021/4/28.
//
/**
 * p: 二分插入排序
 */
#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/28 16:36
 * @description 折半插入排序
 * @param
 * @return
 */
void BinsertSort(Record r[], int length) {
    int i, j;
    Record x;
    int low, high, mid;
    for(i = 2; i<=length;++i){
        x = r[i];
        low=1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if(x.key < r[mid].key){ //左边插入
                high = mid - 1;
            } else{
                low = mid + 1;  //右边查找
            }
        }
        for (j = i - 1; j >= low; --j) {
            r[j + 1] = r[j];
        }
        r[low] = x;
    }
}

int main() {
    printf("二分插入排序\n");
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
    BinsertSort(r, len);
    printf("二分插入排序输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}
