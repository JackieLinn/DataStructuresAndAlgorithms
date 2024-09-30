#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a;
    cin >> a;
    vector<int> A;
    for (int i = 0; i <= a.size() - 1; i++) A.push_back(a[i] - '0');
    LL cnt = 0;
    LL temp = 0;
    for (int i = 0; i <= a.size() - 1; i++) {
        temp += A[i];
        if (temp % 9 == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}