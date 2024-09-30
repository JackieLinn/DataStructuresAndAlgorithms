#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x;
    cin >> x;
    int cnt = 0;
    while (true) {
        if (x % 10 == 0) {
            cout << cnt << endl;
            break;
        }
        x++;
        cnt++;
    }
    return 0;
}