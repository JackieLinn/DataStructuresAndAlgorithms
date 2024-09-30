#include <bits/stdc++.h>

using namespace std;

/*
11 3
1 3 3 3 5 7 9 11 13 15 15
1 3 6
*/

typedef long long LL;

const int N = 1000010;
LL q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i];
    while (m--) {
        LL x;
        cin >> x;
        int l = -1, r = n;
        while (l + 1 != r) {
            int mid = l + r >> 1;
            if (q[mid] < x) l = mid;
            else r = mid;
        }
        if (q[r] == x) cout << r + 1 << " ";
        else cout << "-1 ";
    }
    return 0;
}