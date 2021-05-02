//
// Created by Nine_Dollar on 2021/4/26.
//
/**
 * p: 顺序查找
 */

#include "stdio.h"
#include "predefined.h"

#define max_len 20
typedef struct {
    int key;
    char data;
} Record;

typedef struct {
    Record r[max_len];
    int length;
} seqTable;

/**
 * @time 2021/4/26 10:42
 * @description 查找
 * @param
 * @return
 */
int SeqSearch(seqTable st, int k) {
    int i;
    st.r[0].key = k; //设置哨兵
    i = st.length;
    while (st.r[i].key != k) {  //从后往前查找
        i--;  //查找不到i=0
    }
    return i;  //返回查找到的下标
}

int main() {
    printf("顺序查找\n");
    fflush(stdout);
    seqTable st;
    int rec, k, i, len, ch;  //rec:返回查找的下表
    printf("输入查找表的长度:");
    fflush(stdout);
    scanf("%d", &len);
    rewind(stdin);
    st.length = len;
    for (i = 1; i <= len; i++) {
        printf("输入%d个记录的关键字值:", i);
        fflush(stdout);
        scanf("%d", &ch);
        rewind(stdin);
        st.r[i].key = ch;
    }
    printf("输入查找的元素:");
    fflush(stdout);
    scanf("%d", &k);
    rewind(stdin);
    rec = SeqSearch(st, k);
    if(rec == 0){
        printf("该元素不存在");
    } else{
        printf("该元素在表中的位置为:%d", rec);
    }
    return TRUE;
}


