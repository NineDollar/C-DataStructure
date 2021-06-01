//
// Created by Nine_Dollar on 2021/4/19.
//
/**
 * p: 循环顺序队列 返回元素个数,插入元素,删除队头元素
 */
#include "stdlib.h"
#include "stdio.h"
#include "predefined.h"

#define MAXQSIZE 10
typedef int QELemType;

typedef struct {
    QELemType *base;
    int front;  //头指针
    int rear;  //尾指针
} SqQueue;

/**
 * @time 2021/4/19 16:54
 * @description 初始化
 * @param
 * @return
 */
Status Init(SqQueue *q) {
    q->base = (QELemType *) malloc(MAXQSIZE * sizeof(QELemType)); //开辟了MAXQSIZE个QELemType类型连续的空间
    if (!q->base) {
        exit(OVERFLOW);
    }
    q->front = q->rear = 0;
    return OK;
}

/**
 * @time 2021/4/19 16:57
 * @description 返回元素个数
 * @param
 * @return
 */
int Queuelength(SqQueue q) {
    return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}

/**
 * @time 2021/4/19 17:00
 * @description 插入元素
 * @param
 * @return
 */
Status EnQueue(SqQueue *q, QELemType e) {
    if ((q->rear + 1) % MAXQSIZE == q->front) {  //%MAXQSIZE:当尾指针到达最大长度时和头部分还有空间,%MAXQSIZE就是头部分的位序了
        printf("队满\n");
        exit(OVERFLOW);
    }
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXQSIZE;  //插入元素,队尾指针增1
    return OK;
}

/**
 * @time 2021/4/19 17:01
 * @description 删除队头元素,用e返回其值
 * @param
 * @return
 */
Status DeQueue(SqQueue *q, QELemType *e) {
    if (q->front == q->rear) {
        printf("空队\n");
        return ERROR;
    }
    *e = q->base[q->front];
    q->front = (q->front + 1) % MAXQSIZE;  //删除元素,队头指针增1
    return OK;
}

int main() {
    SqQueue q;
//     初始化
    Init(&q);

    EnQueue(&q, 243);
    printf("循环队列长度:%d\n", Queuelength(q));

    int e;
    DeQueue(&q,&e);
    printf("删除:%d\n", e);
    return TRUE;
}
