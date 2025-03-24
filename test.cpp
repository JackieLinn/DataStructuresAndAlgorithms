#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << *lower_bound(a, a + 10, 2) << endl;
    cout << *upper_bound(a, a + 10, 2) << endl;
    vector<int> b = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << *b.begin() << endl;
    cout << *b.rbegin() << endl;
    cout << *lower_bound(b.begin(), b.end(), 2) << endl;
    cout << *upper_bound(b.begin(), b.end(), 2) << endl;
    return 0;
}