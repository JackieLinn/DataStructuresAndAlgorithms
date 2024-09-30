#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int q[N];
LL n, m;

bool check(LL x) {
    LL sum = 0;
    for (int i = 0; i < n; i++)
        if (q[i] > x)
            sum += q[i] - x;
    return sum >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i];
    LL l = 0, r = 2e9;
    while (l + 1 != r) {
        LL mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int q[N];
LL n, m;

bool check(LL x) {
    LL sum = 0;
    for (int i = 0; i < n; i++)
        if (q[i] > x)
            sum += q[i] - x;
    if (sum >= m) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i];
    sort(q, q + n);

    LL l = q[0] - 1, r = q[n - 1] + 1;
    while (l + 1 != r) {
        LL mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}
*/
