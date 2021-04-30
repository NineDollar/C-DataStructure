//
// Created by Nine_Dollar on 2021/4/29.
//
/**
 * p: 冒泡排序（气泡排序）
 */

#include "stdio.h"
#include "predefined.h"

typedef struct {
    int key;
    int data;
} Record;

/**
 * @time 2021/4/29 14:13
 * @description 对数组r做冒泡排序
 * @param
 * @return
 */
void BubbleSort(Record r[],int length){
    int n,i,j;
    Record temp;
    n = length;
    for(i = 1; i<=n-1; ++i){
        for(j = 1; j<=n-i;++j){
            if(r[j].key>r[j+1].key){
                temp = r[j];
                r[j]=r[j+1];
                r[j + 1] = temp;
            }
        }
    }
}

int main(){
    printf("冒泡排序（气泡排序）\n");
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
    BubbleSort(r, len);
    printf("冒泡排序输出:\n");
    for (i = 1; i <= len; i++) {
        printf("%d  ", r[i].key);
    }
    return TRUE;
}

