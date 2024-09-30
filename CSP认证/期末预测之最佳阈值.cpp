#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
set<int> st;
pair<int, int> pr[N];
int sum[N];
int m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        pr[i] = make_pair(a, b);
    }
    sort(pr + 1, pr + m + 1);
    for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + pr[i].second;
    int max = -1, ans;
    for (int i = 1; i <= m; i++) {
        int x = pr[i].first;
        if (st.count(x)) continue;
        st.insert(x);
        int r = sum[m] - sum[i - 1];    //大于等于阈值部分的准确个数
        int l = i - (sum[i - 1] + 1);    //小于阈值部分准确个数
        int temp = l + r;
        if (temp >= max) {
            max = temp;
            ans = x;
        }
    }
    cout << ans << endl;
    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node {
    int y;
    int result;
};
set<int> st;
int sum[N];
int m;

bool cmp(node n1, node n2) {
    return n1.y < n2.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m;
    node a[m + 1];
    for (int i = 1; i <= m; i++) cin >> a[i].y >> a[i].result;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + a[i].result;
    int max = -1, ans;
    for (int i = 1; i <= m; i++) {
        int x = a[i].y;
        if (st.count(x)) continue;
        st.insert(x);
        int r = sum[m] - sum[i - 1];
        int l = i - (sum[i - 1] + 1);
        int temp = l + r;
        if (temp >= max) {
            max = temp;
            ans = x;
        }
    }
    cout << ans << endl;
    return 0;
}*/
