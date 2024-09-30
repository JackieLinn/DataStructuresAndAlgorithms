#include<stdio.h>
#include<stdlib.h>

void SimpSelSort(int a[], int n) {
    // 请在此添加代码，补全函数SimpSelSort
    /********** Begin *********/

    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the current element
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }

    /********** End **********/
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    int *a = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    SimpSelSort(a, n);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
/*
5
45 78 2 34 90
*/
