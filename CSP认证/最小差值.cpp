#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    int min = 10000;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(q[i] - q[j]) < min) min = abs(q[i] - q[j]);
    cout << min << endl;
    return 0;
}