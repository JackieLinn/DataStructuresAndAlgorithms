#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef char ElemType;
typedef struct node {
    ElemType data;          //结点数据域
    int ltag, rtag;          //增加的线索标记
    struct node *lchild;    //左孩子或线索指针
    struct node *rchild;    //右孩子或线索指针
} TBTNode;

TBTNode *pre;                   //全局变量

//创建二叉树
void CreateTBTNode(TBTNode *&b, char *str) {
    TBTNode *St[MaxSize], *p;//St数组作为顺序栈
    int top = -1, k, j = 0;//top作为栈顶指针
    char ch;
    b = NULL;//初始时二叉链为空
    ch = str[j];
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break; //处理左孩子
            case ')':
                top--;
                break;               //栈顶的子树处理完毕
            case ',':
                k = 2;
                break;                 //开始处理右孩子
            default:
                p = (TBTNode *) malloc(sizeof(TBTNode));  //创建一个结点由p指向它
                p->data = ch;                         //存放结点值
                p->lchild = p->rchild = NULL;           //左右指针都置为空
                if (b == NULL)                         //若尚未建立根结点
                {
                    b = p;                            //b所指结点作为根结点
                } else                                //已建立二叉树根结点
                {
                    switch (k) {
                        case 1:
                            St[top]->lchild = p;
                            break;     //新建结点作为栈顶左孩子
                        case 2:
                            St[top]->rchild = p;
                            break;     //新建结点作为栈顶右孩子
                    }
                }
        }
        j++;                                                //继续扫描str
        ch = str[j];
    }

}

//输出树
void DispTBTNode(TBTNode *b) {
    if (b != NULL) {
        printf("%c", b->data);  // 打印当前节点的值
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispTBTNode(b->lchild);  // 遍历左子树
            if (b->rchild != NULL) {
                printf(",");
            }
            DispTBTNode(b->rchild);  // 遍历右子树
            printf(")");
        }
    }
}

//对二叉排序树进行线索化
void Thread(TBTNode *&p) {
    if (p != NULL) {
        Thread(p->lchild);      //左孩子线索化
        if (p->lchild == NULL)     //左孩子不存在，进行前驱结点线索化
        {
            p->lchild = pre;      //建立当前结点的前驱结点线索
            p->ltag = 1;
        } else {
            p->ltag = 0;          //p结点的左子树已线索化
        }
        if (pre->rchild == NULL)   //对pre的后继结点线索化
        {
            pre->rchild = p;      //建立前驱结点的后继结点线索
            pre->rtag = 1;
        } else {
            pre->rtag = 0;
        }
        pre = p;
        Thread(p->rchild);      //右子树线索化
    }
}

//中序线索化二叉树
TBTNode *CreateThread(TBTNode *b) {
    /********** Begin **********/

    TBTNode *tb = (TBTNode *) malloc(sizeof(TBTNode));
    tb->ltag = 0;
    tb->rtag = 1;
    tb->rchild = tb;
    if (b == NULL) {
        tb->lchild = tb;
    } else {
        tb->lchild = b;
        pre = tb;
        Thread(b);
        pre->rchild = tb;
        pre->rtag = 1;
        tb->rchild = pre;
    }
    return tb;

    /********** End **********/
}

//遍历线索化二叉树
void ThInOrder(TBTNode *tb) {
    TBTNode *p = tb->lchild;                      //p指向根结点
    while (p != tb) {
        while (p->ltag == 0)p = p->lchild;           //找开始结点
        printf("%c", p->data);                   //访问开始结点
        while (p->rtag == 1 && p->rchild != tb) {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}

int main() {
    TBTNode *b, *tb;
    char str[MaxSize];
    scanf("%s", str);
    CreateTBTNode(b, str);
    DispTBTNode(b);
    printf("\n");
    tb = CreateThread(b);
    ThInOrder(tb);
    printf("\n");
    return 0;
}