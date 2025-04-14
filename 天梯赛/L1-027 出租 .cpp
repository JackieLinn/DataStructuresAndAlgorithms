#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int> idx;

int find(int x) {
    for (int i = 0; i < arr.size(); i++) if (arr[i] == x) return i;
    return -1;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) arr.push_back(s[i] - '0');
    sort(arr.begin(), arr.end(), greater<int>());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    for (int i = 0; i < s.size(); i++) idx.push_back(find(s[i] - '0'));
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < arr.size(); i++) {
        if (i == arr.size() - 1) cout << arr[i] << "};" << endl;
        else cout << arr[i] << ",";
    }
    cout << "int[] index = new int[]{";
    for (int i = 0; i < idx.size(); i++) {
        if (i == idx.size() - 1) cout << idx[i] << "};" << endl;
        else cout << idx[i] << ",";
    }
    return 0;
}