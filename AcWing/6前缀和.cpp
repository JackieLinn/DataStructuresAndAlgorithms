#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int q[N], s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> q[i];
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + q[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}