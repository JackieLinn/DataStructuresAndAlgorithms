#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;

double func(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b >> c >> d;
    double l, r;
    int k = 0;
    for (double i = -100; i < 100; i++) {
        l = i, r = i + 1;
        if (func(l) == 0) {
            cout << fixed << setprecision(2) << l << " ";
            k++;
        }
        if (func(l) * func(r) < 0) {
            while (r - l > 1e-4) {
                double mid = (l + r) / 2;
                if (func(mid) * func(r) <= 0) l = mid;
                else r = mid;
            }
            k++;
            cout << fixed << setprecision(2) << r << " ";
        }
        if (k == 3) break;
    }
    return 0;
}