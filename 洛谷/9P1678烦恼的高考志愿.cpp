#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
LL a[N], b[N];       //a为学校 b为学生

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + m);
//    for (int i = 0; i < m; i++) cout << a[i] << " ";
    LL ans = 0;
    while (n--) {
        LL l = -1, r = m;
        while (l + 1 != r) {
            LL mid = l + r >> 1;
            if (a[mid] < b[n]) l = mid;
            else r = mid;
        }

        LL ll = -1, rr = m;
        while (ll + 1 != rr) {
            LL mid = ll + rr >> 1;
            if (a[mid] <= b[n]) ll = mid;
            else rr = mid;
        }

        if (r != 0)
            ans += min({abs(a[r - 1] - b[n]), abs(a[r] - b[n]), abs(a[ll] - b[n])});
        else
//            ans += min(abs(a[r] - b[n]), abs(a[ll] - b[n]));
            ans += abs(a[r] - b[n]);
    }
    cout << ans << endl;
    return 0;
}