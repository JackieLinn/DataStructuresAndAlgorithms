#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < b.length(); i++) {
        while (a.find(b[i]) != a.npos) {
            int pos = a.find(b[i]);
            a.erase(pos, 1);
        }
    }
    cout << a << endl;
    return 0;
}