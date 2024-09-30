#include <stdio.h>
#include <stdlib.h>

//该代码用头插法和尾插法建立两个带头结点的单链表，并进行一系列的操作

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//专门打印链表的函数
void PrintList(LinkList &list) {
    LinkList p = list->next;
    if (p == NULL) printf("该链表为空！请先为其增添元素！\n");
    else {
        printf("链表为: ");
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
    free(p);
}

//头插法建立单链表
LinkList List_HeadCreate(LinkList &list) {
    LNode *p;    //用来每次插入的结点
    int x;    //链表插入的值
    list = (LinkList) malloc(sizeof(LNode));    //为list先分配一个头结点
    list->next = NULL;
    scanf("%d", &x);
    while (x != 999) {    //输入到999的时候停止输入，自定义一个停止的值
        p = (LNode *) malloc(sizeof(LNode));
        p->data = x;
        p->next = list->next;
        list->next = p;
        scanf("%d", &x);
    }
    return list;
}

//尾插法建立单链表
LinkList List_TailCreate(LinkList &list) {
    LNode *p;    //用来每次插入的结点
    int x;    //链表插入的值
    list = (LinkList) malloc(sizeof(LNode));    //为list先分配一个头结点
    LNode *q = list;    //q为表尾指针
    scanf("%d", &x);
    while (x != 999) {
        p = (LNode *) malloc(sizeof(LNode));
        p->data = x;
        q->next = p;
        q = p;
        scanf("%d", &x);
    }
    q->next = NULL;
    return list;
}

//插入操作，在位置i插入元素e
bool List_Insert(LinkList &list, int i, int e) {
    if (i < 1) return false;
    LNode *p = list;    //表示当前扫描到的结点
    int j = 0;     //当前p指向的是第几个结点
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;    //是要在p的后面插入，如果p为NULL就没有插入的必要了
    LNode *temp = (LNode *) malloc(sizeof(LNode));
    if (temp == NULL) return false;    //内存分配失败
    temp->data = e;
    temp->next = p->next;
    p->next = temp;
    return true;
}

//删除操作，删除位置i的元素并用e将其带出来
bool List_Delete(LinkList &list, int i, int &e) {
    if (i < 1) return false;
    LNode *p = list;    //表示当前扫描到的结点
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) return false;    //要删p的下一个，如果本身和下一个为NULL则没有删除的必要
    e = p->next->data;
    p->next = p->next->next;
    return true;
}

int main() {
    //先用头插法来建立一个单链表list1
    LinkList list1 = List_HeadCreate(list1);
    PrintList(list1);
    printf("%d", list1->next->data);
    //然后用尾插法来建立一个单链表list2
    LinkList list2 = List_TailCreate(list2);
    PrintList(list2);
    //对list1在位置i插入元素e，此处注意前插和后插的区别，如果是前插的话执行后插并交换值即可
    if (List_Insert(list1, 2, 8)) {
        printf("插入成功！新链表为: ");
        PrintList(list1);
    } else printf("插入失败！请检查输入是否正确！\n");
    //对list2删除在位置i的元素，并用e将其带出来
    int e = 0;
    if (List_Delete(list2, 2, e)) {
        printf("删除成功！删除的元素为: %d ! 新链表为: ", e);
        PrintList(list2);
    } else printf("删除失败！请检查输入是否正确！\n");
    return 0;
}