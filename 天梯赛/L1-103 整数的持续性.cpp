#include<bits/stdc++.h>

using namespace std;

int check(int x) {
    if (x < 10) return 0;
    int cnt = 0;
    while (x > 10) {
        int tmp = x;
        int num = 1;
        while (tmp) {
            num *= tmp % 10;
            tmp /= 10;
        }
        cnt++;
        x = num;
    }
    return cnt;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = -100;
    vector<int> nums;
    for (int i = a; i <= b; i++) {
        int cnt = check(i);
        if (cnt > ans) {
            ans = cnt;
            nums.clear();
            nums.push_back(i);
        } else if (cnt == ans) nums.push_back(i);
    }
    sort(nums.begin(), nums.end());
    cout << ans << endl;
    for (int i = 0; i < nums.size(); i++) {
        if (i == nums.size() - 1) cout << nums[i];
        else cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}