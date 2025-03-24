#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        int cnt = 0;
        string s1 = s;
        while (s1.find("ong") != s.npos) {
            int pos = s1.find("ong");
            s1.erase(pos, 3);
            s1.insert(pos, "===");
            if (s1[pos + 3] == ',' || s1[pos + 3] == '.') cnt++;
        }
        if (cnt == 2) {
            int cnt1 = 0, cnt2 = 0;
            int idx = 0;
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s[i] == ' ') cnt1++;
                if (cnt1 == 3) {
                    idx = i + 1;
                    break;
                }
                cnt2++;
            }
            s.erase(idx, cnt2 - 1);
            s.insert(idx, "qiao ben zhong");
            cout << s << endl;
        } else cout << "Skipped" << endl;
    }
    return 0;
}