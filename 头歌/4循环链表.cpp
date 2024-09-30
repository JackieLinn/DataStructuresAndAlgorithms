#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

/*
12 66 88 30 0
输出:
输入结点数据中...
--------循环链表初始元素------
12 	66 	88 	30
--------删除第二个结点后------
12 	88 	30
*/

#define ERROR 0
#define OK 1
typedef int EleType;
typedef struct CLinkNode {
    EleType data;
    struct CLinkNode *next;
} CLinkNode, *CLinkList;

/*
初始化循环链表
*/
int InitCLinkList(CLinkList *list) {
    if (list == NULL) {
        return ERROR;
    }

    int data = 0;
    CLinkNode *target = NULL;
    CLinkNode *head_node = NULL;
    printf("输入结点数据中...\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) {
            //退出循环标志，用户输入0 表示结束输入数据
            break;
        }

        if (*list == NULL) {
            CLinkNode *head = (CLinkNode *) malloc(sizeof(CLinkNode));
            //分配结点空间失败
            if (head == NULL) {
                exit(0);
            }

            *list = head;//链表指向头结点

            CLinkNode *node = (CLinkNode *) malloc(sizeof(CLinkNode));
            if (node == NULL) {
                exit(0);
            }
            node->data = data;
            node->next = head;
            head->next = node;
        } else {
            for (target = (*list)->next; target->next != *list; target = target->next);
            head_node = target->next;

            CLinkNode *node = (CLinkNode *) malloc(sizeof(CLinkNode));
            if (node == NULL) {
                exit(0);
            }
            node->data = data;
            node->next = head_node;

            target->next = node;//将新结点插入尾部
        }

    }
    return OK;
}

/*
往链表指定位置插入数据
list 循环链表
loc 第loc位置插入元素，loc 从1 开始计数
data 插入元素的数据域
*/
int InsertCLinkNode(CLinkList list, int loc, EleType data) {
    if (list == NULL || loc < 1)
        return ERROR;
    /*
    循环目的：找到第loc-1位置结点
    */
    int i = 1;
    CLinkNode *node = list;//刚开始node指向头结点
    while (node->next != list && i < loc) {
        node = node->next;
        i++;
    }
    if (i == loc) {
        CLinkNode *new_node = (CLinkNode *) malloc(sizeof(CLinkNode));
        if (new_node == NULL) {
            exit(0);
        }
        new_node->data = data;
        new_node->next = node->next;//新结点指针域 指向前驱结点的后继结点
        node->next = new_node;//将新结点加入链表
    } else {
        return ERROR;
    }

    return OK;
}

/*
删除指定结点，通过指针返回删除结点的数据，并保存至data
*/
int DelCLinkNode(CLinkList list, int loc, EleType *data) {
    if (list == NULL || loc < 1)
        return ERROR;
    /*
    循环目的：找到第loc-1位置结点
    */
    int i = 1;// 按人类的读法 i表示第i个位置 和 loc 表达意思一致
    CLinkNode *node = list;//刚开始node指向头结点
    while (node->next != list && i < loc) {
        node = node->next;
        i++;
    }
    //循环结束 node 指向 loc-1 位置 且 node 不能为尾结点,为什么不能为尾结点？因为不能删除 位置上没有元素的结点！
    if (i == loc && node->next != list) {
        // 请在下面的Begin-End之间补充代码，完成对结点的删除。
        /********** Begin *********/

        node->next = node->next->next;

        /********** End **********/

    }
    return OK;
}

/*
展示循环链表元素
*/
int ShowCLinkList(CLinkList list) {
    if (list == NULL) {
        return ERROR;
    }
    CLinkNode *target = NULL;

    for (target = list->next; target != list; target = target->next)
        printf("%d \t", target->data);
    printf("\n");
    return OK;
}

int main(int argc, char *argv[]) {
    int flag = 0;
    CLinkList list = NULL;
    list = NULL;
    InitCLinkList(&list);
    printf("--------循环链表初始元素------\n");
    ShowCLinkList(list);
    int loc = 2;
    int data = 0;
    DelCLinkNode(list, loc, &data);
    printf("--------删除第二个结点后------\n");
    ShowCLinkList(list);
    return 0;
}