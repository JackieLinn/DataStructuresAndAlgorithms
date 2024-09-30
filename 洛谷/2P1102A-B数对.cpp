#include <bits/stdc++.h>

using namespace std;

/*
4 1
1 1 2 3
*/

typedef long long LL;

const int N = 2e5 + 10;
int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> q[i];
    quick_sort(q, 0, n - 1);
    LL ans = 0;
    while (n--) {
        int a = q[n], b = a - c;
        int l1 = -1, r1 = n;
        while (l1 + 1 != r1) {
            int mid = l1 + r1 >> 1;
            if (q[mid] < b) l1 = mid;
            else r1 = mid;
        }
        int l2 = -1, r2 = n;
        while (l2 + 1 != r2) {
            int mid = l2 + r2 >> 1;
            if (q[mid] <= b) l2 = mid;
            else r2 = mid;
        }
        if (q[r1] == q[l2]) ans += l2 - r1 + 1;
    }
    cout << ans;
    return 0;
}