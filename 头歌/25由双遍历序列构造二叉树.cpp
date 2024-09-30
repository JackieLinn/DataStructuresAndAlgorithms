#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50
typedef char ElemType;
typedef struct node {
    ElemType data;              //数据元素
    struct node *lchild;        //指向左孩子结点
    struct node *rchild;        //指向右孩子结点
} BTNode;

//销毁树
void DestroyBTree(BTNode *&b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

//输出树
void DispBTree(BTNode *b) {
    if (b != NULL) {
        printf("%c", b->data);  // 打印当前节点的值
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");
            DispBTree(b->lchild);  // 遍历左子树
            if (b->rchild != NULL) {
                printf(",");
            }
            DispBTree(b->rchild);  // 遍历右子树
            printf(")");
        }
    }
}

//由先序序列和中序序列构造二叉树
BTNode *CreateBT1(char *pre, char *in, int n) {
    //pre存放先序序列，in存放中序序列，n为二叉树的结点个数
    //算法执行后返回构造二叉链的根结点
    /********** Begin **********/

    if (n <= 0) {
        return NULL;
    }

    BTNode *root = (BTNode *) malloc(sizeof(BTNode));
    root->data = pre[0];
    root->lchild = NULL;
    root->rchild = NULL;

    int rootIndex = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == pre[0]) {
            rootIndex = i;
            break;
        }
    }

    root->lchild = CreateBT1(pre + 1, in, rootIndex);
    root->rchild = CreateBT1(pre + rootIndex + 1, in + rootIndex + 1, n - rootIndex - 1);

    return root;

    /********** End **********/
}

//由中序序列和后序序列构造二叉树
BTNode *CreateBT2(char *post, char *in, int n) {
    //post存放后序序列，in存放中序序列，n为二叉树的结点个数
    //算法执行后返回构造二叉链的根结点
    /********** Begin **********/

    if (n <= 0) {
        return NULL;
    }

    BTNode *root = (BTNode *) malloc(sizeof(BTNode));
    root->data = post[n - 1];
    root->lchild = NULL;
    root->rchild = NULL;

    int rootIndex = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == post[n - 1]) {
            rootIndex = i;
            break;
        }
    }

    root->lchild = CreateBT2(post, in, rootIndex);
    root->rchild = CreateBT2(post + rootIndex, in + rootIndex + 1, n - rootIndex - 1);

    return root;

    /********** End **********/
}

int main() {
    BTNode *b1, *b2;
    int n;
    char pre[MaxSize], in[MaxSize], post[MaxSize];
    scanf("%s", pre);
    scanf("%s", in);
    scanf("%s", post);
    n = strlen(pre);
    b1 = CreateBT1(pre, in, n);
    b2 = CreateBT2(post, in, n);
    DispBTree(b1);
    printf("\n");
    DispBTree(b2);
    printf("\n");
    DestroyBTree(b1);
    DestroyBTree(b2);
    return 0;
}