#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n0, n1, n;
    cin >> n0 >> n1 >> n;
    int k = 100010, x = -1, y = -1;
    for (int i = 1; i < n; i++) {
        if (n1 % i == 0 && n0 % (n - i) == 0) {
            int a = n1 / i;
            int b = n0 / (n - i);
            if (abs(a - b) < k && a != 1 && b != 1) {
                x = n - i;
                y = i;
            }
        }
    }
    if (x == -1) cout << "No Solution" << endl;
    else cout << x << " " << y << endl;
    return 0;
}