#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//二叉树的定义
typedef struct BinaryNode {
    int data;//数据
    int balance;//节点的平衡因子
    struct BinaryNode *leftChild, *rightChild;//左子树和右子树
} BinaryNode, *BinaryTree;

//左旋转
//对以p为根结点的树左旋，同时使得p指针指向新的根结点
void leftRotate(BinaryTree *p) {
    //右节点，新的树根节点
    BinaryTree rightNode = (*p)->rightChild;
    //原来的根的右节点，是新根的左节点
    (*p)->rightChild = rightNode->leftChild;
    rightNode->leftChild = *p;
    *p = rightNode;
}

//右旋转
//对以p为根结点的树右旋，同时使得p指针指向新的根结点
void rightRotate(BinaryTree *p) {
    /********* Begin *********/
    BinaryTree leftNode = (*p)->leftChild;
    //原来的根的右节点，是新根的左节点
    (*p)->leftChild = leftNode->rightChild;
    leftNode->rightChild = *p;
    *p = leftNode;
    /********* End *********/
}


//左子树比右子树的高度大2
void balanceLeftTree(BinaryTree *tree) {
    //左子树，左子树的右子树
    BinaryTree leftNode, leftRightNode;
    //左子树赋值
    leftNode = (*tree)->leftChild;
    //如果左子树的左子树比右子树高1，说明是新节点是插入在了左子树的左子树上
    if (leftNode->balance == 1) {
        (*tree)->balance = leftNode->balance = 0;
        //对整个书右旋即可
        rightRotate(tree);
    }
    //如果左子树的左子树比右子树矮1，说明是新节点是插入在了左子树的右子树上
    if (leftNode->balance == -1) {
        leftRightNode = leftNode->rightChild;
        if (leftRightNode->balance == 1) {
            (*tree)->balance = -1;
            leftNode->balance = 0;
        } else if (leftRightNode->balance == -1) {
            (*tree)->balance = 0;
            leftNode->balance = 1;
        } else {
            (*tree)->balance = leftNode->balance = 0;
        }
        leftRightNode->balance = 0;
        //对左子树进行左旋，并将tree调整为左旋完成后左子树的根节点
        leftRotate(&(*tree)->leftChild);
        //右旋
        rightRotate(tree);
    }

}

//RR旋转
//右子树的平衡处理同左子树的平衡处理完全类似
void balanceRightTree(BinaryTree *tree) {
    BinaryTree leftNode, leftLeftNode;
    leftNode = (*tree)->rightChild;
    if (leftNode->balance == -1) {
        (*tree)->balance = leftNode->balance = 0;
        leftRotate(tree);
    }
    if (leftNode->balance == 1) {
        leftLeftNode = leftNode->leftChild;
        if (leftLeftNode->balance == 1) {
            (*tree)->balance = 0;
            leftNode->balance = -1;
        } else if (leftLeftNode->balance == 0) {
            (*tree)->balance = leftNode->balance = 0;
        } else {
            (*tree)->balance = 0;
            leftNode->balance = 1;
        }
        leftLeftNode->balance = 0;
        rightRotate(&(*tree)->rightChild);
        leftRotate(tree);
    }
}

insertAVLTree(BinaryTree
* tree,
int data,
int *isTaller
)
{
//如果是空树，则新建
if ((*tree) == NULL)
{
//分配空间
(*tree) = (BinaryTree)malloc(sizeof(BinaryNode));
//初始化平衡因子为0
(*tree)->
balance = 0;
//初始化数据
(*tree)->
data = data;
(*tree)->
leftChild = NULL;
(*tree)->
rightChild = NULL;
//树的高度增加了
*
isTaller = 1;
}
//如果待插入的数据小于根节点的数据
else if (data < (*tree)->data)
{
//插入到左子树中
insertAVLTree(&(*tree)
->leftChild, data, isTaller);
//如果插入使得左子树变高
if (*isTaller)
{
//如果本来左子树就比右子树高1，则现在左子树比右子树高2
if ((*tree)->balance == 1) {
//需要对整个树进行平衡调整（左旋和先左旋再右旋）
balanceLeftTree(tree);
//树高度不变（平衡之前树的高度比原来大了1，平衡之后又恢复了）
*
isTaller = 0;
}
//如果本来左子树和右子树一样高，则现在左子树比右子树高1
else if ((*tree)->balance == 0) {
//平衡因子加1
(*tree)->
balance = 1;
//树高度增加
*
isTaller = 1;
}
//如果本来左子树就比右子树矮1
else {
//平衡因子变为0
(*tree)->
balance = 0;
//树高度不变
*
isTaller = 0;
}
}

}
//和上面完全对称
else
{
insertAVLTree(&(*tree)
->rightChild, data, isTaller);
if (*isTaller)
{
if ((*tree)->balance == 1) {
(*tree)->
balance = 0;
*
isTaller = 0;
}
else if ((*tree)->balance == 0) {
(*tree)->
balance = -1;
*
isTaller = 1;
}
else {
balanceRightTree(tree);
*
isTaller = 0;
}
}
}
}

void middleSearch(BinaryTree rootTree) {
    if (rootTree->leftChild != NULL) {
        middleSearch(rootTree->leftChild);
    }
    printf("%d ", rootTree->data);
    if (rootTree->rightChild != NULL) {
        middleSearch(rootTree->rightChild);
    }
}

//求树高
int getTreeHeight(BinaryTree tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int leftHeight = getTreeHeight(tree->leftChild);
        int rightHeight = getTreeHeight(tree->rightChild);
        int res = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
        return res;
    }
}

//是否是AVL树
//0否1是
int isAVLTree(BinaryTree tree) {
    if (tree == NULL) {
        return 1;
    }
    int leftHeight = getTreeHeight(tree->leftChild);
    int rightHeight = getTreeHeight(tree->rightChild);
    if (1 >= abs(leftHeight - rightHeight) && isAVLTree(tree->leftChild) && isAVLTree(tree->rightChild)) {
        return 1;
    }
    return 0;

}

int main() {
    //数组
    int array[6];
    for (int i = 0; i < 6; i++) {
        scanf("%d", &array[i]);
    }
    //树的根节点
    BinaryTree tree = NULL;
    //树在插入完成之后是否增高了，1是0否
    int isTaller;
    //构建AVL树
    for (int i = 0; i < 6; i++) {
        insertAVLTree(&tree, array[i], &isTaller);
    }
    printf("%d\n", isAVLTree(tree));
}
