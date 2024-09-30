#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int q[N];
int n, k;

bool check(LL x) {
    LL ans = 0;
    for (int i = 0; i < n; i++) ans += q[i] / x;
    return ans >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> q[i];
    sort(q, q + n);

    LL l = 0, r = q[n - 1] + 1;
    while (l + 1 != r) {
        LL mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}