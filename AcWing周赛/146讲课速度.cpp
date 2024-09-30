#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int min = 101;
    for (int i = 1; i <= n; i++) {
        if (a[i] < min) min = a[i];
    }
    cout << min << endl;
    return 0;
}