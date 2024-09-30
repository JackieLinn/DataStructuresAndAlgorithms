#include <stdio.h>
#include <stdlib.h>

#define MAXV 50
#define INF 32767

typedef int Vertex; // 假设 Vertex 是整数型，表示顶点的编号

typedef struct ArcNode {
    int adjvex;
    int info;
    struct ArcNode *nextarc;
} ArcNode;
typedef struct Vnode              /*邻接表头结点的类型*/
{
    Vertex data;                /*顶点信息*/
    int count;                     /*存放顶点入度,只在拓扑排序中用*/
    ArcNode *firstarc;             /*指向第一条弧*/
} VNode;
// MGraph 结构体定义
typedef struct {
    int n, e;             // 顶点数n和边数e
    int edges[MAXV][MAXV]; // 邻接矩阵存储边的信息
} MGraph;
typedef struct {
    VNode adjlist[MAXV];
    int n, e;
} ALGraph;


void MatToList(MGraph g, ALGraph *&G)
/*将邻接矩阵g转换成邻接表G*/
{
    int i, j, n = g.n;                        /*n为顶点数*/
    ArcNode *p;
    G = (ALGraph *) malloc(sizeof(ALGraph));
    for (i = 0; i < n; i++)                    /*给邻接表中所有头结点的指针域置初值*/
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < n; i++)                    /*检查邻接矩阵中每个元素*/
        for (j = n - 1; j >= 0; j--)
            if (g.edges[i][j] != 0)                /*邻接矩阵的当前元素不为0*/
            {
                p = (ArcNode *) malloc(sizeof(ArcNode));    /*创建一个结点*p*/
                p->adjvex = j;
                p->info = g.edges[i][j];
                p->nextarc = G->adjlist[i].firstarc;        /*将*p链到链表后*/
                G->adjlist[i].firstarc = p;
            }
    G->n = n;
    G->e = g.e;
}

void ListToMat(ALGraph *G, MGraph &g)
/*将邻接表G转换成邻接矩阵g*/
{
    int i, n = G->n;
    ArcNode *p;
    for (i = 0; i < n; i++) {
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            g.edges[i][p->adjvex] = p->info;
            p = p->nextarc;
        }
    }
    g.n = n;
    g.e = G->e;
}

void DispMat(MGraph g)
/*输出邻接矩阵g*/
{
    int i, j;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] == INF)
                printf("%3s", "∞");
            else
                printf("%3d", g.edges[i][j]);
        printf("\n");
    }
}

//拓扑排序
void TopSort(ALGraph *G) {

    int i, j;
    int St[MAXV], top = -1;              /*栈St的指针为top*/
    ArcNode *p;
    for (i = 0; i < G->n; i++)            /*入度置初值0*/
        G->adjlist[i].count = 0;
    for (i = 0; i < G->n; i++)            /*求所有顶点的入度*/
    {
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            G->adjlist[p->adjvex].count++;
            p = p->nextarc;
        }
    }
    for (i = 0; i < G->n; i++)
        if (G->adjlist[i].count == 0)  /*入度为0的顶点进栈*/
        {
            top++;
            St[top] = i;
        }
    while (top > -1)                     /*栈不为空时循环*/
    {
        /********** Begin **********/

        i = St[top];        // 出栈
        top--;
        printf("%d ", i);   // 输出顶点
        p = G->adjlist[i].firstarc;
        while (p != NULL) { // 对i号顶点的每个邻接点的入度减1
            j = p->adjvex;
            G->adjlist[j].count--;
            if (G->adjlist[j].count == 0) { // 若减到0则入栈
                top++;
                St[top] = j;
            }
            p = p->nextarc;
        }

        /********** End **********/
    }
}

int main() {
    int i, j;
    MGraph g;
    ALGraph *G;
    int n, e;
    int A[MAXV][MAXV];
    scanf("%d %d", &n, &e);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    g.n = n;
    g.e = e;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = A[i][j];
    G = (ALGraph *) malloc(sizeof(ALGraph));
    MatToList(g, G);
    TopSort(G);
    printf("\n");
}
