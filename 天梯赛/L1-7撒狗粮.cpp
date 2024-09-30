#include<bits/stdc++.h>

using namespace std;
//#define int long long
#define pii pair<int,int>
#define endl '\n'
#define INF 9223372036854775807

void print(int a[], int n) {
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}

void solve() {

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    map<string, string> mp;
    map<string, string> rmp;
    string s1, s2;
    for (int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        mp[s1] = s2;
        mp[s2] = s1;
    }
    int m;
    cin >> m;
    map<string, int> str_pos;
    string str[m + 3];
    for (int i = 1; i <= m; i++) {

        cin >> str[i];
        str_pos[str[i]] = i;
    }
    map<string, bool> vis;
    //遍历每个String  找到有对象的人,,标记出来
    for (auto x: str_pos) {
        string t = x.first;
        if (mp.find(t) != mp.end() or rmp.find(t) != mp.end()) {
            vis[mp[t]] = true;
            vis[rmp[t]] = true;
        }
    }
    vector<int> c(m + 3);
//    vector<int> b(m+3);
    //接下来差分,,遍历每一个对象,,他们中间的+,,左右两边的+
    for (auto x: mp) {
        auto a = x.first, b = x.second;
        if (str_pos.find(a) != str_pos.end() and str_pos.find(b) != str_pos.end()) {
            int l = str_pos[a], r = str_pos[b];
            if (l > r) swap(l, r);

            if (r - l != 1)
                c[l + 1] += 1, c[r] -= 1;
            else {
                c[l - 1] += 1;
                c[l] -= 1;
                c[r + 1] += 1;
                c[r + 2] -= 1;
            }
        }
    }
    vector<int> b(m + 3);
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        b[i] = c[i] + b[i - 1];
        mx = max(mx, b[i]);
    }
    vector<string> s;
    for (int i = 1; i <= m; i++) {
        if (b[i] == mx) {
            if (vis[str[i]] == false)
                s.push_back(str[i]);
        }
    }

    std::sort(s.begin(), s.end());
    int len = s.size();
    for (int i = 0; i < len - 1; i++)
        cout << s[i] << " ";
    cout << s[s.size() - 1];
    return 0;
}
