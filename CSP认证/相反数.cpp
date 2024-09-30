#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int q[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (q[i] + q[j] == 0) sum++;
    cout << sum << endl;
    return 0;
}