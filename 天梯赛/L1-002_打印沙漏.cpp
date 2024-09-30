#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    char c;
    cin >> n >> c;

    if (n == 1) cout << c << endl << 0 << endl;
    else {
        int temp = n - 1;
        int num = 1;
        for (int i = 3;; i += 2) {
            if (temp - 2 * i >= 0) {
                temp -= 2 * i;
                num++;
            } else break;
        }
        int a = 2;
        for (int i = 0; i < 2 * num - 1; i++) {
            int iTemp = i;
            if (i > (2 * num - 1) / 2) {
                iTemp = i - a;
                a += 2;
            }
            for (int j = 0; j < 2 * num - 1; j++) {
                if (j >= iTemp && j < (2 * num - 1) - iTemp) cout << c;
                else if (j < (2 * num - 1) - iTemp) cout << " ";
            }
            cout << endl;
        }
        cout << temp << endl;
    }
    return 0;
}