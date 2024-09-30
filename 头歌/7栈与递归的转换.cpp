#include <stdio.h>
#include <stdlib.h>

#define Max 100
typedef int T;

struct SeqStack {
    T *data; // 数据元素指针
    T *fn;
    int top; // 栈顶元素编号
    int max; // 最大节点数
};

/*创建一个栈*/
SeqStack *SS_Create(int maxlen) {
    SeqStack *ss = (SeqStack *) malloc(sizeof(SeqStack));
    ss->data = (T *) malloc(maxlen * sizeof(T));
    ss->fn = (T *) malloc(maxlen * sizeof(T));
    ss->top = -1;
    ss->max = maxlen;
    return ss;
}

/*释放一个栈*/
void SS_Free(SeqStack *ss) {
    free(ss->data);
    free(ss);
}

/*清空一个栈*/
void SS_MakeEmpty(SeqStack *ss) {
    ss->top = -1;
}

bool SS_IsFull(SeqStack *ss)
// 判断栈是否为满。为满返回true，否则返回false。
{
    return ss->top + 1 >= ss->max;

}

bool SS_IsEmpty(SeqStack *ss)
// 判断栈是否为空。为空返回true，否则返回false。
{
    return ss->top < 0;
}

int SS_Length(SeqStack *ss)
// 获取栈元素个数
{

    return ss->top + 1;
}

bool SS_Push(SeqStack *ss, T x)
// 将元素x进栈，若满栈则无法进栈，返回false，否则返回true
{
    if (SS_IsFull(ss)) {
        return false;
    }
    ss->top++;
    ss->data[ss->top] = x;
    return true;

}

bool SS_Pop(SeqStack *ss, T &item)
// 出栈的元素放入item。若出栈成功(栈不为空)，则返回true；否则(空栈)，返回false。
{

    if (SS_IsEmpty(ss)) {
        return false;
    }
    item = ss->data[ss->top];
    ss->top--;
    return true;

}

/*获取栈顶元素放入item中,空栈则返回false*/
bool SS_Top(SeqStack *ss, T &item) {
    if (SS_IsEmpty(ss)) {
        return false;
    }
    item = ss->data[ss->top];
    return true;
}

/*从栈底到栈顶打印出所有元素*/
void SS_Print(SeqStack *ss) {
    if (SS_IsEmpty(ss)) {
        printf("stack data: Empty!\n");
        return;
    }
    int curr = ss->top;
    while (curr >= 0) {
        printf("%d", ss->data[curr]);
        curr--;
    }
    //printf("\n");
}

//在此补全函数,计算n!
int fun(int n) {
    SeqStack *ss = SS_Create(Max);  //创建一个空栈
    ss->top = -1;
    /*****BEGIN*****/

    int result = 1;
    int item = 1;
    for (int i = 1; i <= n; i++) {
        SS_Push(ss, i);
    }
    while (!SS_IsEmpty(ss)) {
        SS_Pop(ss, item);
        result *= item;
    }
    return result;

    /******END******/
}

int main() {
    int n = 3;
    printf("%d! = %d\n", n, fun(n));
    return 0;
}