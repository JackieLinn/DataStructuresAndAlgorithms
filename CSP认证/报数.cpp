#include <bits/stdc++.h>

using namespace std;

int n;
int q[4];    // 表示甲乙丙丁跳过的次数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    int sum = 0;    // 用来记录不包括跳过一共报了多少次，到n退出循环
    int x = 1;    // 用来记录是第几轮
    for (int i = 1;; i++) {
        if (sum == n) break;
        if (i % 4 == 0) x++;
        if (i % 7 == 0) {
            int temp;
            if (i % 4 == 0) temp = i - 4 * (x - 2);
            else temp = i - 4 * (x - 1);
            q[temp - 1]++;
            continue;
        } else {
            int temp1 = i;
            bool flag = true;
            while (temp1 != 0) {
                int judge = temp1 % 10;
                if (judge == 7) {
                    int temp2;
                    if (i % 4 == 0) temp2 = i - 4 * (x - 2);
                    else temp2 = i - 4 * (x - 1);
                    q[temp2 - 1]++;
                    flag = false;
                    break;
                }
                temp1 /= 10;
            }
            if (flag) sum++;
        }
    }
    for (int i: q) cout << i << endl;
    return 0;
}