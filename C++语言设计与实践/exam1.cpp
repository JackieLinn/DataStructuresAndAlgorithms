#include <bits/stdc++.h>

using namespace std;

namespace abc {
    int add(int a = 0, int b = 0, int c = 0);
}

int add();

int add(int a);

int add(int a, int b);

//int add(int a = 0, int b = 0, int c = 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, y, z;
    cout << "请输入三个整数：\n";
    cin >> x >> y >> z;
    cout << add() << endl;
    cout << add(x) << endl;
    cout << add(x, y) << endl;
    cout << abc::add(x, y, z) << endl;
    return 0;
}

int add() {
    return 0;
}

int add(int a) {
    return a;
}

int add(int a, int b) {
    return a + b;
}

int add(int a = 0, int b = 0, int c = 0) {
    return a + b + c;
}

// 1 2 3