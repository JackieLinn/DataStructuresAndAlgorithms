#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n, b;
int a[N], c[N], temp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> b;
    int odd = 0, even = 0, j = 1;  // 奇数、偶数
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
        if (odd == even && i < n) c[j++] = i;
    }

    if (c[1] == 0) cout << 0 << endl;
    else {
        int p = 1, q = 1;
        while (c[p] != 0) {
            temp[q++] = abs(a[c[p]] - a[c[p] + 1]);
            p++;
        }
        sort(temp + 1, temp + q);
        int ans = 1;
        if (temp[1] > b) cout << 0 << endl;
        else {
            int t = 2;
            q--;
            while (--q) {
                if (temp[1] + temp[t] <= b) {
                    temp[1] += temp[t];
                    ans++;
                    t++;
                } else break;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
/*
100 100
60 83 82 16 17 7 89 6 83 100 85 41 72 44 23 28 64 84 3 23 33 52 93 30 81 38 67 25 26 97 94 78 41 74 74 17 53 51 54 17 20 81 95 76 42 16 16 56 74 69 30 9 82 91 32 13 47 45 97 40 56 57 27 28 84 98 91 5 61 20 3 43 42 26 83 40 34 100 5 63 62 61 72 5 32 58 93 79 7 18 50 43 17 24 77 73 87 74 98 2
 */
