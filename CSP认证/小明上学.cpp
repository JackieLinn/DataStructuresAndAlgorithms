#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int r, y, g;
int n;
int k[N], t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> r >> y >> g;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> k[i] >> t[i];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (k[i] != 3) sum += t[i];
        if (k[i] == 2) sum += r;
    }
    cout << sum << endl;
    return 0;
}