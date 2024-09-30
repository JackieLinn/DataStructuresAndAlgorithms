#include <bits/stdc++.h>

using namespace std;

double w0, w, m;
double l, r;

bool check(double x) {
    return (pow(1.0 / (1.0 + x), m) >= 1 - w0 / w * x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> w0 >> w >> m;
    l = 0, r = 10;
    while (r - l > 1e-4) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(1) << l * 100 << endl;
    return 0;
}