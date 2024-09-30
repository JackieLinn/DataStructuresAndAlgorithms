#include <bits/stdc++.h>

using namespace std;

/*
5
3 1 2 4 5
*/

void BubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                flag = true;
            }
        }
        if (!flag) return;
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
    BubbleSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}