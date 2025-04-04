#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m;
    cin >> k;
    int cnt1 = 0, cnt2 = 0;
    while (k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a + c == b && a + c == d) continue;
        if (a + c == b) {
            cnt1++;
        }
        if (a + c == d) {
            cnt2++;
        }
        if (cnt1 == n + 1) {
            cout << "A" << endl;
            cout << cnt2 << endl;
            break;
        }
        if (cnt2 == m + 1) {
            cout << "B" << endl;
            cout << cnt1 << endl;
            break;
        }
    }
    return 0;
}