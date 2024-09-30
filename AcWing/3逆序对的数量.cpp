#include <bits/stdc++.h>

using namespace std;

/*
6
2 3 4 5 6 1
*/

typedef long long LL;
const int N = 1e6;
int q[N], temp[N];

LL merge_sort(int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else {
            temp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid) temp[k++] = q[i++];
    while (j <= r) temp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    cout << merge_sort(q, 0, n - 1);
    return 0;
}