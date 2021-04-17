//
// Created by Nine_Dollar on 2021/4/14.
//
/*
 * 线性表
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "predefined.h"


#define LIST_INIT_SIZE 5  // 初始分分配增量
#define LISTINCREMENT 10  //分配增量

typedef struct {
    ElemType *elem; //元素
    int length;  //长度
    int listsize;  //线性表总大小
} SqList;

/**
 * @time 2021/4/16 0:30
 * @description 初始化
 * @param
 * @return
 */
Status InitList_Sq(SqList *l) {
    l->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!l->elem) {
        printf("分配空间失败");
        exit(OVERFLOW);
    }
    l->length = 0;
    l->listsize = LIST_INIT_SIZE;
    return OK;
}

/**
 * @time 2021/4/16 16:18
 * @description 插入
 * @param
 * @return
 */
Status ListInsert_Sq(SqList *l, int i, ElemType e) {
    ElemType *newbase;
    ElemType *q, *p;
    if (i < 1 || i > l->length + 1) {
        printf("插入位置不合法\n");
        exit(ERROR);
    }
    if (l->length >= l->listsize) {
        newbase = (ElemType *) realloc(l->elem, (l->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) {
            printf("分配空间失败");
            exit(OVERFLOW);
        }
        printf("增加空间\n");
        l->elem = newbase;
        l->listsize += LISTINCREMENT;
    }
    q = &(l->elem[i - 1]);//地址作为插入标志位
    for (p = &(l->elem[l->length - 1]); p >= q; --p) {  //标记的地址
        *(p + 1) = *p;   //向后移动元素
    }
    *q = e;  //插入元素
    ++l->length;  //->高于++
    return OK;
}

/**
 * @time 2021/4/16 0:29
 * @description 遍历元素
 * @param
 * @return
 */
Status TraverElem(SqList l) {
    int i;
    for (i = 0; i < l.length; i++) {
        printf("第%d个：%d\n", i + 1, *l.elem);
        l.elem++;
    }
    return OK;
}

/**
 * @time 2021/4/16 16:17
 * @description 顺序表长度和大小
 * @param
 * @return
 */
Status Listsize(SqList *l) {
    printf("长度:%d\n", l->length);
    printf("总大小:%d\n", l->listsize);
    return OK;
}

/**
 * @time 2021/4/16 16:17
 * @description 初始化元素
 * @param
 * @return
 */
Status InitElem(SqList *l) {
    int i, e = 0;
    for (i = 1;; ++i) {
        printf("请输入第%d个值(0结束):", i);
        fflush(stdout);
        scanf("%d", &e);
        if (e == 0) {
            printf("输入结束\n");
            break;
        }
        ListInsert_Sq(l, i, e);
    }
    return OK;
}

/**
 * @time 2021/4/16 16:42
 * @description 删除第i个位置元素
 * @param i删除下表
 * @return 删除的元素值
 */
Status ListDelete_Sq(SqList *l, int i, ElemType *e) {
    int *q, *p;
    if (i < 1 || i > l->length) {
        printf("删除位置不合法");
        exit(ERROR);
    }
    p = l->elem + i - 1;
    q = l->elem + l->length - 1;
    *e = *p;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --l->length;
    return OK;
}

/**
 * @time 2021/4/16 20:06
 * @description 获取元素位序
 * @param  compare接口
 * @return
 */
Status LocateElem_Sq(SqList *l, ElemType e, ElemType(*compare)(ElemType, ElemType)) {
    int *p, i = 0;
    p = l->elem;
    while (i <= l->length && !(*compare)(*p++, e)) {
        ++i;
    }
    if (i <= l->length) {
        return i + 1;
    } else {
        return 0;
    }
}

/**
 * @time 2021/4/16 20:30
 * @description 有序顺序表插入
 * @param
 * @return
 */
Status InsertOrderList(SqList *l, ElemType x) {
    int i;
    if (l->length == l->listsize) {
        printf("空间已满,插入失败\n");
        return OVERFLOW;
    }
    i = l->length - 1;
    while (i >= 0 && x < l->elem[i]) {
        i--;
    }
    for (int j = l->length - 1; j >= i + 1; j--) {
        l->elem[j + 1] = l->elem[j];
    }
    l->elem[i + 1] = x;
    l->length++;
    return OK;
}

/**
 * @time 2021/4/16 21:10
 * @description 两个顺序表归并
 * @param
 * @return
 */
Status MergeList(SqList la, SqList lb, SqList *lc) {
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa = la.elem;
    pb = lb.elem;
    lc->listsize = lc->length = la.length + lb.length;
    pc = lc->elem = (ElemType *) malloc(lc->listsize * sizeof(ElemType));
    if (!lc->elem) {
        exit(OVERFLOW);
    }
    pa_last = la.elem + la.length - 1;
    pb_last = lb.elem + lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa < *pb) {
            *pc++ = *pa++;
        } else {
            *pc++ = *pb++;  //+高于*
        }
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
    return OK;
}

int main() {
    SqList l;
    InitList_Sq(&l);
//    InitElem(&l);  //初始化数据
    ListInsert_Sq(&l, 1, 1);
    ListInsert_Sq(&l, 2, 42);
    ListInsert_Sq(&l, 3, 89);
    ListInsert_Sq(&l, 4, 894);
    ListInsert_Sq(&l, 5, 1517);
    TraverElem(l);
    printf("-----------\n");

//    删除
    /*int e;
    ListDelete_Sq(&l, 2, &e);
    printf("删除%d\n", e);*/

//    查找元素位序
    /*int findelem = 2, index;
    index = LocateElem_Sq(&l, findelem, compare);
    printf("查找元素%d的位序:%d\n", findelem, index);
    TraverElem(l);
    Listsize(&l);*/

//    在有序表中插入
//    InsertOrderList(&l, 78);

//    两个顺序表归并
    /*SqList lb,lc;
    InitList_Sq(&lb);
    ListInsert_Sq(&lb, 1, 43);
    ListInsert_Sq(&lb, 2, 23);
    ListInsert_Sq(&lb, 3, 6564);
    ListInsert_Sq(&lb, 4, 2343);
    ListInsert_Sq(&lb, 5, 67);
    MergeList(l, lb, &lc);
    TraverElem(lc);*/

//    TraverElem(l);
    return TRUE;
}
