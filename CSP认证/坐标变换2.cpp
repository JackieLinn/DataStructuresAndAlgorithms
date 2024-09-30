#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
int a[N];
double b[N], sum1[N], sum2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    for (int i = 0; i <= n; i++) sum1[i] = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1) {
            sum1[i] = sum1[i - 1] * b[i];
            sum2[i] = sum2[i - 1];
        } else {
            sum1[i] = sum1[i - 1];
            sum2[i] = sum2[i - 1] + b[i];
        }

    while (m--) {
        LL i, j;
        double x, y;
        cin >> i >> j >> x >> y;
        double p = sum1[j] / sum1[i - 1];
        double q = sum2[j] - sum2[i - 1];
        double xTemp = x, yTemp = y;
        x = (xTemp * cos(q) - yTemp * sin(q)) * p;
        y = (xTemp * sin(q) + yTemp * cos(q)) * p;
        cout << fixed << setprecision(3) << x << " " << y << endl;
    }
    return 0;
}