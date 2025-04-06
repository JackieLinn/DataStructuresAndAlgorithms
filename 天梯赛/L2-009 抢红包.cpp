#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> times;
map<int, double> money;

int main() {
    cin >> n;
    vector<vector<pair<int, int>>> send(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int id, val;
            cin >> id >> val;
            send[i].push_back({id, val});
        }
    }
    for (int i = 1; i <= n; i++) {
        double totalGiven = 0;
        set<int> received;
        for (auto& [id, val] : send[i]) {
            if (received.find(id) == received.end()) {
                received.insert(id);
                times[id]++;
                money[id] += val / 100.0;
                totalGiven += val;
            }
        }
        money[i] -= totalGiven / 100.0;
    }
    vector<pair<int, pair<double, int>>> result;
    for (int i = 1; i <= n; i++) {
        result.push_back({i, {money[i], times[i]}});
    }
    sort(result.begin(), result.end(), [](const pair<int, pair<double, int>>& a, const pair<int, pair<double, int>>& b) {
        if (a.second.first != b.second.first) return a.second.first > b.second.first;
        if (a.second.second != b.second.second) return a.second.second > b.second.second;
        return a.first < b.first;
    });
    for (const auto& item : result) {
        cout << item.first << " " << fixed << setprecision(2) << item.second.first << endl;
    }
    return 0;
}
