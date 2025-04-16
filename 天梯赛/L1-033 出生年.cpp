#include<bits/stdc++.h>

using namespace std;

int count(int& x) {
    string tmp = to_string(x);
    string s;
    if (tmp.size() < 4) {
        int len = 4 - tmp.size();
        while (len--) s += '0';
    }
    s += tmp;
    map<int, bool> mp;
    for (int i = 0; i < 10; i++) mp[i] = false;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        int num = s[i] - '0';
        if (!mp[num]) {
            mp[num] = true;
            cnt++;
        }
    }
    return cnt;
}

int check(int& y, int& n) {
    for (int i = y; i <= 5000; i++) {
        int cnt = count(i);
        if (cnt == n) return i;
    }
    return -1;
}

int main() {
    int y, n;
    cin >> y >> n;
    int y2 = check(y, n);
    cout << y2 - y << " ";
    if (y2 >= 1000) cout << y2 << endl;
    else {
        string s = to_string(y2);
        int len = 4 - s.size();
        while (len--) cout << '0';
        cout << y2 << endl;
    }
    return 0;
}