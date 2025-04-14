#include<bits/stdc++.h>

using namespace std;

map<int, int> mp;

void init() {
    mp[1] = 0, mp[2] = 0, mp[3] = 0, mp[4] = 0, mp[5] = 0, mp[6] = 0, mp[7] = 0, mp[8] = 0, mp[9] = 0;
}

bool check() {
    for (int i = 1; i <= 9; i++) if (mp[i] != 1) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(9, vector<int>(9, 0));
    while (n--) {
        init();
        // 输入
        for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) cin >> a[i][j];
        bool flag0 = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (a[i][j] < 1 || a[i][j] > 9) {
                    flag0 = true;
                    cout << 0 << endl;
                    break;
                }
            }
            if (flag0) break;
        }
        if (flag0) continue;

        // 行
        bool flag1 = false;
        for (int i = 0; i < 9; i++) {
            init();
            for (int j = 0; j < 9; j++) {
                mp[a[i][j]]++;
            }
            if (check()) continue;
            else {
                cout << 0 << endl;
                flag1 = true;
                break;
            }
        }
        if (flag1) continue;

        // 列
        bool flag2 = false;
        for (int i = 0; i < 9; i++) {
            init();
            for (int j = 0; j < 9; j++) {
                mp[a[j][i]]++;
            }
            if (check()) continue;
            else {
                cout << 0 << endl;
                flag2 = true;
                break;
            }
        }
        if (flag2) continue;

        // 方块
        init();
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 3; i < 6; i++) for (int j = 0; j < 3; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 6; i < 9; i++) for (int j = 0; j < 3; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 0; i < 3; i++) for (int j = 3; j < 6; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 3; i < 6; i++) for (int j = 3; j < 6; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 6; i < 9; i++) for (int j = 3; j < 6; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 0; i < 3; i++) for (int j = 6; j < 9; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 3; i < 6; i++) for (int j = 6; j < 9; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        init();
        for (int i = 6; i < 9; i++) for (int j = 6; j < 9; j++) mp[a[i][j]]++;
        if (!check()) {
            cout << 0 << endl;
            continue;
        }

        cout << 1 << endl;
    }
    return 0;
}