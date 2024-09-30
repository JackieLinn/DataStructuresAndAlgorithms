#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int fc(LL n) {
    if (n == 0) return 1;
    return (n % 1000000007) * fc(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL k, a, b, c;
    LL n, m;
    cin >> k >> a >> b >> c;
    cin >> m >> n;

    LL sum1;
/*    sum1 = ((fc(k) % (1000000007)) / ((fc(a) % (1000000007)) * (fc(k - a) % (1000000007))));
    sum1 *= ((fc(k - a) % (1000000007)) / ((fc(b) % (1000000007)) * (fc(k - a - b) % (1000000007))));
    sum1 *= ((fc(k - a - b) % (1000000007)) / ((fc(c) % (1000000007)) * (fc(k - a - b - c) % (1000000007))));*/
    sum1 = (fc(k) / fc(a) / fc(k - 1)) % 1000000007;
    sum1 *= (fc(k - a) / fc(b) / fc(k - a - b)) % 1000000007;
    sum1 *= (fc(k - a - b) / fc(c) / fc(k - a - b - c)) % 1000000007;
    cout << sum1 << endl;

    LL sum2;
    for (int i = 1; i <= n; i++) m -= i - 1;
//    sum2 = ((fc(m - 1) % (1000000007)) / ((fc(n - 1) % (1000000007)) * (fc(m - n) % (1000000007))));
    sum2 = (fc(m - 1) / fc(n - 1) / fc(m - n)) % 1000000007;
    cout << sum2 << endl;
    return 0;
}