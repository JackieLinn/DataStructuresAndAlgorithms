#include<stdio.h>
#include<stdlib.h>

void Merge(int a[], int low, int mid, int high) {
    int *b = (int *) malloc(sizeof(int) * (high + 1));
    int i, j, k;
    for (k = low; k <= high; k++) b[k] = a[k];
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
        if (b[i] <= b[j]) a[k] = b[i++];
        else a[k] = b[j++];
    }
    while (i <= mid) a[k++] = b[i++];
    while (j <= high) a[k++] = b[j++];
}

void MergeSort(int a[], int low, int high) {
    if (low < high) {
        // 请在此添加代码，补全函数MergeSort
        /********** Begin *********/

        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);

        /********** End **********/
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    int *a = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    MergeSort(a, 0, n - 1);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
