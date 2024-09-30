#include<stdio.h>
#include<stdlib.h>

void DirecInsSort(int *a, int n) {
    // 请在此添加代码，补全函数DirecInsSort
    /********** Begin *********/

    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;

        /********** End **********/
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    int *a = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    DirecInsSort(a, n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
