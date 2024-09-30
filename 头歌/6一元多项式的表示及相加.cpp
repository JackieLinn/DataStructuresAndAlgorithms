#include <stdio.h>
#include <stdlib.h>

/*
3
8 1
2 3
9 9
2
1 2
4 5
输出:
La=8x+2x^3+9x^9
Lb=x^2+4x^5
计算结果为：
Lc=8x+x^2+2x^3+4x^5+9x^9
*/

typedef struct PLnode {
    //数据域，coef 表示系数，expn 表示指数
    float coef;
    int expn;
    //指针域
    struct PLnode *next;
} PLnode, *PLinkList;

//一元多项式的链表表示创建函数，输入 m 项的系数和指数，建立表示一元多项式的有序链表L
void creatpolyn(PLinkList L, int m) {
    int i;
    float coef;
    int expn;
    PLinkList tail, n;
    L->coef = m;
    L->expn = -1;
    tail = L;
    for (i = 1; i <= m; i++) {
        n = (PLinkList) malloc(sizeof(PLnode));
        scanf("%f", &coef);
        scanf("%d", &expn);
        n->coef = coef;
        n->expn = expn;
        n->next = NULL;
        tail->next = n;
        tail = n;
    }
}

//完成多项式相加运算，即 Lc = La + Lb，并销毁一元多项式 Lb
PLinkList addpolyn(PLinkList La, PLinkList Lb) {
    int x, len;
    float y;
    PLinkList Lc, pa, pb, pc, u;
    Lc = La;
    len = 0;
    pc = Lc;
    //另pa，pb 指向La 、Lb 的首元结点
    pa = La->next;
    pb = Lb->next;
    //通过 pa，pb 遍历链表 La、Lb，只有两指针同时存在时，才需要讨论
    while (pa && pb) {
        x = pa->expn - pb->expn;
        //判断pa 所指结点的指数与pb 所指结点指数的大小关系
        if (x < 0) {
            //如果小，则找去 qa 结点到Lc 上
            pc = pa;
            len++;
            pa = pa->next;
        }
            //如果相等，则判断两结点的系数和是否为0
        else if (x == 0) {
            // 请在下面的Begin-End之间补充代码，完成一元多项式的相加。
            /********** Begin *********/

            pa->coef = pa->coef + pb->coef;
            pc = pa;
            len++;
            pa = pa->next;
            pb = pb->next;

            /********** End **********/
        }
            //如果pb 所指结点指数值小，则摘取pb所指结点到 LC链表上
        else {
            u = pb->next;
            pb->next = pa;
            pc->next = pb;
            pc = pb;
            len++;
            pb = u;
        }
    }
    //由于是在 La 上进行一元多项式的加和，所以如果运行过程 pa 不再有结点，而pb 上有，则需要将pb剩余结点链接到 Lc 上
    if (pb) {
        pc->next = pb;
    }
    //计算 Lc 的长度
    while (pc) {
        pc = pc->next;
        if (pc) {
            len++;
        }
    }
    //Lc 的头结点中记录Lc 链表的长度
    Lc->coef = len;
    //加和完成的同时，释放Lb 结点
    free(Lb);
    return Lc;
}

//根据链表存储信息。输出结点 q
void printpoly(PLinkList q) {
    if (q->expn == 0) {
        printf("%.0f", q->coef);
    } else if (q->expn == 1) {
        if (q->coef == 1) {
            printf("x");
        } else if (q->coef == -1) {
            printf("-x");
        } else {
            printf("%.0f", q->coef);
            printf("x");
        }
    } else if (q->coef == 1) {
        printf("x^%d", q->expn);
    } else if (q->coef == -1) {
        printf("-x^%d", q->expn);
    } else {
        printf("%.0fx^%d", q->coef, q->expn);
    }
}

//输出一元多项式L
void printpolyn(PLinkList L) {
    int n;
    PLinkList p;
    p = L->next;
    n = 0;
    while (p) {
        n++;
        if (n == 1) {
            printpoly(p);
        } else if (p->coef > 0) {
            printf("+");
            printpoly(p);
        } else {
            printpoly(p);
        }
        p = p->next;
    }
}

int main() {
    PLinkList La, Lb, Lc;
    int m, n;
    //根据 n 的值，创建链表La
    scanf("%d", &n);
    La = (PLinkList) malloc(sizeof(PLnode));
    creatpolyn(La, n);
    //根据 m 的值，创建 Lb
    scanf("%d", &m);
    Lb = (PLinkList) malloc(sizeof(PLnode));
    creatpolyn(Lb, m);
    //输出La和Lb
    printf("La=");
    printpolyn(La);
    printf("\nLb=");
    printpolyn(Lb);
    //计算La+Lb，结果保存在 Lc中
    printf("\n计算结果为：");
    Lc = addpolyn(La, Lb);
    printf("\nLc=");
    printpolyn(Lc);
    return 0;
}