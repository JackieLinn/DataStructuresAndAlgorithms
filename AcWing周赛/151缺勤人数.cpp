#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}