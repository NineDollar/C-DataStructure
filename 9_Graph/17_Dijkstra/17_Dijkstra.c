//
// Created by Nine_Dollar on 2021/5/1.
//
/**
 * p: Dijkstra迪杰斯特拉算法求某一点到其他各顶点的最短路径
 */

#include "stdio.h"
#include "predefined.h"

#define MAX_VEX 50

int creatcost(int cost[][MAX_VEX]) {
    int vexnum, arcnum, i, j, k, v1, v2, w;
    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");
    fflush(stdout);
    scanf("%d,%d", &vexnum, &arcnum);
    rewind(stdin);
    for (i = 1; i <= vexnum; i++) {
        for (j = 1; j <= vexnum; j++) {
            cost[i][j] = 9999;
        }
    }
    for (k = 1; k <= arcnum; k++) {
        printf("v1,v2,w=");
        fflush(stdout);
        scanf("%d,%d,%d", &v1, &v2, &w);
        rewind(stdin);
        cost[v1][v2] = w;
    }
    return vexnum;
}

/**
 * @time 2021/5/1 20:57
 * @description 迪杰斯特拉求从源点出发的最短路径
 * @param
 * @return
 */
void dijkstra(int cost[][MAX_VEX], int vexnum) {
    //s数组记录顶点v是否确定最短路径,s[v] = 1;表示顶点v确定了最短路径;s[v] = 0,表示顶点v尚未确定最短路径
    //dist数组表示当前求出的从v1到vi的最短路径
    //path是路径数组,其中path[i]表示v1到顶点vi之间最短路径上vi的前驱顶点,eg:路径(v1,v2,v3),则path[5]=3;
    int path[MAX_VEX], s[MAX_VEX], dist[MAX_VEX], i, j, w, v, min, v1;
    printf("请输入源点v1:");
    fflush(stdout);
    scanf("%d", &v1);
    rewind(stdin);
    for (i = 1; i <= vexnum; i++) {
        dist[i] = cost[v1][i];
        s[i] = 0;
        if (cost[v1][i] < 9999) {
            path[i] = v1;
        }
    }
    s[v1] = 1;  //自身确定最短路径
    for (i = 1; i <= vexnum; i++) {
        min = 9999;
        for (j = 1; j <= vexnum; j++) {
            if (s[j] == 0 && (dist[j] < min)) {  //查找未被确定的最短路径
                min = dist[j];
                w = j;
            }
        }
        s[w] = 1;  //确定最短路径
        for (v = 1; v <= vexnum; v++) {
            if (s[v] == 0) {
                if (dist[w] + cost[w][v] < dist[v]) {  //确定是否存在新的路径
                    dist[v] = dist[w] + cost[w][v];  //存在就更新新的路径权值
                    path[v] = w;  //存放新的前驱顶点
                }
            }
        }
    }
    printf("源点%d到其他各顶点的路径与值:\n", v1);
    for (i = 2; i <= vexnum; i++) {
        if (s[i] == 1) {
            w = i;
            while (w != v1) {
                printf("%d<--", w);
                w = path[w];
            }
            printf("%d", w);
            printf("    %d\n", dist[i]);
        } else {
            printf("%d<--%d", i, v1);
            printf("    9999\n");
        }
    }
}

/**
 * @time 2021/5/1 21:24
 * @description 输出邻接矩阵
 * @param
 * @return
 */
void printMatrix(int cost[][MAX_VEX], int vexnum) {
    for (int j = 0; j < vexnum * 13; ++j) {
        printf("-");
    }
    printf("\n");
    for (int j = 0; j <= vexnum; j++) {
        if (j == 0) {
            printf("|  %7c ", 32);
            continue;
        }
        printf("| v%-6d ", j);
    }
    printf("|");
    printf("\n");
    for (int i = 1; i <= vexnum; i++) {
        for (int j = 0; j < vexnum * 13; ++j) {
            printf("-");
        }
        printf("\n");

        printf("| v%-7d ", i);

        for (int j = 1; j <= vexnum; j++) {
            printf("| %7d ", cost[i][j]);
        }
        printf("|");
        printf("\n");
    }
    for (int j = 0; j < vexnum * 13; ++j) {
        printf("-");
    }
    printf("\n");
}

int main() {
    printf("Dijkstra迪杰斯特拉算法求某一点到其他各顶点的最短路径\n");
    int vexnum;
    int cost[MAX_VEX][MAX_VEX];
    vexnum = creatcost(cost);
    printMatrix(cost, vexnum);
    dijkstra(cost, vexnum);
    return TRUE;
}
