#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int sum = 0;
    int a = n;
    for (int i = 0; i < a; i++) {
        if (n >= 10) {
            int temp1 = n;
            while (temp1 != 0) {
                int temp2 = temp1 % 10;
                temp1 /= 10;
                if (temp2 == x) sum++;
            }
        } else if (n == x) sum++;
        n--;
    }
    cout << sum << endl;
    return 0;
}