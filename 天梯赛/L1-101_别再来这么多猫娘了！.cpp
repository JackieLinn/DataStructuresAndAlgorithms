#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, k;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        getline(cin, s[i]);
    }
    cin >> k;
    cin.ignore();
    string ss;
    getline(cin, ss);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        while (ss.find(s[i]) != ss.npos) {
            cnt++;
            int pos = ss.find(s[i]);
            ss.erase(pos, s[i].length());
            ss.insert(pos, "===");
        }
    }
    if (cnt >= k) cout << cnt << endl << "He Xie Ni Quan Jia!" << endl;
    else {
        while (ss.find("===") != -1) {
            int pos = ss.find("===");
            ss.erase(pos, 3);
            ss.insert(pos, "<censored>");
        }
        cout << ss << endl;
    }
    return 0;
}