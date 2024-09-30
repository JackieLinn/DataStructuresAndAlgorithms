#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1, j = 1; i <= n; i++, j++) {
        if (j <= 4) cout << "MB";
        else if (j == 6) j = 0;
    }
    return 0;
}
