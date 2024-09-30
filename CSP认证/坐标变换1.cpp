#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int dx[N], dy[N];
int x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> dx[i] >> dy[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            x[i] += dx[j];
            y[i] += dy[j];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << x[i] << " " << y[i] << endl;
    }
    return 0;
}