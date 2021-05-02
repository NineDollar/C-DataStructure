//
// Created by Nine_Dollar on 2021/4/18.
//
/**
 * p: 双向链表 插入,遍历,删除
 */
#include <string.h>
#include "stdio.h"
#include "predefined.h"
#include "stdlib.h"

#define MAXSIZE 20

typedef struct DulNode {
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DuLinkList;

DuLinkList GetElemP_Dul(DuLinkList l, int i) {
    DuLinkList p;
    int j;
    j = 0;
    p = l;
    while (p && j < i) {
        j++;
        p = p->next;
    }
    if (!p || j > i) {
        return NULL;
    }
    return p;
}

/**
 * @time 2021/4/18 11:13
 * @description 插入
 * @param
 * @return
 */
Status ListInsert_Dul(DuLinkList l, int i, ElemType e) {
    DuLinkList s, p;
    if (!(p = GetElemP_Dul(l, i))) {
        printf("插入位置不合法");
        return OVERFLOW;
    }
    s = (DuLinkList) malloc(sizeof(DulNode));
    if (!s) {
        printf("插入元素空间分配失败");
        exit(OVERFLOW);
    }
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

/**
 * @time 2021/4/18 11:13
 * @description 遍历
 * @param
 * @return
 */
Status TraverElem(DuLinkList l) {
    DuLinkList p;
    p = l->next;
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return OK;
}

/**
 * @time 2021/4/18 15:01
 * @description 输入元素
 * @param
 * @return
 */
Status InitElem(DuLinkList l) {
    DuLinkList p, q;
    char se[MAXSIZE] = "";
    int e, i;
    p = l;
    i = 1;
    while (1) {
        printf("请输入单链x表第%d个值（“？”结束输入）：", i++);
        fflush(stdout);
        scanf("%s", se);
        e = atoi(se);
        if (strcmp(se, "?") == 0) {
            printf("输入结束\n");
            break;
        }
        q = (DuLinkList) malloc(sizeof(DulNode));
        if (!q) {
            exit(OVERFLOW);
        }
        q->data = e;
        q->next = p->next;
        p->next = q;
        q->prior = p;
        p = q;
    }
    return OK;
}

/**
 * @time 2021/4/18 15:01
 * @description 删除
 * @param
 * @return
 */
Status ListDelete_Dul(DuLinkList l,int i,ElemType *e){
    DuLinkList  p;
    if (!(p = GetElemP_Dul(l, i))) {
        printf("删除位置不合法");
        return OVERFLOW;
    }
    *e = p->data;
    p->prior->next = p->next;
    p->next = p->prior;
    free(p);
    return OK;
}

int main() {
    DuLinkList l;
    l = (DuLinkList) malloc(sizeof(DulNode));
    if (!l) {
        printf("内存分配失败");
        exit(OVERFLOW);
    }
    l->prior = NULL;
    l->next = NULL;
    InitElem(l);
    TraverElem(l);

//    插入
//    ListInsert_Dul(l, 3, 45);

//    删除
    /*int e;
    ListDelete_Dul(l, 5, &e);
    printf("删除元素%d\n", e);*/

    TraverElem(l);
    return TRUE;
}

