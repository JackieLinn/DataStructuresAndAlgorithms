#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1010;
LL a[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    LL sum = 0;
    int temp = 1;
    int i, j;
    for (i = 1; i <= n; i += 2) {
        for (j = 1; j <= m; j++) {
            sum += a[i][j];
        }
        if (temp % 2 == 1) {
            sum += a[i + 1][m];
        } else {
            sum += a[i + 1][1];
        }
        temp++;
        if ((i + 2) == n) {
            if (temp % 2 == 0) {
                sum += a[n][m];
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}

//7 6
//2 8 6 3 5 2
//7 5 6 3 1 6
//7 4 2 8 6 9
//6 2 5 4 8 8
//2 3 8 9 1 5
//7 2 6 9 1 7
//2 3 4 5 6 7