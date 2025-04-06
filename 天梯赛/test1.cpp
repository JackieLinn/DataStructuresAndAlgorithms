#include <bits/stdc++.h>

using namespace std;

int n;
map<int, int> times;
map<int, double> money;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        times[i] = 0;
        money[i] = 0.0;
    }
    for (int i = 1; i <= n; i++) {
        double cnt = 0.0;
        int k;
        cin >> k;
        while (k--) {
            int id, val;
            cin >> id >> val;
            times[id] ++;
            money[id] += val / 100.0;
            cnt += val / 100.0;
        }
        money[i] -= cnt;
        cnt = 0.0;
    }

    vector<pair<int, pair<double, int>>> result;
    for (int i = 1; i <= n; i++) {
        result.push_back({i, {money[i], times[i]}});
    }
    sort(result.begin(), result.end(), [](const pair<int, pair<double, int>>& a, const pair<int, pair<double, int>>& b){
        if (a.second.first != b.second.first) return a.second.first > b.second.first;
        if (a.second.second != b.second.second) return a.second.second > b.second.second;
        return a.first < b.first;
    });
    for (const auto& item : result) {
        cout << item.first << " " << fixed << setprecision(2) << item.second.first << endl;
    }
    return 0;
}