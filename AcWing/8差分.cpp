#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];    //a是b的前缀和，b是a的差分

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //由于初始化的a和b数组全是0.默认就是b是a的差分数组，上面a数组已经插入了元素，通过这个循环来重新构造b数组，使得b数组是a数组的差分数组
    for (int i = 1; i <= n; i++) insert(i, i, a[i]);
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];    //把b数组构造成自己的前缀和,用来替换a数组
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    return 0;
}