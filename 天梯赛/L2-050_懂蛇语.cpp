#include <bits/stdc++.h>

using namespace std;

string findKey(string s) {
    string key;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        key += word[0];
    }
    return key;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    map<string, vector<string>> s1;
    cin >> n;
    cin.ignore();
    while (n--) {
        string a;
        getline(cin, a);
        string key = findKey(a);
        s1[key].push_back(a);
    }
    cin >> m;
    cin.ignore();
    while (m--) {
        string b;
        getline(cin, b);
        string b_key = findKey(b);
        if (s1.count(b_key)) {
            sort(s1[b_key].begin(), s1[b_key].end());
            cout << s1[b_key][0];
            for (int i = 1; i < s1[b_key].size(); i++) {
                cout << "|" << s1[b_key][i];
            }
            cout << endl;
        } else {
            cout << b << endl;
        }
    }
    return 0;
}
