#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10;

int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) insert(i, i, a[i]);
    while (p--) {
        int x, y, z;
        cin >> x >> y >> z;
        insert(x, y, z);
    }
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

    int ans = 1000;
    for (int i = 1; i <= n; i++)
        if (b[i] < ans) ans = b[i];
    cout << ans << endl;
    return 0;
}