#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (x.second != y.second) return x.second > y.second;
    else return x.first > y.first;
}

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= 1000; i++) mp[i] = 0;
    while (n--) {
        int k;
        cin >> k;
        while (k--) {
            int tx;
            cin >> tx;
            mp[tx]++;
        }
    }
    vector<pair<int, int>> p;
    for (auto kv : mp) if (kv.second != 0) p.push_back({kv.first, kv.second});
    sort(p.begin(), p.end(), cmp);
    cout << p[0].first << " " << p[0].second << endl;
    return 0;
}