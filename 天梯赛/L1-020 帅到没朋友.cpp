#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110, M = 1010, K = 10010;

int n, m;
string s[N][M];
string ss[K];
int k[M];

int main() {
    map<string, int> mp;
    map<string, bool> mp1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> s[i][j];
            if (k[i] > 1) mp[s[i][j]]++;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> ss[i];
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (mp[ss[i]] == 0 && !mp1[ss[i]]) {
            if (cnt == 0) cout << ss[i];
            else cout << " " << ss[i];
            mp1[ss[i]] = true;
            cnt++;
        }
    }
    if (cnt == 0) cout << "No one is handsome" << endl;
    return 0;
} 