

# DP专题

## 线性DP

### 数字三角形

#### 正序做法

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) 
            cin >> a[i][j];
            
    for (int i = 1; i <= n + 10; i++) 
        for (int j = 0; j <= i + 10; j++) // f[N]初始化的时候，前后都要初始化多一点
        	f[i][j] = -INF;
    
    f[1][1] = a[1][1];	// 第一层就不用算了
    for (int i = 2; i <= n; i++) 
        for (int j = 1; j <= i; j++) 
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
        
    int res = -INF;
    for (int i = 1; i <= n; i++) res = max(res, f[n][i]);	// 遍历最后一行找到最优解
    cout << res << endl;
    return 0;
}
```

#### 倒序做法

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) 
            cin >> a[i][j];
            
    for (int i = n; i >= 1; i--) 
        for (int j = i; j >= 1; j--)
            f[i][j] = max(f[i + 1][j + 1] + a[i][j], f[i + 1][j] + a[i][j]);
            
    cout << f[1][1] << endl;
    return 0;
}
```

### 最长上升子序列

#### 朴素做法

时间复杂度是 $O(n^2)$

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        f[i] = 1;	// 只有a[i]一个数
        for (int j = 1; j < i; j++) 
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}
```

#### 优化做法法国防护

`q[len] = a`表示最长上升子序列长度为`len`的时候，结尾的最小值是`a`。二分的时候，`l`可以写-1或者0，而`r`只能是`len + 1`。

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], q[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i <= n; i++) q[i] = -(1e9 + 10);
    
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = -1, r = len + 1;
        while (l + 1 != r) {
            int mid = l + r >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid;
        }
        len = max(len, l + 1);
        q[l + 1] = a[i];
    }
    cout << len << endl;
    return 0;
}
```

### 最长公共子序列

[AcWing 897. 最长公共子序列（思路超清晰） - AcWing](https://www.acwing.com/solution/content/48820/)

主要是要注意理解`f[i][j - 1]`集合的理解，`j`一定不在里面，而`i`可能在也可能不在，所以它包括的情况比较多。另外一个也类似。

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
    cin >> n >> m;
    cin >> a + 1 >> b + 1;	// 下标从1开始
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            // 对于同时包含两个的情况，一定要相等才存在
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    
    cout << f[n][m] << endl;
    return 0;
}
```

### 最短编辑距离

主要是要注意理解`f[i][j]`表示`a`的前`i`个字符和`b`的前`j`个字符匹配的最小操作次数。

`f[i - 1][j]`表示需要删除`a[i]`，`f[i][j - 1]`表示需要增加`a[i]`，`f[i - 1][j - 1]`判断看需不需要改。

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
    cin >> n >> a + 1;
    cin >> m >> b + 1;
    
    for (int i = 0; i <= m; i++) f[0][i] = i;
    for (int i = 0; i <= n; i++) f[i][0] = i;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1;  j <= m; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
```

### 编辑距离

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 15, M = 1010;

int n, m;
char str[M][N];
int f[N][N];

int edit_distance(char a[], char b[]) {
    int la = strlen(a + 1), lb = strlen(b + 1);
    for (int i = 0; i <= lb; i++) f[0][i] = i;
    for (int i = 0; i <= la; i++) f[i][0] = i;
    
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return f[la][lb];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> str[i] + 1;
    
    while (m --) {
        char s[N];
        int limit;
        cin >> s + 1 >> limit;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (edit_distance(str[i], s) <= limit) res ++;
        }
        cout << res << endl;
    }
    return 0;
}
```



## 区间DP

### 区间合并

[AcWing 282. 石子合并详细解释版 - AcWing](https://www.acwing.com/solution/content/21818/)

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 310;

int n;
int s[N];
int f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];
    
    // 区间DP模版一般都是先枚举一下区间长度
    for (int len = 2; len <= n; len++) {
        // 枚举一下起点
        for (int i = 1; i <= n - len + 1; i++) {
            int l = i, r = i + len - 1;
            f[l][r] = 1e9;	// 取最小值要初始化成最大值
            // 枚举分界处
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
```

