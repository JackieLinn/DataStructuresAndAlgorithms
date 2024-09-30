#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int M = 10010;
int s[N], a[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 1; i <= n; i++) a[s[i]]++;
    int temp = a[1], ans = 1;
    for (int i = 2; i <= 10000; i++) {
        if (a[i] > temp) {
            temp = a[i];
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}