#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char chess[N][8][8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                cin >> chess[i][j][k];
            }
        }
    }
    char chessTemp[8][8];
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << "1" << endl;
        else {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 8; k++) {    //把每个局面提取出来
                    chessTemp[j][k] = chess[i][j][k];
                }
            }
            int sum = 1;
            for (int a = 0; a < i; a++) {    //和之前的局面比较
                bool flag = false;
                for (int b = 0; b < 8; b++) {
                    for (int c = 0; c < 8; c++) {
                        if (chessTemp[b][c] != chess[a][b][c]) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
                if (!flag) sum++;
                if (a == i - 1) cout << sum << endl;
            }
        }
    }
    return 0;
}