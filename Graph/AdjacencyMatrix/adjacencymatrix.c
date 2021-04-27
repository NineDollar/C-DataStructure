//
// Created by Nine_Dollar on 2021/4/23.
//
/**
 * p: 图，邻接矩阵
 */
#include "stdio.h"
#include "stdlib.h"
#include "predefined.h"

#define MAX_VEX 100


int creatcost(int cost[][MAX_VEX]) {
    int vexnum, arcnum, i, j, k, v1, v2;
    printf("请输入顶点数和边数（输入格式为：顶点树，边数）：");
    fflush(stdout);
    scanf("%d,%d", &vexnum, &arcnum);
    rewind(stdin);
    for (i = 1; i <= vexnum; i++) {  //初始化矩阵
        for (j = 1; j <= vexnum; j++) {
            cost[i][j] = 0;
        }
    }
    for (k = 0; k < arcnum; k++) {
        printf("v1,v2=");
        fflush(stdout);
        scanf("%d,%d", &v1, &v2);
        rewind(stdin);
        cost[v1][v2] = 1;
//        cost[v2][v1] = 1;  //无向图矩阵上下对称，去掉此行即为有向图
    }
    return vexnum;
}

/**
 * @time 2021/4/25 19:22
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
    printf("邻接矩阵\n");
    int i, j, vexnum;
    int cost[MAX_VEX][MAX_VEX];
    vexnum = creatcost(cost);
    printf("所建图的邻接矩阵为：\n");
    /*for (i = 1; i <= vexnum; i++) {
        for (j = 1; j <= vexnum; j++) {
            printf("%3d", cost[i][j]);
        }
        printf("\n");
    }*/
    printMatrix(cost, vexnum);
    return TRUE;
}

