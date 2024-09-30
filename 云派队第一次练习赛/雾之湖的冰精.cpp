#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL a, b;
    cin >> a >> b;
    if (a + b > 9) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}