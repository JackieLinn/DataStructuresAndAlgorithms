#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n, m, i, j, pos, sum, len, mlen = 0, t = 0;
    cin >> n;
    m = sqrt(n);
    int s[m];
    for (i = 2; i <= m + 1; i++) //连续因子相乘后还是因子，因此符合题意的因子肯定只在2~sqrt(n)+1之间
    {
        if (n % i == 0)
            s[t++] = i;
    }
    if (t == 0)//说明是素数
        cout << '1' << endl << n << endl;
    else if (t == 1)//如果只有一个因数，那么最长连续因子的个数为1，最小的连续因子序列就为s[0]
        cout << '1' << endl << s[0] << endl;
    else//大于两个因数则进入循环
    {
        for (i = 0; i < t - 1; i++) {
            sum = s[i];
            len = 1;
            for (j = i; j < t - 1; j++) {
                if (s[j + 1] - s[j] == 1 && n % (sum * s[j + 1]) == 0)//判断是否连续  连续的话判断相乘后是否还是因子
                {//因为题目要求的是连续因子，既要连续，连续相乘后还得是因子
                    sum = sum * s[j + 1];
                    len++;
                } else//不符合直接跳出，判断以下一个因子开始的序列是否符合
                    break;
            }
            if (len > mlen)//如果长度大于最大长度则记录开始的因子序列
            {//如果等于则不变，因为题目要求输出的是在序列最长的情况下输出最小连续因子
                mlen = len;//更新最长序列
                pos = i;
            }
        }
        cout << mlen << endl;//按要求输出
        cout << s[pos];
        for (i = pos + 1; i < pos + mlen; i++)
            cout << '*' << s[i];
        cout << endl;
    }
    return 0;
}
