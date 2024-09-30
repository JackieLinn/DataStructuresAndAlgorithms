#include <bits/stdc++.h>

using namespace std;

struct node {
    int distance; //距离
    int id;       //检测点编号
};

bool cmp(node n1, node n2) {
    if (n1.distance == n2.distance) return n1.id < n2.id;
    return n1.distance < n2.distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, X, Y;
    cin >> n >> X >> Y;

    node ans[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ans[i].distance = pow(X - x, 2) + pow(Y - y, 2);
        ans[i].id = i + 1;
    }
    sort(ans, ans + n, cmp);
    for (int i = 0; i < 3; i++) cout << ans[i].id << endl;
    return 0;
}