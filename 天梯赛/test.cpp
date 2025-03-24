#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    set<pair<ll, string>> input_time; // 使用 set 自动排序
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        ll hour = stoll(s.substr(0, 2));
        ll min = stoll(s.substr(3, 2));
        ll second = stoll(s.substr(6, 2));
        ll value = hour * 3600 + min * 60 + second;
        input_time.insert({value, s}); // 插入 set
    }

    // 处理首部间隙
    auto it = input_time.begin();
    if (it->second.substr(0, 8) != "00:00:00") {
        cout << "00:00:00 - " << it->second.substr(0, 8) << endl;
    }

    // 处理相邻间隙
    auto prev = it;
    for (++it; it != input_time.end(); ++it) {
        string current_end = prev->second.substr(11, 8);
        string next_start = it->second.substr(0, 8);
        if (current_end != next_start) {
            cout << current_end << " - " << next_start << endl;
        }
        prev = it;
    }

    // 处理尾部间隙
    string last_end = prev->second.substr(11, 8);
    if (last_end != "23:59:59") {
        cout << last_end << " - 23:59:59" << endl;
    }

    return 0;
}