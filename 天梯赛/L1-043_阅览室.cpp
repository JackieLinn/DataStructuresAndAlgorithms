#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        map<int, string> start_time;
        int cnt = 0, time = 0;
        while (true) {
            int a;
            char b;
            string c;
            cin >> a >> b >> c;
            if (a == 0) break;
            if (b == 'S') start_time[a] = c;
            else if (b == 'E') {
                if (start_time.count(a)) {
                    cnt ++;
                    time += (stoll(c.substr(0, 2)) - stoll(start_time[a].substr(0, 2))) * 60
                            + stoll(c.substr(3, 5)) - stoll(start_time[a].substr(3, 5));
                    start_time.erase(a);
                }
            }
        }
        if (cnt == 0) cout << "0 0" << endl;
        else cout << cnt << " " << round(time / (cnt*1.0)) << endl;
        start_time.clear();
    }
    return 0;
}