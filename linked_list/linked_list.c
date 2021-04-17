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

#define SIZE 20

typedef struct LNode {
    ElemType data;  //数据域
    struct LNode *next;  //指针域
} LNode, *LinkList;

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
    s = (LinkList) malloc(sizeof(struct LNode));
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
    printf("NULL");
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
    char se[SIZE]="";
    i = 0;
    LinkList p, q;
    while (1) {
        printf("请输入单链x表第%d个值（“？结束输入”）：", i++);
        fflush(stdout);
        scanf("%s", se);
        e = atoi(se);
        if (strcmp(se, "?") == 0) {
            printf("输入结束\n");
            break;
        }
        p = (LinkList) malloc(sizeof(LinkList));
        p->data = e;
        p->next = l->next;
        l->next = p;
        l = p;
    }
    return OK;
}

int main() {
    LinkList l;
    l = (LinkList) malloc(sizeof(struct LNode));
    l->next = NULL;
    InitElem(l);
//    ListInsert_L(l, 0, 10);
    TraverElem(l);

    return TRUE;
}