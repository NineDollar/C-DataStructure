//
// Created by Nine_Dollar on 2021/4/27.
//
/**
 * p: 散列表(哈希表),除留余数法分配空间
 */

#include "stdio.h"
#include "predefined.h"
#include "malloc.h"

typedef struct {
    int key;  //设key为整型
    char data;  //数据元素信息域定义
} Record;

/**
 * @time 2021/4/27 18:03
 * @description 求小于等于m的质数
 * @param
 * @return
 */
int hp(int m) {
    int i, p, flag;
    for (p = m; p >= 2; p--) {
        for (i = 2, flag = 1; i <= p / 2 && flag; i++) {
            if (p % i == 0) {
                flag = 0;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    return p;
}

/**
 * @time 2021/4/27 18:05
 * @description 除留余数
 * @param
 * @return
 */
int hi(int key, int p) {
    return key % p;
}

/**
 * @time 2021/4/27 18:08
 * @description 动态创建序列,输入记录数据的key
 * @param
 * @return
 */
void inputdata(Record **r, int n) {
    int i;
    (*r) = (Record *) malloc(n * sizeof(Record));
    printf("请输入%d个待散列的数据\n", n);
    fflush(stdout);
    for (i = 0; i < n; i++) {
        printf("请输入第%d个记录值的key:", i + 1);
        fflush(stdout);
        scanf("%d", &((*r)[i].key));
        rewind(stdin);
    }

}

/**
 * @time 2021/4/27 19:04
 * @description 通过余数法分配序列地址
 * @param   n记录个数,m散列表长度,p小于m的质数
 * @return
 */
void createhashtable(Record **ht, Record *r, int n, int m, int p) {
    int i, j;
    (*ht) = (Record *) malloc(m * sizeof(Record));
    for (i = 0; i < m; i++) {
        (*ht)[i].key = 0;  //存放关键字数组初始化
    }
    for (i = 0; i < n; i++) {
        j = hi(r[i].key, p);  //除留余数法得到[r].key的地址
        while ((*ht)[j].key != 0) {  //线性探测法解决冲突
            j = (j + 1) % m;
        }
        (*ht)[j].key = r[i].key;
    }
}

/**
 * @time 2021/4/27 19:15
 * @description 散列表查的查找
 * @param
 * @return
 */
int search(Record *ht, int key, int p, int *k) {
    int i;
    *k = 1;
    i = hi(key, p);  //
    while (ht[i].key != 0 && ht[i].key != key) {
        i++;
        ++*k;  //++*:从右到左结合
    }
    if (ht[i].key == 0) {
        return -1;
    } else {
        return i;
    }
}

int main() {
    printf("散列表(哈希表)\n");
    Record *r, *ht;
    int key, i, n, m, p, k;
    char ch;
    printf("输入记录个数n和散列长度m(n<=m):");
    fflush(stdout);
    scanf("%d %d", &n, &m);
    rewind(stdin);
    inputdata(&r, n);
    p = hp(m);  //获取小于m的质数p
    printf("这个小于表长的质数是:%d\n", p);
    fflush(stdout);
    createhashtable(&ht, r, n, m, p);
    printf("得到的散列表为: \n");
    printf("\n  位 置");
    for (i = 0; i < m; i++) {
        printf("%5d", i);
    }
    printf("\n  关键字");
    for (i = 0; i < m; i++) {
        printf("%5d", ht[i].key);
    }
    do {
        printf("\n输入要查找的记录的关键字:");
        fflush(stdout);
        scanf("%d", &key);
        rewind(stdout);
        i = search(ht, key, p, &k);
        if (i != -1) {
            printf("查找成功,位置是:%d\n", i);
            printf("比较次数是:%d\n", k);
        } else {
            printf("查找失败\n");
            printf("比较次数是:%d\n", k);
        }
        fflush(stdout);
        ch = getchar();
        rewind(stdin);
    } while (ch == 'y' || ch == 'Y');
    return TRUE;
}


