#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int l, n, t;
    cin >> l >> n;
    int a[l];
    t = pow(26, l) - n;
    for (int i = 0; i < l; i++) {
        a[i] = t % 26;
        t /= 26;
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << static_cast<char>('a' + a[i]);
    }

    return 0;
}