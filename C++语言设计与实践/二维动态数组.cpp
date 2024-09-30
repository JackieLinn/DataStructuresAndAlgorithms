#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 4;
    int(*pb1)[5] = new int[n][5];   // 数组指针, pb1是行指针
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            pb1[i][j] = i * j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cout << pb1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}