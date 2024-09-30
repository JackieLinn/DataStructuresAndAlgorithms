#include <stdio.h>

typedef struct node {
    int data;           //结点对应人的编号
    int rank;           //结点对应秩
    int parent;         //结点对应双亲下标
} UFSTree;

/*
7
2 4
5 7
1 3
8 9
1 2
5 6
2 3
3 4
*/

#define MaxSize 100
#define N 100
#define M 100

//初始化并查集树
void MAKE_SET(UFSTree t[]) {
    int i;
    for (i = 1; i <= N; i++) {
        t[i].data = i;                      //数据为该人的编号
        t[i].rank = 0;                      //秩初始化为0
        t[i].parent = i;                    //双亲初始化指向自已
    }
}

//在x所在子树中查找集合编号
int FIND_SET(UFSTree t[], int x) {
    if (x != t[x].parent)                   //双亲不是自已
        return (FIND_SET(t, t[x].parent));  //递归在双亲中找x
    else
        return (x);                        //双亲是自已,返回x
}

//将x和y所在的子树合并
void UNION(UFSTree t[], int x, int y) {
    /********** Begin **********/

    int rootX = FIND_SET(t, x);
    int rootY = FIND_SET(t, y);

    if (rootX == rootY)
        return;

    if (t[rootX].rank > t[rootY].rank) {
        t[rootY].parent = rootX;
    } else {
        t[rootX].parent = rootY;
        if (t[rootX].rank == t[rootY].rank)
            t[rootY].rank++;
    }

    /********** End **********/
}

int main() {
    int i, x, y, n, a, b;
    UFSTree t[MaxSize];
    int rel[M][2];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &rel[i][0], &rel[i][1]);
    }
    scanf("%d %d", &a, &b);
    MAKE_SET(t);                                //初始化并查集树t
    for (i = 0; i < n; i++)                           //根据关系进行合并操作
        UNION(t, rel[i][0], rel[i][1]);
    x = FIND_SET(t, a);
    y = FIND_SET(t, b);
    if (x == y)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
