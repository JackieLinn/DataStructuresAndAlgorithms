#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, s, t, k;
    cin >> n >> s >> t >> k;
    LL m = t;
    LL num = t - s;
    for (LL i = 0; i < k; i++) {
        m += num;
        if (m > n) m %= n;
        if (m <= 0) m += n;
    }
    cout << m << endl;
    return 0;
}