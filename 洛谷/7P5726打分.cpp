#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int q[N];

int findMax(int q[], int n) {
    int max = -1;
    for (int i = 1; i <= n; i++)
        if (q[i] > max) max = q[i];
    return max;
}

int findMin(int q[], int n) {
    int min = 11;
    for (int i = 1; i <= n; i++)
        if (q[i] < min) min = q[i];
    return min;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        sum += q[i];
    }
    int max = findMax(q, n);
    int min = findMin(q, n);
    double ans = (sum - max - min) * 1.0 / (n - 2);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}