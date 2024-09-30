#include <bits/stdc++.h>

using namespace std;

void fun() {
    static int n = 0;
    int m = 0;
    n++;
    m++;
    cout << m << " " << n << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 4; i++) {
        fun();
    }
    return 0;
}