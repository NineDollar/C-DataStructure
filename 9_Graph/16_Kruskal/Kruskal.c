//
// Created by Nine_Dollar on 2021/5/1.
//
/**
 * p: Kruskal克鲁斯卡尔求最小生成树
 */
#include "stdio.h"
#include "predefined.h"

#define MAX_VEX 50

typedef struct edges {
    int bv, ev, w;
} EDGES;
EDGES edgeset[MAX_VEX];

int createdgeset() {
    int arcnum, i;
    printf("\n输入无向网的边数:");
    fflush(stdout);
    scanf("%d", &arcnum);
    rewind(stdin);
    for (i = 1; i <= arcnum; i++) {
        printf("bv,ev,w=");  //分别对应起点,终点,权值
        fflush(stdout);
        scanf("%d,%d,%d", &edgeset[i].bv, &edgeset[i].ev, &edgeset[i].w);
        rewind(stdin);
    }
    return arcnum;
}

void sort(int n) {
    int i, j;
    EDGES t;
    for (i = 1; i <= n - 1; i++) {
        for (j = i + 1; j <= n; j++) {
            if (edgeset[i].w > edgeset[j].w) {
                 t = edgeset[i];
                edgeset[i] = edgeset[j];
                edgeset[j] = t;
            }
        }
    }
}

int seeks(const int set[], int v) {
    int i = v;
    while (set[i] > 0) {
        i = set[i];
    }
    return i;
}

void kruskal(int e) {
    int set[MAX_VEX], v1, v2;
    int i;
    printf("kruskal算法构造的最小生成树\n");
    fflush(stdout);
    for (i = 1; i < MAX_VEX; i++) {
        set[i] = 0;
    }
    i = 0;
    while (i < e) {
        v1 = seeks(set, edgeset[i].bv);
        v2 = seeks(set, edgeset[i].ev);
        if(v1!=v2){
            printf("(%d,%d) %d\n", edgeset[i].bv, edgeset[i].ev, edgeset[i].w);
            fflush(stdout);
            set[v1] = v2;
        }
        i++;
    }
}

int main() {
    printf("Kruskal克鲁斯卡尔求最小生成树\n");
    int i, arcnum;
    arcnum = createdgeset();
    sort(arcnum);
    printf("按权值由小到大输出边信息:\n");
    printf("bv   ev   w\n");
    for(i = 1;i<=arcnum; i++){
        printf("%d   %d   %d\n", edgeset[i].bv, edgeset[i].ev, edgeset[i].w);
    }
    kruskal(arcnum);
    return TRUE;
}

