#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, ss;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
        if (s[i] == 'G' || s[i] == 'P' || s[i] == 'L' || s[i] == 'T') {
            ss += s[i];
        }
    }
    map<char, int> mp;
    for (int i = 0; i < ss.length(); i++) {
        if (ss[i] == 'G') mp['G']++;
        if (ss[i] == 'P') mp['P']++;
        if (ss[i] == 'L') mp['L']++;
        if (ss[i] == 'T') mp['T']++;
    }
    while (mp['G'] != 0 || mp['P'] != 0 || mp['L'] != 0 || mp['T'] != 0) {
        if (mp['G'] != 0) {
            cout << "G";
            mp['G']--;
        }
        if (mp['P'] != 0) {
            cout << "P";
            mp['P']--;
        }
        if (mp['L'] != 0) {
            cout << "L";
            mp['L']--;
        }
        if (mp['T'] != 0) {
            cout << "T";
            mp['T']--;
        }
    }
    return 0;
}