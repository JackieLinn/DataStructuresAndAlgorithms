#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<int, int> mp;
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) mp[s[i] - '0'] ++;
    for (auto & i : mp) {
        cout << i.first << ":" << i.second << endl;
    }
    return 0;
}