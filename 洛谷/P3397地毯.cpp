#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int s[N][N];

void insert(int x1, int y1, int x2, int y2) {
    s[x1][y1] += 1;
    s[x1][y2 + 1] -= 1;
    s[x2 + 1][y1] -= 1;
    s[x2 + 1][y2 + 1] += 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        insert(x1, y1, x2, y2);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
    return 0;
}