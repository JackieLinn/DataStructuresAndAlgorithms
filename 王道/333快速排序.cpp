#include <bits/stdc++.h>

using namespace std;

/*
5
3 1 2 4 5
*/

void QuickSort(int *a, int l, int r) {
    if (l >= r) return;
    int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    QuickSort(a, l, j);
    QuickSort(a, j + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int *a = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}