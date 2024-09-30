#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1010;
LL a[N][N];


vector<int> add(vector<int> &A, LL &sum) {
    vector<int> B;
    vector<int> C;
    while (sum / 10 != 0) {
        B.push_back(sum % 10);
        sum /= 10;
    }
    if (sum) B.push_back(sum);
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    sum = 0;
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    LL sum = 0;
    int temp = 1;
    int i, j;
    vector<int> A;
    A.push_back(0);
    for (i = 1; i <= n; i += 2) {
        for (j = 1; j <= m; j++) {
            sum += a[i][j];
        }
        A = add(A, sum);
        if (i == n && j == m) break;

        if (temp % 2 == 1) {
            sum += a[i + 1][m];
            A = add(A, sum);
        } else {
            sum += a[i + 1][1];
            A = add(A, sum);
        }
        if (i == n && j == m) break;
        temp++;
        if ((i + 2) == n) {
            if (temp % 2 == 0) {
                sum += a[n][m];
                A = add(A, sum);
                break;
            }
        }
    }
    for (int k = A.size() - 1; k >= 0; k--) cout << A[k];
    cout << endl;
    return 0;
}

//7 6
//2 8 6 3 5 2
//7 5 6 3 1 6
//7 4 2 8 6 9
//6 2 5 4 8 8
//2 3 8 9 1 5
//7 2 6 9 1 7
//2 3 4 5 6 7