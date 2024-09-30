#include <stdio.h>
#include <stdlib.h> //malloc、free函数在此头文件

#define InitSize 10 // 默认最大长度
typedef struct {
    int *data;
    int MaxSize;
    int length;
} SqList;

//初始化函数，防止有脏数据
void InitList(SqList &list) {
    //用malloc函数申请一个连续的存储空间
    list.data = (int *) malloc(sizeof(int) * InitSize);
    list.length = 0;
    list.MaxSize = InitSize;
}

void print(SqList &list) {
    for (int i = 0; i < list.length; i++)
        printf("%d ", list.data[i]);
}

//插入数据的插入函数
bool ListInsert(SqList &list, int i, int e) {
    if (i < 1 || i > list.length + 1) return false;
    if (list.length >= InitSize) return false;
    for (int j = list.length; j >= i; j--)
        list.data[j] = list.data[j - 1];
    list.length++;
    list.data[i - 1] = e;
    return true;
}

//增加动态数组长度的函数
void IncreaseSize(SqList &list, int len) {
    int *p = list.data;
    list.data = (int *) malloc(sizeof(int) * (list.MaxSize + len));
    for (int i = 0; i < list.length; i++)
        list.data[i] = p[i];
    list.MaxSize += len;
    free(p);
}

int main() {
    SqList list;
    InitList(list);
    //往顺序表中随意插入一些元素
    list.data[0] = 2;
    list.data[1] = 5;
    list.data[2] = 6;
    list.data[3] = 3;
    list.data[4] = 9;
    list.length = 5;
    print(list);
    //下面增加动态数组的长度
    IncreaseSize(list, 10);
    //插入操作，在第i个位置插入元素e
    if (ListInsert(list, 3, 4)) {
        printf("\n插入后新的数组为: ");
        print(list);
    } else printf("\n插入数据失败，请检查输入是否正确！！！");
    return 0;
}
