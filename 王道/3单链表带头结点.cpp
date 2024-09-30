#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//打印链表的函数
void print(LinkList &list) {
    LinkList p = list->next;
    if (p == NULL) {
        printf("这是一个空表，还没有元素！\n");
        return;
    }
    printf("链表为：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//初始化函数
bool InitList(LinkList &list) {
    list = (LNode *) malloc(sizeof(LNode));//分配一个头结点
    //list = new LNode();
    if (list == NULL) return false;//内存不足，分配失败
    list->next = NULL;//头结点之后暂时还没有结点
    return true;
}

//前插操作，在结点p之前插入结点s
bool InsertPriorNode(LNode *p, LNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    p->next = s;
    int temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

//指定结点的后插操作,插入元素e
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *temp = (LNode *) malloc(sizeof(LNode));
    if (temp == NULL) return false;//内存分配失败
    temp->next = p->next;
    p->next = temp;
    temp->data = e;
    return true;
}

//按位序插入，在第i个位置插入值e
bool ListInsert(LinkList &list, int i, int e) {
    if (i < 1) return false;
    LNode *p = list;//指针p当前扫描到的结点
    int j = 0;//表示j是当前p指向的第几个结点
//    p = list;
    while (p != NULL && j < i - 1) {//循环找到第i-1个结点
        p = p->next;
        j++;
    }
    /* 此处可以进行封装，封装进函数InsertNextNode，提高代码复用性
    * if (p == NULL) return false;
    LNode* temp = (LNode*)malloc(sizeof(LNode));
    temp->next = p->next;
    p->next = temp;
    temp->data = e;
    return true;
    */
    return InsertNextNode(p, e);//注意，如果不写函数头这个得放在这个函数的前面
}

//按位序删除结点函数
bool ListDelete(LinkList &list, int i, int &e) {
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = list;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

int main() {
    LinkList list;//声明一个指向单链表的指针
    //初始化带头结点的单链表，防止脏数据
    InitList(list);
    print(list);

    //直接插入法
    LinkList l1 = (LNode *) malloc(sizeof(LNode));
    list->next = l1;
    l1->data = 3;
    l1->next = NULL;
    print(list);

    //按位序插入
    if (ListInsert(list, 2, 7)) {
        printf("插入成功！新链表为：");
        print(list);
    } else printf("插入失败，请检查输入是否正确！\n");

    //前插操作，由于该程序限制，只测试在头结点的前插
    LinkList l2 = (LNode *) malloc(sizeof(LNode));
    LNode *p;
    p = list;
    p = p->next;
    l2->data = 4;
    l2->next = NULL;
    if (InsertPriorNode(p, l2)) { //不能直接传头结点插入，头结点是没有值域的，得头结点的下一个
        printf("前插插入成功！新链表为：");
        print(list);
        printf("\n");
    } else printf("前插插入失败，请检查输入是否正确！\n");
    //free(p);

    //按位序删除
    int e = -1;//用e将删除的数据带出来
    if (ListDelete(list, 3, e)) {
        printf("删除成功！删除的元素为 %d\n", e);
        printf("删除后的新链表为：");
        print(list);
    } else printf("删除失败，请检查输入是否正确！\n");

    //按指定结点删除
    return 0;
}