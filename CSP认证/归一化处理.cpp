#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N];
double f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int sum1 = 0;
    for (int i = 1; i <= n; i++) sum1 += a[i];
    double avg = (sum1 * 1.0) / n;

    double sum2 = 0;
    for (int i = 1; i <= n; i++) sum2 += pow(a[i] - avg, 2);
    double Da = sum2 / n;

    for (int i = 1; i <= n; i++) {
        f[i] = (a[i] - avg) / pow(Da, 0.5);
        cout << f[i] << endl;
    }
    return 0;
}