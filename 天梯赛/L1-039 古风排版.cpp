#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    int len = s.size();
    int row = n, col = len / n;
    if (len % n != 0) col++;
    char ch[row][col];
    int k = 0;
    bool flag = true;
    for (int i = col - 1; i >= 0; i--) {
        for (int j = 0; j < row; j++) {
            if (flag) ch[j][i] = s[k++];
            else ch[j][i] = ' ';
            if (k == len) flag = false;
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ch[i][j];
        }
        cout << endl;
    }
    return 0;
}