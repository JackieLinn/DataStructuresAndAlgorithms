#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int q;
int a[50], b[50];

void divide(LL x) {
    for (int i = 0; i < 50; i++) {
        if (a[i] == 0) break;
        a[i] = 0;
        b[i] = 0;
    }

    int p = 0, t = 0;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
//            cout << i << " " << cnt << endl;
            a[p++] = i, b[t++] = cnt;
        }
    }
//    if (x > 1) cout << x << " " << 1 << endl;
    if (x > 1) a[p++] = x, b[t++] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> q;
    while (q--) {
        LL n, k;
        cin >> n >> k;
        LL sum = 1;
        divide(n);
        for (int i = 0; i < 50; i++) {
            if (a[i] == 0) break;
            if (b[i] >= k) sum *= pow(a[i], b[i]);
        }
        cout << sum << endl;
    }
    return 0;
}