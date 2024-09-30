#include <stdio.h>
#include <stdlib.h>

#define MAXV 50
#define INF 32767

// MGraph 结构体定义
typedef struct {
    int n, e;             // 顶点数n和边数e
    int edges[MAXV][MAXV]; // 邻接矩阵存储边的信息
} MGraph;

void Ppath(int path[][MAXV], int i, int j)  /*前向递归查找路径上的顶点*/
{
    int k;
    k = path[i][j];
    if (k == -1) return;    /*找到了起点则返回*/
    Ppath(path, i, k);    /*找顶点i的前一个顶点k*/
    printf("%d,", k);
    Ppath(path, k, j);    /*找顶点k的前一个顶点j*/
}

void Dispath(int A[][MAXV], int path[][MAXV], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (A[i][j] == INF) {
                if (i != j)
                    printf("从%d到%d没有路径\n", i, j);
            } else {
                printf("  从%d到%d=>路径长度:%d 路径:", i, j, A[i][j]);
                printf("%d,", i);    //输出路径上的起点
                Ppath(path, i, j);    //输出路径上的中间点
                printf("%d\n", j);    //输出路径上的终点
            }
        }
}

void Floyd(MGraph g) {
    /********** Begin **********/

    int A[MAXV][MAXV], path[MAXV][MAXV];
    int i, j, k, n = g.n;
    for (i = 0; i < n; i++)    //给A数组置初值
        for (j = 0; j < n; j++) {
            A[i][j] = g.edges[i][j];
            path[i][j] = -1;
        }
    for (k = 0; k < n; k++) {    //计算Ak
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (A[i][j] > (A[i][k] + A[k][j])) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }

    /********** End **********/
    Dispath(A, path, g.n);   /*输出最短路径*/
}

int main() {
    int i, j;
    MGraph g;
    int n, e;
    int a[MAXV][MAXV];
    scanf("%d %d", &n, &e);
    g.n = n;
    g.e = e;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < g.n; i++)        /*建立图9.18所示的图的邻接矩阵*/
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = a[i][j];
    printf("各顶点的最短路径:\n");
    Floyd(g);
    return 0;
}
