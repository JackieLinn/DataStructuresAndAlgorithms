#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
const int D = 20;

long long Q[N][D], K[N][D], V[N][D], W[N];
long long temp[N][N], result[N][D];
long long resultTemp[D][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, d;
    //以下均为输入
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> Q[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> K[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> V[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
/*    //此处会出现n方，时间空间都无比巨大；下面优化为d方，相对缩小很多
    int KTemp[d][n];    //K的转置
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            KTemp[i][j] = K[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < d; k++) {
                temp[i][j] += Q[i][k] * KTemp[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] *= W[i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += temp[i][k] * V[k][j];
            }
        }
    }*/
    //以下为转置化简后矩阵的初步处理
    long long VTemp[d][n], QTemp[d][n];
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            VTemp[i][j] = V[j][i];
        }
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            QTemp[i][j] = Q[j][i];
        }
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            QTemp[i][j] *= W[j];
        }
    }
    //下面开始结合律计算
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < n; k++) {
                temp[i][j] += VTemp[i][k] * K[k][j];
            }
        }
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < d; k++) {
                resultTemp[i][j] += temp[i][k] * QTemp[k][j];
            }
        }
    }
    //计算之后最后转置（化简中最后带有转置）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            result[i][j] = resultTemp[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}