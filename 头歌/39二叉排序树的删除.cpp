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
void initTree(BinaryTree tree, int data) {
    tree->data = data;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
}

//查找指定节点的前驱节点以及前驱节点的父节点
//tree：待查找的节点
//preParentNode：待查找的节点的前驱节点的父节点
//返回待查找的节点的前驱节点
BinaryTree searchPreNode(BinaryTree tree, BinaryTree *preParentNode) {
    //初始的时候，父节点就是待查找的节点
    *preParentNode = tree;
    //进入左子树
    BinaryTree preNode = tree->leftChild;
    //循环遍历右子树，直到走到空节点
    while (preNode->rightChild != NULL) {
        //在进入右子树之前，记录下父节点
        *preParentNode = preNode;
        //进入右子树
        preNode = preNode->rightChild;
    }
    return preNode;
}

//根据值找节点
//tree：查找树
//target：目标节点的值
//parentNode：目标节点的父节点
//返回目标节点
BinaryTree searchNode(BinaryTree tree, int target, BinaryTree *parentNode) {
    if (tree->data == target) {
        return tree;
    }
        //目标值大于根节点的值，进入右子树
    else if (tree->data < target) {
        *parentNode = tree;
        //递归查找
        return searchNode(tree->rightChild, target, parentNode);
    }
        //目标值大于根节点的值，进入左子树
    else {
        *parentNode = tree;
        //递归查找
        return searchNode(tree->leftChild, target, parentNode);
    }
}

//删除左右子树都为空的节点
void deleteBothEmpty(BinaryTree parentNode, int target) {
    //如果节点是父节点的左子树的根，则将父节点的左子树清空
    if (parentNode->leftChild != NULL && parentNode->leftChild->data == target) {
        parentNode->leftChild = NULL;
    }
        //如果节点是父节点的右子树的根，则将父节点的右子树清空
    else {
        parentNode->rightChild = NULL;
    }
}

//删除左右子树只有一个为空的节点
void deleteOneEmpty(BinaryTree targetNode, BinaryTree parentNode, int target) {
    //被删除节点是父节点的左子树
    if (parentNode->leftChild != NULL && parentNode->leftChild->data == target) {
        //将被删除节点的左子树挂到父节点的左子树上
        if (targetNode->leftChild != NULL) {
            parentNode->leftChild = targetNode->leftChild;
        }
            //将被删除节点的右子树挂到父节点的左子树上
        else {
            parentNode->leftChild = targetNode->rightChild;
        }
    }
        //被删除节点是父节点的右子树
    else {
        //将被删除节点的左子树挂到父节点的右子树上
        if (targetNode->leftChild != NULL) {
            parentNode->rightChild = targetNode->leftChild;
        }
            //将被删除节点的右子树挂到父节点的右子树上
        else {
            parentNode->rightChild = targetNode->rightChild;
        }
    }
}

//删除左右子树都不为空的节点
void deleteNotEmpty(BinaryTree targetNode, BinaryTree parentNode, int target) {
    //前驱节点的父节点的初始值
    BinaryTree preParentNode = targetNode;
    //找到前驱节点以及前驱节点的父节点
    BinaryTree preNode = searchPreNode(targetNode, &preParentNode);
    //先删除前驱节点和整棵树的连接
    deleteOneEmpty(preNode, preParentNode, preNode->data);
    //然后用前驱节点替代当前节点
    //替代的第一步是更换父节点的指针
    //替代的第二步是将子节点挂到前驱节点上
    //代码未给出，作为练习
    /********* Begin *********/
    targetNode->data = preNode->data;
    /********* End *********/
}


void binaryTreeDelete(BinaryTree tree, int target) {
    //待删除元素的父节点
    BinaryTree parentNode = tree;
    //首先找到待删除的元素所在的节点以及父节点
    BinaryTree targetNode = searchNode(tree, target, &parentNode);
    if (targetNode->leftChild == NULL && targetNode->rightChild == NULL) {
        deleteBothEmpty(parentNode, target);
    }
        //如果这个节点没有左子树，或者没有右子树
    else if (targetNode->leftChild == NULL || targetNode->rightChild == NULL) {
        deleteOneEmpty(targetNode, parentNode, target);
    } else {
        deleteNotEmpty(targetNode, parentNode, target);
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


//主函数
int main() {
    BinaryTree rootTree = (BinaryTree) malloc(sizeof(BinaryNode));
    initTree(rootTree, 100);
    BinaryTree rightRootTree = (BinaryTree) malloc(sizeof(BinaryNode));
    initTree(rightRootTree, 112);
    BinaryTree tree3 = (BinaryTree) malloc(sizeof(BinaryNode));
    initTree(tree3, 102);
    BinaryTree tree4 = (BinaryTree) malloc(sizeof(BinaryNode));
    initTree(tree4, 120);
    BinaryTree tree5 = (BinaryTree) malloc(sizeof(BinaryNode));
    initTree(tree5, 108);
    BinaryTree tree6 = (BinaryTree) malloc(sizeof(BinaryNode));
    initTree(tree6, 105);
    //构建二叉树
    rootTree->rightChild = rightRootTree;
    rightRootTree->leftChild = tree3;
    rightRootTree->rightChild = tree4;
    tree3->rightChild = tree5;
    tree5->leftChild = tree6;
    //删除节点
    int deleteNum;
    scanf("%d", &deleteNum);
    binaryTreeDelete(rootTree, deleteNum);
    middleSearch(rootTree);
    return 0;
}
