//
// Created by Nine_Dollar on 2021/4/26.
//
/**
 * p: 二分查找
 */

#include "stdio.h"
#include "../../predefined.h"

#define max_len 20

typedef struct {
    int key;
    char data;
} Record;

typedef struct {
    Record r[max_len + 1];
    int length;
} seqTable;

/**
 * @time 2021/4/26 11:35
 * @description 在有序表sq中查找关键字k的元素
 * @param
 * @return
 */
int BinarySearch(seqTable sq, int k) {
    int low, high, mid;
    low = 1;
    high = sq.length;
    while (low <= high) {
        mid = (low + high) / 2;
        if (sq.r[mid].key < k) {
            low = mid + 1;  //继续在右半边进行查找
        } else {
            if (sq.r[mid].key > k) {
                high = mid - 1; //左半边进行查找
            } else {  //不满足以上两种情况,等于查找到了关键字,查找结束
                break;
            }
        }
    }
    if (low > high) {
        return 0;
    } else {
        return mid;
    }
}

int main() {
    printf("二分查找\n");
    fflush(stdout);
    seqTable sq;
    int rec, k, i, len, ch;
    printf("输入查找表的长度:");
    fflush(stdout);
    scanf("%d", &len);
    rewind(stdin);
    sq.length = len;
    for (i = 1; i <= len; i++) {
        printf("输入%d个记录的关键字值:", len);
        fflush(stdout);
        scanf("%d", &ch);
        rewind(stdin);
        sq.r[i].key = ch;
    }
    printf("输入要查找的元素:");
    fflush(stdout);
    scanf("%d", &k);
    rec = BinarySearch(sq, k);
    if (rec == 0) {
        printf("该查找表中没有这条记录");
    } else {
        printf("该元素在表中的位置为:%d\n", rec);
    }
    return TRUE;
}

