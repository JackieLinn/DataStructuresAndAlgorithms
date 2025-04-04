#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    ll hour = stoll(s.substr(0, 2));
    if (hour <= 12) cout << "Only "<< s <<".  Too early to Dang." << endl;
    else {
        hour -= 12;
        if (s.substr(3, 5) == "00") for (int i = 1; i <= hour; i++) cout << "Dang";
        else for (int i = 0; i <= hour; i++) cout << "Dang";
    }
    return 0;
} 