#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int X1[N], Y1[N], X2[N], Y2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;
    int area = 0;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        if (X1[i] >= a || X2[i] <= 0 || Y1[i] >= b || Y2[i] <= 0) area += 0;
        else {
            int x, y;
            x = min(a, X2[i]) - max(0, X1[i]);
            y = min(b, Y2[i]) - max(0, Y1[i]);
            area += x * y;
        }
    }
    cout << area << endl;
    return 0;
}