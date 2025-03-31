#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    int n;
    cin >> s;
    cin >> n;
    while (n--) {
        int a, b;
        string s1, s2, tmp;
        cin >> a >> b >> s1 >> s2;
        tmp = s.substr(a - 1, b - a + 1);
        string ss = s1 + s2;
        s.erase(a - 1, b - a + 1);
        if (s.find(ss) != s.npos) {
            int pos = s.find(ss) + s1.length();
            s.insert(pos, tmp);
        } else s += tmp;
    }
    cout << s << endl;
    return 0;
}