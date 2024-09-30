#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0, a = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a < 10) cout << 0 << a;
            else cout << a;
            a++;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0, a = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j >= n - 1) {
                if (a < 10) cout << 0 << a;
                else cout << a;
                a++;
            } else cout << "  ";
        }
        cout << endl;
    }
    return 0;
}