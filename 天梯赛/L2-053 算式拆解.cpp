#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ')') st.push(s[i]);
        else {
            vector<char> tmp;
            while (st.top() != '(') {
                tmp.push_back(st.top());
                st.pop();
            }
            st.pop();
            for (int j = tmp.size() - 1; j >= 0; j--) cout << tmp[j];
            cout << endl;
        }
    }
    return 0;
}