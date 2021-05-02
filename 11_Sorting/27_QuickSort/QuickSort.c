//
// Created by Nine_Dollar on 2021/4/29.
//
/**
 * p: 快速排序
 */

#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;


/**
 * @time 2021/4/29 15:32
 * @description 对数组r中的r[left]至r[right]部分进行一趟快速排序,并得到枢轴记录
 * 排序后的结果满足其之后()前的记录的关键字均不小于(大于)枢轴记录
 * @param
 * @return
 */
int Partition(Record r[], int left, int right) {
    Record temp;
    int low, high;
    temp = r[left];
    low = left;
    high = right;
    while (low < high) {
        while (low < high && r[high].key >= temp.key) {
            high--;
        }
        if (low < high) {  //找到小于temp.key的记录,进行交换
            r[low] = r[high];
            low++;
        }
        while (low < high && r[low].key < temp.key) {  //low从左到右找到大于temp.key的记录
            low++;
        }
        if (low < high) {  //找到大于temp.key的记录,进行交换
            r[high] = r[low];
            high--;
        }
    }
    r[low] = temp;  //将枢轴记录保存到low=high的位置
    return low;  //返回枢轴记录的位置
}

void quicksort(Record r[], int low, int high) {
    int pos;
    if (low < high) {
        pos = Partition(r, low, high);
        quicksort(r, low, pos - 1);
        quicksort(r, pos + 1, high);
    }
}

int main() {
    printf("快速排序\n");
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
    quicksort(r, 1, len);
    printf("快速排序输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}
