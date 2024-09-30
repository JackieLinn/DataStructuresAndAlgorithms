#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int d[N];

struct node {
    string num;
    int a = 0;
    int b = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    struct node c[n];
    for (int i = 0; i < n; i++) cin >> c[i].num >> c[i].a >> c[i].b;
    cin >> m;
    for (int i = 0; i < m; i++) cin >> d[i];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j].a == d[i]) {
                cout << c[j].num << " " << c[j].b << endl;
                break;
            }
        }
    }
    return 0;
}