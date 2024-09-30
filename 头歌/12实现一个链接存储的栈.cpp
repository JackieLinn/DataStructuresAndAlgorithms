#include <stdio.h>
#include <stdlib.h>

typedef int T; // 栈元素的数据类型

struct LNode {
    T data;
    LNode *next;
};

struct LinkStack {
    LNode *top; // 栈顶指针
    int len; // 栈的长度
};

/*创建栈*/
LinkStack *LS_Create() {
    LinkStack *ls = (LinkStack *) malloc(sizeof(LinkStack));
    ls->top = NULL;
    ls->len = 0;
    return ls;
}

/*释放栈*/
void LS_Free(LinkStack *ls) {
    LNode *curr = ls->top;
    while (curr) {
        LNode *next = curr->next;
        free(curr);
        curr = next;
    }
    free(ls);
}

/*将栈变为空栈*/
void LS_MakeEmpty(LinkStack *ls) {
    LNode *curr = ls->top;
    while (curr) {
        LNode *next = curr->next;
        free(curr);
        curr = next;
    }
    ls->top = NULL;
    ls->len = 0;
}

/*判断栈是否为空*/
bool LS_IsEmpty(LinkStack *ls) {
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    return ls->len == 0;
    /********** End **********/
}

/*获取栈的长度*/
int LS_Length(LinkStack *ls) {
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    return ls->len;

    /********** End **********/
}

/*将x进栈*/
void LS_Push(LinkStack *ls, T x) {
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    LNode *newNode = (LNode *) malloc(sizeof(LNode));
    newNode->data = x;
    newNode->next = ls->top;
    ls->top = newNode;
    ls->len++;
    /********** End **********/
}

/*出栈。出栈元素放入item；如果空栈，将返回false*/
bool LS_Pop(LinkStack *ls, T &item) {
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (LS_IsEmpty(ls)) {
        return false;
    }

    LNode *topNode = ls->top;
    item = topNode->data;
    ls->top = topNode->next;
    free(topNode);
    ls->len--;
    return true;
    /********** End **********/
}

/*读栈顶元素放入item。如果空栈，将返回false*/
bool LS_Top(LinkStack *ls, T &item) {
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    if (LS_IsEmpty(ls)) {
        return false;
    }

    item = ls->top->data;
    return true;
    /********** End **********/
}

/*从栈顶到栈底打印各结点数据*/
void LS_Print(LinkStack *ls) {
    if (ls->len == 0) {
        printf("The stack: Empty!");
        return;
    }
    printf("The stack (from top to bottom):");
    LNode *curr = ls->top;
    while (curr) {
        printf(" %d", curr->data);

        curr = curr->next;
    }
    // printf("\n");
}
