//
// Created by Nine_Dollar on 2021/4/24.
//
/**
 * p: 
 */

#include <malloc.h>
#include "stdio.h"
#include "../predefined.h"

#define MAX_VEX 100

typedef char Vextype[3];

typedef struct {
    Vextype vexs[MAX_VEX];
    int cost[MAX_VEX][MAX_VEX];
    int vexnum, arcnum;
} MGraph;

int visited[MAX_VEX];


int main() {
    printf("邻接矩阵深度优先搜索\n");

    return TRUE;
}

