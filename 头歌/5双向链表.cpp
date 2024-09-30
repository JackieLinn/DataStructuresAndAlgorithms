#include <stdio.h>
#include <stdlib.h>

/*
4 1 3 0 8 9
输出:
输入数据中...
链表结构为：4 <-> 1 <-> 3 <-> 0 <-> 8 <-> 9
链表中第 4 个节点的直接前驱是：3
*/

//节点结构
typedef struct line {
    struct line *prior;
    int data;
    struct line *next;
} line;

//双链表的创建函数
line *initLine(line *head);

//输出双链表的函数
void display(line *head);

int main() {
    //创建一个头指针
    line *head = NULL;
    //调用链表创建函数
    head = initLine(head);
    printf("链表结构为：");
    //输出创建好的链表
    display(head);
    //显示双链表的优点
    printf("链表中第 4 个节点的直接前驱是：%d", head->next->next->next->prior->data);
    return 0;
}

line *initLine(line *head) {
    printf("输入数据中...\n");
    int data[6] = {0};
    for (int i = 0; i < 6; i++) {
        scanf("%d", &data[i]);
    }
    line *list = NULL;
    //创建一个首元节点，链表的头指针为head
    head = (line *) malloc(sizeof(line));
    //对节点进行初始化
    head->prior = NULL;
    head->next = NULL;
    head->data = data[0];
    //声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
    list = head;
    for (int i = 1; i <= 5; i++) {

        // 请在下面的Begin-End之间补充代码，插入结点，其中结点数据为data[i]。
        /********** Begin *********/

        line *node = (line *) malloc(sizeof(line));
        node->data = data[i];
        node->prior = list;
        node->next = NULL;
        list->next = node;
        list = node;

        /********** End **********/
    }
    //返回新创建的链表
    return head;
}

void display(line *head) {
    line *temp = head;
    while (temp) {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        } else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
}