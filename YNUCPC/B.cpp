#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int a[N], s[N];
int n, q;

struct node {
    int s;
    int index;
};
struct node ss[N];

bool cmp(node n1, node n2) {
    if (n1.s == n2.s) return n1.index > n2.index;
    return n1.s > n2.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ss[0].s = 0;
    ss[0].index = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ss[i].s = ss[i - 1].s + a[i];
        ss[i].index = i;
    }
    sort(ss + 1, ss + n + 1, cmp);
//    for (int i = 1; i <= n; i++) cout << ss[i].s << " " << ss[i].index << endl;
    while (q--) {
        LL x;
        cin >> x;
    }
    return 0;
}

//5 1
//5 4 3 2 1