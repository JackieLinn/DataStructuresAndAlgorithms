#include <bits/stdc++.h>

using namespace std;

const int M = 15;
int n, m;

struct node {
    int id;
    int q[M];
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    node a[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i].q[j];
        }
        a[i].id = i + 1;
    }

    for (int i = 0; i < n; i++) {
        bool flag2 = true;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            bool flag1 = true;
            for (int k = 0; k < m; k++) {
                if (a[j].q[k] <= a[i].q[k]) flag1 = false;
            }
            if (flag1) {
                flag2 = false;
                cout << a[j].id << endl;
                break;
            }
        }
        if (flag2) cout << 0 << endl;
    }
    return 0;
}