//
// Created by Nine_Dollar on 2021/4/23.
//
/**
 * p: 邻接表
 */

#include "stdio.h"
#include "predefined.h"
#include "malloc.h"

#define MAX_VEX 100

typedef struct Node {
    int adjvex;  //邻接顶点域
    struct Node *next;
    char info;  //若为网图，要显示边上的信息，增加数据域
} ARCNODE;

typedef struct VexNode {
    int vertex;  //顶点域
    ARCNODE *firstarc;  //边表头指针，指向下一个邻接点
} VEXNODE;

VEXNODE adjlist[MAX_VEX];  //头节点数组,存放顶点域

/**
 * @time 2021/4/23 19:02
 * @description 建立邻接表
 * @param
 * @return
 */
int creatadjlist() {
    ARCNODE *ptr;
    int arcnum, vexnum, v1, v2;  //arcnum:边，vexnum：边
    printf("请输入顶点数和边数（输入格式为：顶点数，边数）：");
    fflush(stdout);
    scanf("%d,%d", &vexnum, &arcnum);
    rewind(stdin);
    for (int k = 1; k <= vexnum; k++) {
        adjlist[k].firstarc = NULL;
    }
    for (int k = 0; k < arcnum; ++k) {
        printf("v1,v2=");
        fflush(stdout);
        scanf("%d,%d", &v1, &v2);
        ptr = (ARCNODE *) malloc(sizeof(ARCNODE));
        ptr->adjvex = v2;
        ptr->next = adjlist[v1].firstarc;  //头插法，组成链表
        adjlist[v1].firstarc = ptr;
//        对于有向图，下面四句需删除
        ptr = (ARCNODE *) malloc(sizeof(ARCNODE));
        ptr->adjvex = v1;
        ptr->next = adjlist[v2].firstarc;
        adjlist[v2].firstarc = ptr;
    }
    return vexnum;
}

int main() {
    printf("邻接表\n");
    int i, n;
    ARCNODE *p;
    n = creatadjlist();
    printf("所建图的邻接表为：\n");
    for (i = 1; i <= n; ++i) {
        printf("%d==>", i);
        p = adjlist[i].firstarc;
        while (p != NULL) {
            printf("---->%d", p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
    return TRUE;
}
