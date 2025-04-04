#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    map<int, char> mp;
    mp[0] = '1';
    mp[1] = '0';
    mp[2] = 'X';
    mp[3] = '9';
    mp[4] = '8';
    mp[5] = '7';
    mp[6] = '6';
    mp[7] = '5';
    mp[8] = '4';
    mp[9] = '3';
    mp[10] = '2';

    bool flag2 = true;
    cin.ignore();
    while (n--) {
        bool flag = true;
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9') {
                flag = false;
                break;
            }
            else {
                sum += (s[i] - '0') * a[i];
            }
        }
        if (!flag) {
            cout << s << endl;
            flag2 = false;
            continue;
        }
        sum %= 11;
        if (mp[sum] != s[s.length() - 1]) {
            cout << s << endl;
            flag2 = false;
        }
    }
    if (flag2) cout << "All passed" << endl;
    return 0;
} 