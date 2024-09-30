#include <bits/stdc++.h>

using namespace std;

int n;
string a[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    if (n == 0) cout << a[n] << endl;
    else {
        if (n < 0) {
            cout << "fu ";
            n = -n;
        }
        vector<int> A;
        for (int i = 0; n > 0; i++) {
            A.push_back(n % 10);
            n /= 10;
        }
        for (int i = A.size() - 1; i >= 0; i--) {
            if (i == 0) cout << a[A[i]];
            else cout << a[A[i]] << " ";
        }
    }
    return 0;
}