#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef char ElemType;
typedef struct node {
    ElemType data;              //数据元素
    struct node *lchild;        //指向左孩子结点
    struct node *rchild;        //指向右孩子结点
} BTNode;

//创建二叉树
void CreateBTree(BTNode *&b, char *str) {
    BTNode *St[MaxSize], *p;//St数组作为顺序栈
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
                p = (BTNode *) malloc(sizeof(BTNode));  //创建一个结点由p指向它
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

//销毁树
void DestroyBTree(BTNode *&b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

//先序遍历
void PreOrder(BTNode *b) {
    /********** Begin **********/

    if (b != NULL) {
        printf("%c", b->data);  // Print the data of the current node
        PreOrder(b->lchild);   // Traverse the left subtree
        PreOrder(b->rchild);   // Traverse the right subtree
    }

    /********** End**********/
}

//中序遍历
void InOrder(BTNode *b) {
    /********** Begin **********/

    if (b != NULL) {
        InOrder(b->lchild);   // Traverse the left subtree
        printf("%c", b->data);  // Print the data of the current node
        InOrder(b->rchild);   // Traverse the right subtree
    }

    /********** End **********/
}

//后续遍历
void PostOrder(BTNode *b) {
    /********** Begin **********/

    if (b != NULL) {
        PostOrder(b->lchild);   // Traverse the left subtree
        PostOrder(b->rchild);   // Traverse the right subtree
        printf("%c", b->data);  // Print the data of the current node
    }

    /********** End **********/
}

int main() {
    BTNode *b;
    char str[100];
    scanf("%s", str);
    CreateBTree(b, str);
    PreOrder(b);
    printf("\n");
    InOrder(b);
    printf("\n");
    PostOrder(b);
    printf("\n");
    DestroyBTree(b);
    return 0;
}