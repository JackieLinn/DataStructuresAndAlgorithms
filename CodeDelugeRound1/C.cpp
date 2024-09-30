#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c, s;
    cin >> s;
    cin >> a >> b >> c;
    if (a * b * c == s) cout << "* *" << endl;
    else if (a + b + c == s) cout << "+ +" << endl;
    else if (a - b - c == s) cout << "- - " << endl;
    else if (a * b + c == s) cout << "* +" << endl;
    else if ((a + b) * c == s) cout << "+ *" << endl;
    else if (a * b - c == s) cout << "* -" << endl;
    else if ((a - b) * c == s) cout << "- *" << endl;
    else if (a + b - c == s) cout << "+ -" << endl;
    else if (a - b + c == s) cout << "- +" << endl;
    return 0;
}