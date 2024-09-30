#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

//专门输出的打印函数
void print(SqList &list) {
    for (int i = 0; i < list.length; i++)
        printf("%d ", list.data[i]);
}

//初始化函数，防止有脏数据
void InitList(SqList &list) {
    for (int i = 0; i < MaxSize; i++)
        list.data[i] = 0;
    list.length = 0;
}

//插入数据的插入函数
bool ListInsert(SqList &list, int i, int e) {
    if (i < 1 || i > list.length + 1) return false;
    if (list.length >= MaxSize) return false;
    for (int j = list.length; j >= i; j--)
        list.data[j] = list.data[j - 1];
    list.length++;
    list.data[i - 1] = e;
    return true;
}

//删除数据的删除函数
/*bool ListDelete(SqList &list, int i, int &e) {
    if (i < 1 || i > list.length + 1) return false;
    e = list.data[i - 1];
    for (int j = i; j < list.length; j++)
        list.data[j - 1] = list.data[j];
    list.length--;
    return true;
}*/
bool ListDelete(SqList &list, int i, int &e) {
    if (i < 1 || i > list.length + 1) return false;
    e = list.data[i - 1];
    for (int j = i - 1; j < list.length - 1; j++)
        list.data[j] = list.data[j + 1];
    list.length--;
    return true;
}

//按位查找函数
int getValue1(SqList &list, int e) {
    if (e < 1 || e > list.length) return -1;
    else return list.data[e - 1];
}

//按值查找函数，最后返回的是位序
int getValue2(SqList &list, int e) {
    for (int i = 0; i < list.length; i++)
        if (list.data[i] == e)
            return i + 1;
    return 0;
}

int main() {
    SqList list;
    InitList(list);
    //一些随意的赋值
    list.data[0] = 2;
    list.data[1] = 5;
    list.data[2] = 6;
    list.data[3] = 3;
    list.data[4] = 9;
    list.length = 5;
    print(list);
    //插入操作，在第i个位置插入元素e
    if (ListInsert(list, 3, 4)) {
        printf("\n插入后新的数组为: ");
        print(list);
    } else printf("\n插入数据失败，请检查输入是否正确！！！");

    //删除第i个元素，并用e把删除的元素带出来
    int e = -1;
    if (ListDelete(list, 4, e)) {
        printf("\n删除后新的数组为: ");
        print(list);
    } else printf("\n删除数据失败，请检查输入是否正确！！！");

    //按位查找
    if (getValue1(list, 6) == -1)
        printf("\n输入错误！请检查位置是否正确！");
    else
        printf("\n该位置元素的值是 %d", getValue1(list, 6));
    //按值查找，最后得到第一个该值的位置
    if (getValue2(list, 9))
        printf("\n该元素的位置是第 %d 个", getValue2(list, 9));
    else
        printf("\n输入错误！请检查位置是否正确！");
    return 0;
}

