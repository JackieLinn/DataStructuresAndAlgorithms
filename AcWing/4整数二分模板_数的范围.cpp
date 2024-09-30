#include <bits/stdc++.h>

using namespace std;

/*
6 3
1 2 2 3 3 4
3 4 5
4
5
*/

const int N = 1e6 + 10;
int q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i];
/*    while (m--) {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (q[l] != x) cout << "-1 -1" << endl;
        else {
            cout << l << " ";
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }*/
    while (m--) {
        int x;
        cin >> x;
        int l = -1, r = n;
        while (l + 1 != r) {
            int mid = l + r >> 1;
            if (q[mid] < x) l = mid;
            else r = mid;
        }

        int ll = -1, rr = n;
        while (ll + 1 != rr) {
            int mid = ll + rr >> 1;
            if (q[mid] <= x) ll = mid;
            else rr = mid;
        }

        if (q[r] == q[ll]) cout << r << " " << ll << endl;
        else cout << "-1 -1" << endl;
    }
    return 0;
}