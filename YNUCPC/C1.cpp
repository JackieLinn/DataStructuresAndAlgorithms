#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> pre(n + 5);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    for (int i = 1; i <= n; i++)
        pre[i] = max(pre[i], pre[i - 1]);

    while (q--) {
        ll x;
        cin >> x;
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (pre[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (pre[l] >= x) cout << l << endl;
        else cout << -1 << endl;
    }
}

int main() {
    solve();
    return 0;
}
