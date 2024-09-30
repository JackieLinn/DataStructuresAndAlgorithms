#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double a = (1 + sqrt(5)) / 2, b = (1 - sqrt(5)) / 2;
    int n;
    cin >> n;
    double ans = (pow(a, n) - pow(b, n)) / sqrt(5);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}