#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], p[N], q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> p[i] >> q[i];

    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= m; i++) {
        if (p[i] == 0)
            sort(a + 1, a + q[i] + 1, greater<int>());
        else if (p[i] == 1) {
            sort(a + q[i], a + n + 1);
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
