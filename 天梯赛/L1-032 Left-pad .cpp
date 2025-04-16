#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    char c;
    cin >> n >> c;
    cin.ignore();
    string s;
    getline(cin, s);
    if (s.size() == n) cout << s << endl;
    else if (s.size() < n) {
        int len = n - s.size();
        while (len--) cout << c;
        cout << s << endl;
    } else {
        for (int i = s.size() - 1 - n + 1; i < s.size(); i++) cout << s[i];
        cout << endl;
    }
    return 0;
}