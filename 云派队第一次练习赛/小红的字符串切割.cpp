#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    LL len = s.size();
    for (LL i = 0; i < len; i++) {
        cout << s[i];
        if (i + 1 == len / 2) cout << endl;
    }
    return 0;
}