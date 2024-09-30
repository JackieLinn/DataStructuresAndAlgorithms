#include <bits/stdc++.h>

using namespace std;

const int N = 510;
int a[N][N], h[260];
int n, m, l;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            h[a[i][j]]++;
    for (int i = 0; i < l; i++) cout << h[i] << " ";
    return 0;
}