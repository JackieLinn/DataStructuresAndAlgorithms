#include <stdio.h>
#include <stdlib.h>

#define RADIX 10 // 对整数，基数为10
#define MAX_LENGTH 100 // 最大元素个数

// 静态链表结点 
struct node {
    int data;
    int next;
};

// 获取关键字每一位数字
int get_digit(int n, int loc) {
    int i;
    for (i = 1; i < loc; i++) n = n / 10;
    return n % 10;
}

// 分配和收集操作
void distri_collect(struct node r[], int length, int loc) {

    int front[RADIX], rear[RADIX]; // 辅助数组,指向每个链队列 
    int i;
    for (i = 0; i < RADIX; i++) // 初始为空
    {
        front[i] = 0;
        rear[i] = 0;
    }

    // 遍历整个静态链表，按照关键字分配到各链队列
    int p, digit;
    for (p = r[0].next; p != 0; p = r[p].next) {
        digit = get_digit(r[p].data, loc);
        if (front[digit] == 0) front[digit] = p; // 链队列为空时直接插入
        else r[rear[digit]].next = p; // 插入尾部
        rear[digit] = p;
    }

    // 收集合并
    for (i = 0; front[i] == 0 && i < RADIX; i++);
    r[0].next = front[i];
    p = rear[i];
    while (i < RADIX) {
        for (i++; i < RADIX - 1 && front[i] == 0; ++i);
        if (i >= RADIX) break; // 对最后一个元素特殊处理
        if (front[i]) {
            // 链接两个非空链队列 
            r[p].next = front[i];
            p = rear[i];
        }
    }
    r[p].next = 0;
}

void RadixSort(int a[], int length, int k) {
    struct node r[MAX_LENGTH]; // 创建静态链表保存数据
    r[0].next = 0; // 初始化链表为空 
    int i;
    for (i = 0; i < length; i++) {
        r[i].next = i + 1;
        r[i + 1].data = a[i];
    }
    r[i].next = 0; // 链表最后一个元素指向0，表示链表结束 
    // 请在此添加代码，补全函数RadixSort
    // 对关键字按照从低位到高位进行排序
    /********** Begin *********/

    // 对关键字按照从低位到高位进行排序
    for (i = 1; i <= k; i++) {
        distri_collect(r, length, i);
    }

    /********** End **********/
    int p = r[0].next;
    for (i = 0; i < length && p != 0; i++) {
        a[i] = r[p].data;
        p = r[p].next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    int *a = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    RadixSort(a, n, 2);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}