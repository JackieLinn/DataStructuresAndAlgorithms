#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//二叉树的定义
typedef struct BinaryNode {
    int data;//数据
    int index;//在数组中的位置
    struct BinaryNode *leftChild, *rightChild;//左子树和右子树
} BinaryNode, *BinaryTree;

//创建二叉排序树
//tree：待构造的二叉树
//array：顺序表
//start：本次操作创建的子树在顺序表中的起始索引
//end：本次操作创建的子树在顺序表中的结束索引
void createBinarySortTree(BinaryTree tree, int array[], int start, int end) {
    /********* Begin *********/
    //从start到end中随机找一个数字作为根节点的索引
    int rootIndex = start == end ? start : (rand() % (end - start) + start);
    //对树根赋值
    tree->data = array[rootIndex];
    /********* End *********/
    tree->index = rootIndex;
    //当左子树中元素个数大于1
    if (start < rootIndex) {
        //给左子树分配空间
        tree->leftChild = (BinaryTree) malloc(sizeof(BinaryNode));
        //递归调用，生成左子树
        createBinarySortTree(tree->leftChild, array, start, rootIndex - 1);
    } else {
        //左子树中已经没有元素
        tree->leftChild = NULL;
    }
    //当右子树中元素个数大于1
    if (rootIndex < end) {
        //给右子树分配空间
        tree->rightChild = (BinaryTree) malloc(sizeof(BinaryNode));
        //递归调用，生成右子树
        createBinarySortTree(tree->rightChild, array, rootIndex + 1, end);
    } else {
        //右子树中已经没有元素
        tree->rightChild = NULL;
    }
    return;
}


//主函数
int main() {
    //顺序表
    int array[6];
    for (int i = 0; i < 6; i++) {
        scanf("%d", &array[i]);
    }
    //顺序表构造的次优静态查找树
    BinaryTree tree = (BinaryTree) malloc(sizeof(BinaryNode));
    //构造次优静态查找树
    createBinarySortTree(tree, array, 0, 5);
    printf("%d\n", tree->rightChild->rightChild->data);
    return 0;
}

//1 10 21 33 44 55