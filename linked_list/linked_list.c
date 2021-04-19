//
// Created by Nine_Dollar on 2021/4/16.
//
/**
 * p: 线性链表
 */

#include <malloc.h>
#include <stdlib.h>
#include "stdio.h"
#include "predefined.h"
#include "string.h"

#define MAXSIZE 20

typedef struct LNode {  //LNode类型
    ElemType data;  //数据域
    struct LNode *next;  //指针域
} LNode, *LinkList;  //LNode变量

/**
 * @time 2021/4/16 21:45
 * @description 单链表插入
 * @param  i:插入的位序
 * @return
 */
Status ListInsert_L(LinkList l, int i, ElemType e) {
    int j;
    LinkList p, s;
    p = l;
    j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) {
        exit OVERFLOW;
    }
    s = (LinkList) malloc(sizeof(LNode)); //LNode类型名
    s->data = e;
    s->next = l->next;
    l->next = s;
    return OK;
}

/**
 * @time 2021/4/17 12:30
 * @description 遍历单链表
 * @param
 * @return
 */
Status TraverElem(LinkList l) {
    LinkList p;
    p = l->next;
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return OK;
}

/**
 * @time 2021/4/17 12:33
 * @description 初始化单链表元素
 * @param
 * @return
 */
Status InitElem(LinkList l) {
    int i, e;
    char se[MAXSIZE] = "";
    i = 0;
    LinkList p, q;
    while (1) {
        printf("请输入单链x表第%d个值（“？”结束输入）：", i++);
        fflush(stdout);
        scanf("%s", se);
        e = atoi(se);
        if (strcmp(se, "?") == 0) {
            printf("输入结束\n");
            break;
        }
        p = (LinkList) malloc(sizeof(LNode));
        p->data = e;
        p->next = l->next;
        l->next = p;
        l = p;
    }
    return OK;
}

/**
 * @time 2021/4/17 17:45
 * @description 获取第i个元素的值
 * @param  i：位序
 * @return
 */
Status GetIndexElem(LinkList l, int i, int *e) {
    LinkList p;
    int j;
    p = l->next;
    j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

/**
 * @time 2021/4/17 17:52
 * @description 删除位序i的元素
 * @param  i:位序
 * @return
 */
Status ListDelete_L(LinkList l, int i, int *e) {
    LinkList p, q;
    int j = 0;
    p = l;
    while (p->next && j < i - 1) {  //找到删除元素上一个节点
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1) {
        return ERROR;
    }
    q = p->next; //删除的节点
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/**
 * @time 2021/4/17 20:28
 * @description 两非递减单链表归并
 * @param  *lc:二级指针,lc本身是指针,需要返回指针,所以再取一次指针,指针的指针,也就是地址的地址
 * @return
 */
Status MergeList(LinkList l, LinkList lb, LinkList *lc) {  //*lc二级指针
    LinkList pa, pb, pc;
    pa = l->next;
    pb = lb->next;
    pc = l;
    *lc = pc;  //保存pc的首地址
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(lb);
    return OK;
}

int main() {
    LinkList l;
    l = (LinkList) malloc(sizeof(struct LNode));
    l->next = NULL;

//    输入值
//    InitElem(l);

    ListInsert_L(l, 4, 345);
    ListInsert_L(l, 3, 267);
    ListInsert_L(l, 1, 120);
    ListInsert_L(l, 0, 10);
    TraverElem(l);
    printf("-----\n");

//    获取第i个元素
    /*int e,index;
    index = 2;
    GetIndexElem(l, index, &e);
    printf("位序%d的值：%d\n", index, e);*/

//    删除
    /*int e,index;
    index = 2;
    ListDelete_L(l, index, &e);
    printf("删除位序%d的值:%d\n", index, e);
    TraverElem(l);*/

//    归并
    /*LinkList lb, lc;
    lb = (LinkList) malloc(sizeof(LNode));
    lb->next = NULL;
    ListInsert_L(lb, 4, 789);
    ListInsert_L(lb, 3, 325);
    ListInsert_L(lb, 1, 69);
    ListInsert_L(lb, 0, 45);
    TraverElem(lb);
    printf("-----\n");

    MergeList(l, lb, &lc);
    TraverElem(lc);*/

    return TRUE;
}