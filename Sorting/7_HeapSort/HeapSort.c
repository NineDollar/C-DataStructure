//
// Created by Nine_Dollar on 2021/4/29.
//
/**
 * p: 堆排序（树形选择排序）
 */

#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/29 19:48
 * @description r[k...m]是以r[k]为根的完全二叉树,
 * 且以分别以[2k]和r[2k+1]为左右树的小顶堆
 * 调整r[k],使整个序列r[k...m]满足堆的性质(根值小于(大于)左右孩子)
 * 此算法生成最小堆
 * @param 
 * @return
 */
void sift(Record r[], int k, int m) {
    Record t;
    int i, j;
    int x;
    int finished;
    t = r[k];  //暂存跟记录人r[k]
    x = r[k].key;
    i = k;
    j = 2 * i;
    finished = 0;
    while (j <= m && !finished) {
        if (j < m && r[j].key > r[j + 1].key) {
            j = j + 1;  //若存在右子树,且右子树根的关键字小,则沿右分支筛选
        }
        if (x <= r[j].key) {
            finished = 1;  //筛选完毕
        } else {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }   //继续筛选
    }
    r[i] = t;
}

/**
 * @time 2021/4/29 20:13
 * @description 建成最小堆
 * @param
 * @return
 */
void creatheap(Record r[], int length) {
    int i, n;
    n = length;
    for (i = n / 2; i >= 1; --i) {  //自第[n/2]个记录开始筛选
        sift(r, i, n);
    }
}

/**
 * @time 2021/4/29 20:13
 * @description 堆排序
 * @param
 * @return
 */
void HeapSort(Record r[], int length) {
    int i, n;
    Record b;
    creatheap(r, length);
    n = length;
    for (i = n; i >= 2; --i) {
        b = r[i];  //堆顶和堆最后一个交换
        r[i] = r[1];  //最值放放入r[i]
        r[1] = b;
        sift(r, 1, i - 1);  //继续调整,使r[1...i-1]变成堆
    }
}

int main() {
    printf("堆排序（树形选择排序）\n");
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
    HeapSort(r, len);
    printf("堆排序（树形选择排序）输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}

