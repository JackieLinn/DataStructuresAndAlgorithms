#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL t;
    cin >> t;
    while (t--) {
        LL l, r;
        cin >> l >> r;
        cout << r / 3 - (l - 1) / 3 << endl;
    }
    return 0;
}