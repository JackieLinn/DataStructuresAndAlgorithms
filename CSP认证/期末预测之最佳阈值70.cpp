#include <bits/stdc++.h>    //70分解法，时间复杂度为O(n^2)

using namespace std;

typedef long long LL;

struct node1 {
    int y;    //安全指数
    int result;    //挂科情况，0表示挂科，1表示没有挂科
};

struct node2 {
    int xita;    //阈值
    int sum;    //预测正确的次数
};

bool cmp(node2 n1, node2 n2) {
    if (n1.sum == n2.sum) return n1.xita > n2.xita;
    return n1.sum > n2.sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m;
    node1 a[m];
    for (int i = 0; i < m; i++) cin >> a[i].y >> a[i].result;

    node2 b[m];
    for (int i = 0; i < m; i++) {
        b[i].xita = a[i].y;
        b[i].sum = 0;
        for (int j = 0; j < m; j++) {
            if (a[j].y >= b[i].xita && a[j].result == 1 || a[j].y < b[i].xita && a[j].result == 0)
                b[i].sum++;
        }
    }
    sort(b, b + m, cmp);
    cout << b[0].xita << endl;
    return 0;
}
/*

#include <bits/stdc++.h>    //70分解法，时间复杂度为O(n^2)

using namespace std;

typedef long long LL;

struct node1 {
    int y;    //安全指数
    int result;    //挂科情况，0表示挂科，1表示没有挂科
};

bool cmp(node1 n1, node1 n2) {
    return n1.y < n2.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m;
    node1 a[m];
    for (int i = 0; i < m; i++) cin >> a[i].y >> a[i].result;
    sort(a, a + m, cmp);
    vector<int> xita;
    xita.push_back(a[0].y);
    for (int i = 1; i < m; i++)
        if (a[i].y > a[i - 1].y) xita.push_back(a[i].y);
    int sum[xita.size()], max = 0;
    for (int i = 0; i < xita.size(); i++) {
        sum[i] = 0;
        for (int j = 0; j < m; j++) {
            if (a[j].y >= xita[i] && a[j].result == 1 || a[j].y < xita[i] && a[j].result == 0)
                sum[i]++;
        }
        if (sum[i] >= sum[max]) max = i;
    }
    cout << xita[max] << endl;
    return 0;
}*/
