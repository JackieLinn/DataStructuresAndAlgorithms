#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];

    bool flag = true;    //判断b数组是否单调增，若是，则sum最大最小值是必然相等
    for (int i = 1; i < n; i++) {
        if (b[i] == b[i + 1]) {
            flag = false;
            break;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += b[i];
    if (flag) {
        cout << sum << endl;
        cout << sum << endl;
    } else {
        cout << sum << endl;    //sum就是这个情况下的最大值
        a[1] = b[1];
        int min = a[1];
        for (int i = 2; i <= n; i++) {
            if (b[i] == b[i - 1]) a[i] = 0;
            else a[i] = b[i];
            min += a[i];
        }
        cout << min << endl;
    }
    return 0;
}