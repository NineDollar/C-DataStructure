//
// Created by Nine_Dollar on 2021/4/24.
//
/**
 * p: 邻接表深度优先搜索
 */

#include <malloc.h>
#include "stdio.h"
#include "../../predefined.h"

#define MAX_VEX 100  //最大顶点数

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

void dfs(int v){
    int w;
    ARCNODE *p;
    printf("%d  ", v);  //输出访问顶点
    adjlist[v].vertex = 1;  //顶点标志域置1,表明已经访问过
    p = adjlist[v].firstarc;
    while (p != NULL) {
        w = p->adjvex;
        if(adjlist[w].vertex == 0){
            dfs(w);
        }
        p = p->next;
    }
}

int main(){
    printf("无向图\n");
    printf("深度优先搜索\n");
    int i, n, v;
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
    printf("输入深度优先搜索起始点v:");
    fflush(stdout);
    scanf("%d", &v);
    rewind(stdin);
    printf("图的深度优先搜索序列DFS:");
    dfs(v);
    return TRUE;
}
