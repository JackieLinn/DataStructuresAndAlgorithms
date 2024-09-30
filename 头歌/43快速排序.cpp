#include<stdio.h>
#include<stdlib.h>

int Partition(int a[], int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(a, low, high);
        // 请在此添加代码，补全函数DirecInsSort
        /********** Begin *********/

        QuickSort(a, low, pivotpos - 1);
        QuickSort(a, pivotpos + 1, high);

        /********** End **********/
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int i;
    int *a = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    QuickSort(a, 0, n - 1);
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}