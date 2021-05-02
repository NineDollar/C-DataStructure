//
// Created by Nine_Dollar on 2021/4/25.
//
/**
 * p: Prim普里姆算法求最小生成树
 */

#include "stdio.h"
#include "../../predefined.h"

#define MAX_VEX 50

/**
 * @time 2021/4/25 10:43
 * @description 创建邻接矩阵,并每个顶点赋值为无穷大,然后输入每个顶点的权值
 * @param
 * @return
 */
int creatcost(int cost[][MAX_VEX]) {
    int vexnum, arcnum, i, j, k, v1, v2, w;
    printf("\n请输入顶点数和边数(输入格式为:顶点数,边数):");
    fflush(stdout);
    scanf("%d,%d", &vexnum, &arcnum);
    rewind(stdin);
    for (i = 1; i <= vexnum; i++) {
        for (j = 0; j <= vexnum; j++) {
            cost[i][j] = 32767;  //32767表示无穷大
        }
    }
    for (k = 1; k <= arcnum; k++) {
        printf("v1,v2,w=");
        fflush(stdout);
        scanf("%d,%d,%d", &v1, &v2, &w);
        rewind(stdin);
        cost[v1][v2] = w;
        cost[v2][v1] = w;  //无向图
    }
    return vexnum;
}

/**
 * @time 2021/4/25 10:45
 * @description 最小生成树算法
 * @param  vexnum:最小生成树顶点
 * @return
 */
void prim(int cost[][MAX_VEX], int vexnum) {
    int lowcost[MAX_VEX], closevert[MAX_VEX], i, j, k, min;
    for (i = 1; i <= vexnum; i++) {  //初始化
        lowcost[i] = cost[1][i];  //从顶点1保存顶点1到
        closevert[i] = 1;
    }
    closevert[1] = -1;  //放入U
    for (i = 2; i <= vexnum; i++) {
        min = 32767;
        k = 0;
        for (j = 1; j <= vexnum; j++) {
            if (closevert[j] != -1 && lowcost[j] < min) {  //权值小于无穷，不然就是未连通
                min = lowcost[j];
                k = j;
            }
        }
        if (k) {  //k==0：说明全是无穷，代表与此顶点不通，查找下一个顶点
            printf("(%d,%d)%2d\n", closevert[k], k, lowcost[k]);
            closevert[k] = -1;  //K放入U
            for (j = 2; j <= vexnum; j++) {  //1是头节点，所以从v2开始
                if (closevert[j] != -1 && cost[k][j] < lowcost[j]) {
                    lowcost[j] = cost[k][j];
                    closevert[j] = k;
                }
            }
        }
    }
}

/**
 * @time 2021/4/25 17:34
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
}

int main() {
    printf("Prim算法-邻接矩阵最小生成树");
    fflush(stdout);
    int vexnum;
    int cost[MAX_VEX][MAX_VEX];
    vexnum = creatcost(cost);
    printf("邻接矩阵为:\n");
    printMatrix(cost, vexnum);

    printf("Prim算法构造的最小生成树的边及其权值:\n");
    fflush(stdout);
    prim(cost, vexnum);
    return TRUE;
}

