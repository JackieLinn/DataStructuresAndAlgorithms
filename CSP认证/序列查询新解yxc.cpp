#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N];
int n, m;
int R;    //系数

LL get_g(int l, int r) {
    if (l / R == r / R) return (l / R) * (r - l + 1);
    else {
        LL aa = l / R + 1, bb = r / R - 1;    //先去掉左右两段
        LL res = (aa + bb) * (bb - aa + 1) / 2 * R;    //中间部分
        res += (aa - 1) * (aa * R - l);    //左边部分
        res += (bb + 1) * (r - (bb * R + R) + 1);    //右边部分
        return res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    a[n + 1] = m;
    R = m / (n + 1);
    LL ans = 0;
    for (int i = 0; i <= n; i++) {
        LL l = a[i], r = a[i + 1] - 1;
        LL x = l / R, y = r / R;
        if (y <= i || x >= i) ans += abs(i * (r - l + 1) - get_g(l, r));
        else {
            LL mid = i * R;
            ans += abs(i * (mid - l + 1) - get_g(l, mid));    //左半边
            ans += abs(i * (r - mid) - get_g(mid + 1, r));    //右半边
        }
    }
    cout << ans << endl;
    return 0;
}