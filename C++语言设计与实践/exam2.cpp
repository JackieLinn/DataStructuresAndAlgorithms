#include <bits/stdc++.h>

using namespace std;

#define pi 3.14

int fun(float r, float &s, float &l, float &v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    float r, area, length, volume;
    int flag;
    cout << "请输入一个半径：\n";
    cin >> r;
    flag = fun(r, area, length, volume);
    if (flag == 0) {
        cout << "输入的半径不合法\n";
    } else {
        cout << "圆面积为：" << area << endl;
        cout << "圆周长为：" << length << endl;
        cout << "球体积为：" << volume << endl;
    }
    return 0;
}

int fun(float r, float &s, float &l, float &v) {
    if (r <= 0) return 0;
    s = 4 * pi * pow(r, 2);
    l = 2 * pi * r;
    v = 4 * pi * pow(r, 3) / 3;
    return 1;
}

// 2