#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    bool flag;
    if (s[0] == '-') {
        flag = true;
        s.erase(0, 1);
    } else flag = false;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] - '0') == 2) cnt++;
    }
    double tmp = (cnt*1.0) / s.length();
    if (flag) tmp *= 1.5;
    if ((s[s.length() - 1] - '0') % 2 == 0) tmp *= 2;
    cout << fixed << setprecision(2) << tmp * 100 << "%" << endl;
    return 0;
} 