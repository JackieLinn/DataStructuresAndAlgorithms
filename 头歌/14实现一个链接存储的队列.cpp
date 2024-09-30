#include <stdio.h>
#include <stdlib.h>
#include "CLnkQueue.h"

LNode* CLQ_Create()
// 创建一个队列
{
    LNode* rear=(LNode*)malloc(sizeof(LNode));
    rear->data = 0;
    rear->next = rear;
    return rear;
}
void CLQ_Free(LNode* rear)
// rear指向尾结点
{
    CLQ_MakeEmpty(rear);
    free(rear);
}

void CLQ_MakeEmpty(LNode* & rear)
// rear指向尾结点
// 将队列变为空队列
{
    T item;
    while(!CLQ_IsEmpty(rear))
        CLQ_Out(rear,item);
}

bool CLQ_IsEmpty(LNode* rear)
// 判断队列是否为空
{
    // 请在这里补充代码，完成本关任务

    return rear->next->data==0;
    //return rear->next->next==rear->next;

}

int CLQ_Length(LNode* rear)
// 返回队列长度，rear指向尾结点
{
    // 请在这里补充代码，完成本关任务

    return rear->next->data;

}

void CLQ_In(LNode* & rear, T x)
// 入队列, 新结点加入链表尾部。rear指向尾结点
{
    // 请在这里补充代码，完成本关任务

    LNode*node=(LNode*)malloc(sizeof(LNode));
    node->data=x;
    node->next=rear->next;
    rear->next=node;
    rear=node;
    rear->next->data++;

}

bool CLQ_Out(LNode* & rear, T& item)
// 出队列。空队列时，返回值为false。rear指向尾结点
{
    if(CLQ_IsEmpty(rear)){
        return false;
    }
    if(rear->next->next==rear){
        LNode*node=rear;
        item=rear->data;
        rear->next->next=rear->next;
        rear=rear->next;
        free(node);
    }else{
        item=rear->next->next->data;
        LNode*node=rear->next->next;
        rear->next->next=node->next;
        free(node);

    }
    rear->next->data--;
    return true;

}

bool CLQ_Head(LNode* rear, T& item)
// rear指向尾结点
// 获取队列头。空队列时返回值为false。
{
    if (CLQ_IsEmpty(rear))
        return false;

    item = rear->next->next->data;
    return true;
}
void CLQ_Print(LNode* rear)
// 打印队列
{
    if (CLQ_IsEmpty(rear))  {
        printf("The queue is: empty. \n");
        return;
    }
    LNode* node=rear->next->next;
    do {
        printf("%d  ", node->data);
        node = node->next;
    }   while (node != rear->next);
    //printf("\n");
}

