#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 25;
int a[N], b[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    c[0] = 1;
    for (int i = 1; i <= n; i++) c[i] = c[i - 1] * a[i];
    for (int i = 1; i <= n; i++) {
        LL mTemp = m;
        if (i == 1) b[i] = mTemp % c[i] / c[i - 1];
        else {
            int temp = 0;
            for (int j = 1; j < i; j++) temp += c[j - 1] * b[j];
            b[i] = (mTemp % c[i] - temp) / c[i - 1];
        }
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    return 0;
}