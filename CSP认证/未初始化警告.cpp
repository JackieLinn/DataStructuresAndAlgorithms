#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> x[i] >> y[i];

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (x[j] == y[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}