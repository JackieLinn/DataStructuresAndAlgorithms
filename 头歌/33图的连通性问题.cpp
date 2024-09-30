#include <stdio.h>
#include <stdlib.h>

#define MAXV 50
#define INF 32767


// MGraph 结构体定义
typedef struct {
    int n, e;             // 顶点数n和边数e
    int edges[MAXV][MAXV]; // 邻接矩阵存储边的信息
} MGraph;

// Definition of Edge structure
typedef struct {
    int u, v; // Vertices that the edge connects
    int w;    // Weight of the edge
} Edge;

//prim
void Prim(MGraph g, int v) {
    int lowcost[MAXV];
    int closest[MAXV];
    int min, k, i, j;

    for (i = 0; i < g.n; i++) {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }

    lowcost[v] = 0;
    for (i = 1; i < g.n; i++) {
        min = INF;

        for (j = 0; j < g.n; j++) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }

        printf("(%d, %d): %d\n", closest[k], k, min);
        lowcost[k] = 0;

        for (j = 0; j < g.n; j++) {
            if (g.edges[k][j] < lowcost[j]) {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
    }
}

//krusal
void InsertSort(Edge E[], int n) /*对E[0..n-1]按递增有序进行直接插入排序*/
{
    int i, j;
    Edge temp;
    for (i = 1; i < n; i++) {
        temp = E[i];
        j = i - 1;                /*从右向左在有序区E[0..i-1]中找E[i]的插入位置*/
        while (j >= 0 && temp.w < E[j].w) {
            E[j + 1] = E[j];    /*将关键字大于E[i].w的记录后移*/
            j--;
        }
        E[j + 1] = temp;        /*在j+1处插入E[i] */
    }
}

void Kruskal(MGraph g) {
    /********** Begin **********/

    Edge edges[MAXV * MAXV]; // 边集数组，存储所有边的信息
    int i, j, k = 0;
    for (i = 0; i < g.n; i++) {
        for (j = i + 1; j < g.n; j++) {
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].w = g.edges[i][j];
                k++;
            }
        }
    }
    InsertSort(edges, k); // 对边集数组进行排序

    int parent[MAXV]; // 存放顶点的祖先结点
    for (i = 0; i < g.n; i++) {
        parent[i] = -1; // 初始化为-1，表示每个顶点的祖先是自己
    }

    for (i = 0; i < k; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int pu = u, pv = v;
        while (parent[pu] != -1) {
            pu = parent[pu]; // 找到u的祖先结点
        }
        while (parent[pv] != -1) {
            pv = parent[pv]; // 找到v的祖先结点
        }
        if (pu != pv) { // 如果u、v不在同一连通分量中，即不构成回路
            printf("(%d,%d):%d\n", u, v, edges[i].w);
            parent[pv] = pu; // 将v的祖先设置为u，合并连通分量
        }
    }

    /********** End **********/
}

int main() {
    int i, j;
    MGraph g;
    int n, e;
    scanf("%d %d", &n, &e);
    g.n = n;
    g.e = e;
    int a[MAXV][MAXV];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = a[i][j];
    printf("Krusal:\n");
    Kruskal(g);
    printf("Prim:\n");
    Prim(g, 0);
    return 0;
}
