#include <stdio.h>
#include <stdlib.h>

#define MAXV 50
#define INF 32767
typedef struct ANode {
    int adjvex;                 //该边的邻接点编号
    struct ANode *nextarc;      //指向下一条边的指针
    int weight;                 //该边的相关信息，如权值（这里用整型表示）
} ArcNode;                       //边结点类型
typedef struct Vnode {
    //InfoType info             //顶点的其他信息
    ArcNode *firstarc;          //指向第一个边结点
} VNode;
typedef struct {
    VNode adjlist[MAXV];        //邻接表的头结点数组
    int n, e;                    //图中的顶点数n和边数e
} AdjGraph;                     //完整的图邻接表类型

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)  //创建图的邻接表
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)                                        //给邻接表的头元素的指针域置初值
    {
        G->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i++)                                        //检查邻接表的每个元素
    {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 && A[i][j] != INF)                    //存在一条边
            {
                p = (ArcNode *) malloc(sizeof(ArcNode));       //创建一个结点p
                p->adjvex = j;                                //存放邻接点
                p->weight = A[i][j];                          //存放权
                p->nextarc = G->adjlist[i].firstarc;          //采用头插法插入结点p
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void DispAdj(AdjGraph *G) {
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++) {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL) {
            printf("%d[%d]→", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("^\n");
    }
}

void DestroyAdj(AdjGraph *&G) {
    int i;
    ArcNode *pre, *p;
    for (i = 0; i < G->n; i++)                 //扫描所有单链表
    {
        pre = G->adjlist[i].firstarc;     //p指向第i个单链表的头结点
        if (pre != NULL) {
            p = pre->nextarc;
            while (p != NULL)              //释放第i个单链表的所有结点
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

//广度优先遍历
void BFS(AdjGraph *G, int v) {
    /********** Begin **********/

    int visited[MAXV] = {0}; // 标记节点是否被访问过，初始化为0（未访问）

    int queue[MAXV]; // 队列用于存储待访问的节点
    int front = 0, rear = 0; // 队列的头尾指针

    ArcNode *p;
    int w;

    printf("%d ", v); // 访问起始节点
    visited[v] = 1; // 标记起始节点已访问

    queue[rear++] = v; // 将起始节点入队

    while (front != rear) { // 当队列不为空时
        v = queue[front++]; // 出队
        p = G->adjlist[v].firstarc;

        while (p != NULL) { // 遍历该节点的邻接节点
            w = p->adjvex;
            if (!visited[w]) { // 若邻接节点未访问过
                printf("%d ", w); // 访问该节点
                visited[w] = 1; // 标记为已访问
                queue[rear++] = w; // 入队
            }
            p = p->nextarc;
        }
    }

    /********** End **********/
}

int main() {
    int i, j, n, e;
    int A[MAXV][MAXV];
    scanf("%d %d", &n, &e);
    AdjGraph *G;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    CreateAdj(G, A, n, e);
    BFS(G, 0);
    printf("\n");
    DestroyAdj(G);
    return 0;
}