#include <stdio.h>
#include <stdlib.h>

#define MAXN 20              //最多皇后个数
int q[MAXN];                 //存放各皇后所在列号
int count = 0;              //输出一个解

void dispsolution(int n)     //输出一个解
{
    printf("第%d个解：", ++count);
    for (int i = 1; i <= n; i++) {
        printf("(%d,%d)", i, q[i]);
    }
    printf("\n");
}

bool place(int i)               //测试第i行的q[i]列上能否摆放皇后
{
    int j = 1;
    if (i == 1)return true;
    while (j < i)                  //j=1~i-1是已放置了皇后的行
    {
        if ((q[j] == q[i]) || (abs(q[j] - q[i]) == abs(j - i))) {
            //该皇后是否与以前的皇后同列，位置(j,q[j])与(i,q[i])是否同对角线
            return false;
        }
        j++;
    }
    return true;
}

void Queens(int n)                   //求解n皇后问题
{
    int i = 1;                        //i表示当前行，也表示放置第i个皇后
    q[i] = 0;                         //q[i]是当前列，每个新考虑的皇后的初始位置置为0列
    while (i >= 1)                     //尚未回溯到头，循环
    {
        /********** Begin **********/

        while (i >= 1) {
            q[i]++;
            while (q[i] <= n) {
                if (place(i)) {
                    if (i == n) {
                        dispsolution(n);  // 输出结果
                        q[i]++;
                    } else {
                        i++;
                        q[i] = 0;  // 下一行皇后位置初始置0
                        break;
                    }
                } else {
                    q[i]++;
                }
            }
            if (q[i] > n) {
                i--; // 回溯
            }
        }

        /********** End **********/
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d皇后求解如下：\n", n);
    Queens(n);
    return 0;
}