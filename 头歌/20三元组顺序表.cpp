#include<stdio.h>

#define number 3
typedef struct {
    int i, j;
    int data;
} triple;
typedef struct {
    triple data[number];
    int n, m, num;
} TSMatrix;

//输出存储的稀疏矩阵
void display(TSMatrix M);

int main() {
    TSMatrix M;
    M.m = 3;
    M.n = 3;
    M.num = 3;

    M.data[0].i = 1;
    M.data[0].j = 1;
    M.data[0].data = 1;

    M.data[1].i = 2;
    M.data[1].j = 3;
    M.data[1].data = 5;

    M.data[2].i = 3;
    M.data[2].j = 1;
    M.data[2].data = 3;
    display(M);
    return 0;
}

void display(TSMatrix M) {
/*** 请在下方填写你的代码 *********/
/************* begin **************/

    int k = 0; // 用于遍历 data 数组的索引
    for (int i = 1; i <= M.m; i++) {
        for (int j = 1; j <= M.n; j++) {
            if (k < M.num && M.data[k].i == i && M.data[k].j == j) {
                printf("%d ", M.data[k].data);
                k++; // 移动到下一个非零元素
            } else {
                printf("0 "); // 打印零元素
            }
        }
        printf("\n"); // 换行到下一行
    }

/************** end ***************/
} 