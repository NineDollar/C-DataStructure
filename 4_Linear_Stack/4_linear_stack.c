//
// Created by Nine_Dollar on 2021/4/20.
//

/**
 * p: 顺序栈 返回栈顶元素,入栈,退栈
 */
#include "stdio.h"
#include "predefined.h"
#include "stdlib.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

/**
 * @time 2021/4/18 15:29
 * @description 初始化
 * @param
 * @return
 */
Status InitStack(SqStack *s) {
    s->base = (ElemType *) malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base) {
        printf("分配内存失败");
        exit(OVERFLOW);
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}

/**
 * @time 2021/4/18 15:39
 * @description 返回栈顶元素
 * @param  e返会值
 * @return
 */
Status GetTop(SqStack *s, ElemType *e) {
    if (s->top == s->base) {
        printf("栈空\n");
        return ERROR;
    }
    *e = *(s->top - 1);
    return OK;
}

/**
 * @time 2021/5/2 20:19
 * @description 入栈
 * @param
 * @return
 */
Status Push(SqStack *s, ElemType e) {
    if (s->top - s->base >= s->stacksize) {
        s->base = (ElemType *) realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base) {
            printf("分配空间失败");
            exit(OVERFLOW);
        }
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    *s->top++ = e;
    return OK;
}

/**
 * @time 2021/4/18 15:47
 * @description 退栈，从栈顶一一退
 * @param
 * @return
 */
Status Pop(SqStack *s, ElemType *e) {
    if (s->top == s->base) {
        printf("空");
        return ERROR;
    }
    *e = *--s->top;  //--高于*
    return OK;
}

int main() {
    SqStack s;
    InitStack(&s);

    Push(&s, 4);
    Push(&s, 9);
    Push(&s, 354);
    Push(&s, 3453);

//    获取栈顶元素
     int e;
     GetTop(&s, &e);
     printf("栈顶元素%d\n", e);

//   退栈
    /* int e;
     Pop(&s, &e);
     printf("%d\n", e); //退栈，先进后出*/

    return OK;
}


