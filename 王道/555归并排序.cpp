#include <bits/stdc++.h>

using namespace std;

/*
5
3 1 2 4 5
*/

void MergeSort(int *a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);
    int *b = (int *) malloc(sizeof(int) * (r + 1));
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int p = l, q = 0; p <= r; p++, q++) a[p] = b[q];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int *a = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}