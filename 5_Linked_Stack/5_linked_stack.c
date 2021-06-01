//
// Created by Nine_Dollar on 2021/4/19.
//
/**
 * p: 链栈 插入元素,出栈,判断是否空链栈
 */
#include "stdio.h"
#include "predefined.h"
#include "stdlib.h"

typedef int SElemType;

typedef struct SNode {
    SElemType tnodedata;
    struct SNode *next;
} SNode, *StackPtr;

typedef struct {
    StackPtr top;
    int count;  //元素个数
} LinkStack;

/**
 * @time 2021/4/19 19:55
 * @description 初始化
 * @param
 * @return
 */
Status Init(LinkStack *s) {
    s->top = (StackPtr) malloc(sizeof(SNode));
    if (!s->top) {
        printf("分配内存失败");
        exit(OVERFLOW);
    }
    s->top->next = NULL;
    return OK;
}

/**
 * @time 2021/4/19 20:16
 * @description 插入元素(入栈)
 * @param
 * @return
 */
Status EnStack(LinkStack *s, SElemType e) {
    StackPtr p;
    p = (StackPtr) malloc(sizeof(SNode));
    if (!p) {
        exit(OVERFLOW);
    }
    p->tnodedata = e;
    p->next = s->top;
    s->top = p;
    s->count += 1;
    return OK;
}

/**
 * @time 2021/4/19 20:17
 * @description 出栈
 * @param
 * @return
 */
Status PopStack(LinkStack *s, SElemType *e) {
    StackPtr q;
    if (!s->top) {
        printf("链栈空");
        exit(OVERFLOW);
    }
    q = s->top;
    *e = q->tnodedata;
    s->top = q->next;
    free(q);
    return OK;
}


/**
 * @time 2021/4/20 19:26
 * @description 判断是否空链栈
 * @param
 * @return
 */
Status StackEmpty(LinkStack *s) {
    if (s->top->next) {
        return TRUE;
    }
    return FALSE;
}

int main() {
    LinkStack s;
    Init(&s);

    /*EnStack(&s, 78);
    EnStack(&s, 23);
    EnStack(&s, 2345);
    SElemType e;
    PopStack(&s, &e);
    printf("出栈:%d\n", e);
    PopStack(&s, &e);
    printf("出栈:%d", e);*/

//    判断栈空
    /*EnStack(&s, 78);
    printf("%d", StackEmpty(&s));*/
    return TRUE;
}
