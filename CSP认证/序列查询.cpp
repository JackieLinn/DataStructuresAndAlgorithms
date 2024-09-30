#include <bits/stdc++.h>

using namespace std;

const int N = 210;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    a[n + 1] = m;
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i * (a[i + 1] - a[i]);
    cout << sum << endl;
    return 0;
}