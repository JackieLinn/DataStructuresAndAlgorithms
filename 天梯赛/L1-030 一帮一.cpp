#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp = n;
    vector<pair<int, string>> p;
    unordered_map<string, bool> check;
    while (tmp--) {
        int num;
        string name;
        cin >> num >> name;
        p.push_back({num, name});
        check[name] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!check[p[i].second]) {
            cout << p[i].second << " ";
            check[p[i].second] = true;
        }
        for (int j = n - 1; j >= 0; j--) {
            if (p[i].first != p[j].first && !check[p[j].second]) {
                cout << p[j].second << endl;
                check[p[j].second] = true;
                break;
            }
        }
    }
    return 0;
}