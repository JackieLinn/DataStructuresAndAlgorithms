#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int sum, number;
    cin >> sum >> number;
    double l = 0, r = 15;
    while (r - l > 1e-2) {
        double mid = (l + r) / 2;
        if (number * mid < sum) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}