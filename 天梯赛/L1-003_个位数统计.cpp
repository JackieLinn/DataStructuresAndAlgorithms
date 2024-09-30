#include <bits/stdc++.h>

using namespace std;

int a[10];
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string n;
    cin >> n;

    for (int i = n.size() - 1; i >= 0; i--) A.push_back(n[i] - '0');
    for (int i: A) a[i]++;
    for (int i = 0; i < 10; i++) {
        if (a[i]) cout << i << ":" << a[i] << endl;
    }
    return 0;
}