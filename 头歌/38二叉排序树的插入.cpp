#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//二叉树的定义
typedef struct BinaryNode {
    int data;//数据
    int index;//在数组中的位置
    struct BinaryNode *leftChild, *rightChild;//左子树和右子树
} BinaryNode, *BinaryTree;

//初始化二叉树
void initBinaryTree(BinaryTree tree) {
    tree->data = -1;
    tree->index = -1;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
}

//创建二叉排序树
//tree：待构造的二叉树
//target：待插入的元素
//index：待插入元素在数组中的索引
int binaryTreeInsert(BinaryTree tree, int target, int index) {
    if (tree->data == -1) {
        tree->data = target;
        tree->index = index;
        return -1;
    } else {
        if (target > tree->data) {
            //待插入元素大于当前子树的根节点，进入右子树
            if (tree->rightChild == NULL) {
                //如果右子树不存在，构建右子树
                tree->rightChild = (BinaryTree) malloc(sizeof(BinaryNode));
                //初始化右子树
                initBinaryTree(tree->rightChild);
            }
            //递归插入右子树中
            return binaryTreeInsert(tree->rightChild, target, index);
        } else if (target < tree->data) {
            /********* Begin *********/
            if (tree->leftChild == NULL) {
                //如果左子树不存在，构建左子树
                tree->leftChild = (BinaryTree) malloc(sizeof(BinaryNode));
                //初始化右子树
                initBinaryTree(tree->leftChild);
            }
            //递归插入右子树中
            return binaryTreeInsert(tree->leftChild, target, index);
            /********* End *********/
        } else {
            /********* Begin *********/
            return tree->index;
            /********* End *********/
        }
    }
}

//主函数
int main() {
    int array[7];
    for (int i = 0; i < 7; i++) {
        scanf("%d", &array[i]);
    }
    BinaryTree tree = (BinaryTree) malloc(sizeof(BinaryNode));;
    initBinaryTree(tree);
    for (int i = 0; i < 7; i++) {
        printf("%d\n", binaryTreeInsert(tree, array[i], i));
    }
    return 0;
}
