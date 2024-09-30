#include <bits/stdc++.h>

using namespace std;

/*
5
3 1 2 4 5
*/

void SelectSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        if (min != i) swap(a[i], a[min]);
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
    SelectSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}