#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    vector<pair<string, ll>> input_time;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        ll hour = stoll(s.substr(0, 2));
        ll min = stoll(s.substr(3, 2));
        ll second = stoll(s.substr(6, 2));
        ll value = hour * 3600 + min * 60 + second;
        input_time.emplace_back(s, value);
    }
    sort(input_time.begin(), input_time.end(), [](const pair<string, ll>& a, const pair<string, ll>& b) {
        return a.second < b.second;
    });
    if (input_time[0].first.substr(0, 8) != "00:00:00") {
        cout << "00:00:00 - " << input_time[0].first.substr(0, 8) << endl;
    }
    for (int i = 0; i < input_time.size() - 1; ++i) {
        string current_end = input_time[i].first.substr(11, 8);
        string next_start = input_time[i + 1].first.substr(0, 8);
        if (current_end != next_start) {
            cout << current_end << " - " << next_start << endl;
        }
    }
    string last_end = input_time.back().first.substr(11, 8);
    if (last_end != "23:59:59") {
        cout << last_end << " - 23:59:59" << endl;
    }
    return 0;
}