#include <bits/stdc++.h>

using namespace std;

/*
5
3 1 2 4 5
*/

//从小到大的插入排序
void InsertSort(int *a, int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--)
                a[j + 1] = a[j];
            a[j + 1] = temp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int *a = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    InsertSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}