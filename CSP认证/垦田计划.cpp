#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int t[N], c[N];
int n, m, k;

bool check(int x) {
    LL sum = 0;
    for (int i = 0; i < n; i++)
        if (t[i] > x)
            sum += c[i] * (t[i] - x);
    return sum > m;    // return sum <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> t[i] >> c[i];

    int l = 0, r = 1e5;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;    // r = mid;
        else r = mid;    // l = mid
    }
    if (r > k) cout << r << endl;    // if (l > k) cout << l << endl;
    else cout << k << endl;
    return 0;
}