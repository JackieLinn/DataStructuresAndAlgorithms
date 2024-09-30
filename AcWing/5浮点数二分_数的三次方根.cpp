#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x;
    cin >> x;
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    /*
    此处注意区别：C++的精度输出
    加fixed是指小数点后几位
    而不加fixed是指几位有效数字
    两个不能混用，但是如果先有fixed的话会出现全部向fixed靠齐的情况
    */

//    cout << setprecision(6) << l << endl;
    cout << fixed << setprecision(6) << l << endl;
//    cout << setprecision(6) << l << endl;
    return 0;
}