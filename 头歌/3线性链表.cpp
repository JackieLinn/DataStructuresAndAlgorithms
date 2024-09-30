#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
张三
李四
王五
输出:
线性链表创建成功！
张三
李四
王五
 */

struct stu {
    char name[32];
    struct stu *next;
};

/*创建链表，参数n是初始化链表时建立的数据个数
prev：指向当前结点的前一个结点
cur：指向当前结点
head：保存表头结点的指针*/
struct stu *CreatList(int n) {
    int i;
    char age[12];
    struct stu *prev, *cur, *head;
    head = (struct stu *) malloc(sizeof(struct stu));
    if (head == NULL) {
        printf("Can't alloc memory\n");
        return NULL;
    }
    prev = head;
    head->name[0] = '\0';
    head->next = NULL;
    for (i = 1; i <= n; i++) {
        cur = (struct stu *) malloc(sizeof(struct stu));
        if (cur == NULL) {
            printf("Can't alloc memory\n");
            return NULL;
        }
        scanf("%s", cur->name);
        // 请在下面的Begin-End之间补充代码，插入结点。
        /********** Begin *********/

        prev->next = cur;
        prev = prev->next;

        /********** End **********/
    }
    printf("线性链表创建成功！\n");
    return head;
}

/*遍历链表，打印链表数据*/
void Print(struct stu *head) {
    struct stu *cur;
    cur = head->next;
    while (cur != NULL) {
        printf("%s\n", cur->name);
        cur = cur->next;
    }
}

int main() {
    int number = 3;
    char _name[32];
    struct stu *head, *cur, *fro;
    head = CreatList(number);
    if (head == NULL)
        return -1;
    Print(head);
    return 0;
}