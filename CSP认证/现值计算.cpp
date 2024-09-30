#include <bits/stdc++.h>

using namespace std;

const int N = 60;
int q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    double i;
    cin >> n >> i;
    for (int k = 0; k <= n; k++) cin >> q[k];

    double sum = q[0];
    for (int k = 1; k <= n; k++) sum += q[k] * pow(1 + i, -k);
    cout << sum << endl;
    return 0;
}