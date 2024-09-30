#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    if (a[0] > x) cout << 0 << " " << x << endl;
    else {
        LL cnt = 1;
        x -= a[0];
        for (int i = 1; i < n; i++) {
            int cmp = a[i] - a[i - 1];
            if (x < cmp) break;
            else {
                x -= cmp;
                cnt++;
            }
        }
        cout << cnt << " " << x << endl;
    }
    return 0;
}