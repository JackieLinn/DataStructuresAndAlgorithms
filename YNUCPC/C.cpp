#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
ll a[N], s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) s[i] = max(s[i], s[i - 1]);

    while (q--) {
        ll x;
        cin >> x;

//        int l = 1, r = n;
//        while (l < r) {
//            int mid = (l + r) >> 1;
//            if (s[mid] >= x) r = mid;
//            else l = mid + 1;
//        }
//        if (s[l] >= x) cout << l << endl;
//        else cout << -1 << endl;

        int l = 0, r = n + 1;
        while (l + 1 != r) {
            int mid = (l + r) / 2;
            if (s[mid] < x) l = mid;
            else r = mid;
        }
        if (s[r] >= x) cout << r << endl;
        else cout << -1 << endl;
    }
    return 0;
}