#include<bits/stdc++.h>

using namespace std;

int main() {
    int cnt = 0;
    bool flag1 = false, flag2 = false;
    string s1, s2;
    while (true) {
        string s;
        cin >> s;
        if (s[0] == '.') break;
        cnt++;
        if (cnt == 2) {
            flag1 = true;
            s1 = s;
        }
        if (cnt == 14) {
            flag2 = true;
            s2 = s;
        }
    }
    if (flag1 && flag2) cout << s1 << " and " << s2 << " are inviting you to dinner..." << endl;
    else if (flag1) cout << s1 << " is the only one for you..." << endl;
    else cout << "Momo... No one is for you ..." << endl;
    return 0;
}