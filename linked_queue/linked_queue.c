//
// Created by Nine_Dollar on 2021/4/19.
//
/**
 * p: 链队列
 */
#include "stdio.h"
#include "stdlib.h"
#include "predefined.h"

typedef int QElemType;

typedef struct QNode {  //QNode:结构体类型名
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr; //别名

typedef struct {
    QueuePtr front;  //头指针
    QueuePtr rear;  //尾指针
} LinkQueue;

/**
 * @time 2021/4/19 14:37
 * @description 初始化
 * @param
 * @return
 */
Status InitQueue(LinkQueue *q) {
    q->front = q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (!q->front) {
        exit(OVERFLOW);
    }
    q->front->next = NULL;
    return OK;
}

/**
 * @time 2021/4/19 14:38
 * @description 销毁队列
 * @param
 * @return
 */
Status DestroyQueue(LinkQueue *q) {
    while (q->front) {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return OK;
}

/**
 * @time 2021/4/19 14:40
 * @description 插入元素e
 * @param
 * @return
 */
Status EnQueue(LinkQueue *q, QElemType e) {
    QueuePtr p;
    p = (QueuePtr) malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *q, QElemType *e) {
    QueuePtr p;
    if (q->front == q->rear) {
        printf("空队\n");
        exit(ERROR);
    }
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;  //指向删除元素下一个节点
    if (q->rear == p) {
        q->rear = q->front;
    }
    free(p);
    return OK;
}


int main() {
    LinkQueue q;
    InitQueue(&q);

//    插入
    EnQueue(&q, 78);
    EnQueue(&q, 98);
    EnQueue(&q, 128);
    EnQueue(&q, 3458);

//    出队
    int e;
    DeQueue(&q, &e);
    printf("出队:%d\n", e);
    DeQueue(&q, &e);
    printf("出队:%d\n", e);

//    销毁
    DestroyQueue(&q);
    DeQueue(&q, &e);
    printf("出队:%d", e);

    return TRUE;
}