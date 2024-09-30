#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int score[N], w[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> score[i];

    LL ans = 0;
    for (int i = 0; i <= n; i++) ans += score[i] * w[i];
    cout << max((LL) 0, ans) << endl;
    return 0;
}