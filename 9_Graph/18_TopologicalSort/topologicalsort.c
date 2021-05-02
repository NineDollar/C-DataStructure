//
// Created by Nine_Dollar on 2021/5/2.
//
/**
 * p: TopologicalSort拓扑排序，判断AOV网（有向无环图）是否有环
 */

#include "stdio.h"
#include "predefined.h"
#include "stdlib.h"
#define MAX_VEX 50

typedef struct arcnode{
    int adjvex;
    struct arcnode *next;
}ARCNODE;

typedef struct vexnode{  //邻接表头节点
    int vertex;
    ARCNODE *firstarc;
}VEXNODE;

VEXNODE adjlist[MAX_VEX];

/**
 * @time 2021/5/2 16:35
 * @description 创建邻接表,并给每个顶点赋入度
 * @param
 * @return
 */
int creatadjlist(){
    ARCNODE *ptr;
    int arcnum, vexnum, k, v1, v2;
    printf("\n请输入顶点数和边数（输入格式为：顶点数,边数）:");
    fflush(stdout);
    scanf("%d,%d", &vexnum, &arcnum);
    rewind(stdin);
    for(k = 1; k<=vexnum;k++){
        adjlist[k].firstarc = NULL;
        adjlist[k].vertex = 0;
    }
    for(k = 1;k<=arcnum;k++){
        printf("v1,v2=");
        fflush(stdout);
        scanf("%d,%d", &v1, &v2);
        rewind(stdin);
        ptr = (ARCNODE *) malloc(sizeof(ARCNODE));
        ptr->adjvex = v2;
        ptr->next = adjlist[v1].firstarc;
        adjlist[v1].firstarc = ptr;
        adjlist[v2].vertex++;
    }
    return vexnum;
}

/**
 * @time 2021/5/2 16:36
 * @description 拓扑排序算法
 * @param  n为顶点个数
 * @return
 */
void toposort(int n){
    int queue[MAX_VEX];
    int front = 0,rear = 0;
    int v, w, n1;
    ARCNODE *p;
    n1 = 0;  //记录入度为0的个数
    for(v=1;v<=n;v++){
        if(adjlist[v].vertex == 0){  //所有入度为0的入队
            rear = (rear + 1) % MAX_VEX;
            queue[rear] = v;
        }
    }
    printf("拓扑排序的结果:\n");
    fflush(stdout);
    while (front!=rear){
        front = (front + 1) % MAX_VEX;
        v = queue[front];
        printf("%d", v);
        n1++;
        p = adjlist[v].firstarc;
        while (p!=NULL){
            w = p->adjvex;
            adjlist[w].vertex--;
            if(adjlist[w].vertex==0){
                rear = (rear + 1) % MAX_VEX;
                queue[rear] = w;
            }
            p = p->next;
        }
    }
    if(n1<n){  //输出的顶点个数小于图的顶点个数,说明有环,拓扑排序失败,不是AOE图
        printf("不是AOV图");
    } else{
        printf("--AOV网");
    }
}

/**
 * @time 2021/5/2 17:03
 * @description 输出邻接表
 * @param
 * @return
 */
void printlist(int vexnum){
    printf("所建图的邻接表为：\n");
    int i,n = vexnum;
    ARCNODE *p;
    for (i = 1; i <= n; ++i) {
        printf("%d,%d==>", i, adjlist[i].vertex);  //vertex:保存了顶点的入度
        p = adjlist[i].firstarc;
        while (p != NULL) {
            printf("%d-->", p->adjvex);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main(){
    printf("TopologicalSort拓扑排序，判断AOV网（有向无环图）是否有环\n");
    int n;
    n = creatadjlist();
    printlist(n);
    toposort(n);
    return TRUE;
}


