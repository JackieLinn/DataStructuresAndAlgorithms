#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    a[n + 1] = m;
    LL ans = 0, f, g, r = m / (n + 1);
    for (int i = 0; i <= n; i++) {
        f = i;
        LL cnt;
        for (int j = a[i]; j < a[i + 1]; j += cnt) {
            g = j / r;
            int pos = (g + 1) * r;
            pos = min(pos, a[i + 1]);
            cnt = pos - j;
            ans += abs(g * cnt - f * cnt);
        }
    }
    cout << ans << endl;
    return 0;
}