#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;
int d[N];
int l, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    d[n + 1] = l;
    int left = 0, right = l + 1;
    while (left + 1 != right) {
        int mid = (left + right) >> 1;
        int sum = 0, x = d[0];    //x为当前起跳位置，sum为当前答案下要移走多少石头
        for (int i = 1; i <= n + 1; i++)
            if (d[i] - x < mid) sum++;
            else x = d[i];
        if (sum <= m) left = mid;
        else right = mid;
    }
    cout << left << endl;
    return 0;
}