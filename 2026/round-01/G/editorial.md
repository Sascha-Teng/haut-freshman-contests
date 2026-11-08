# G · 红雨

[牛客原题](https://ac.nowcoder.com/acm/contest/143651/G) · [题面](problem.md)

## 解题思路

$n$ 最大为 100000，整场雨最多只有 199999 分钟，可以逐分钟累加。

第 $t$ 分钟的雨滴数为：

- $t\le n$ 时，为 $t$；
- $t>n$ 时，为 $2n-t$。

每加完一分钟，就检查累计雨滴数是否达到 $k$；第一次达到时立即输出当前分钟并结束。循环结束仍没有达到，则输出 `-1`。

累计数量和 $k$ 都用 `long long` 保存，避免 32 位整数溢出。

## 正确性说明

程序按实际顺序累加每一分钟的雨滴数，所以每次检查的累计值准确。按照分钟从小到大的顺序检查，第一次达到 k 的分钟就是最早答案。如果所有分钟都不足 k，则整场雨结束也无法达到，输出 -1 正确。

## 复杂度分析

最多检查 $2n-1$ 分钟，时间复杂度 $O(n)$，额外空间复杂度 $O(1)$。

## C 语言参考代码

[下载源文件](solution.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    long long k;
    scanf("%d%lld", &n, &k);

    long long sum = 0;
    int ans = -1;
    for (int t = 1; t <= 2 * n - 1; t++)
    {
        int rain = t <= n ? t : 2 * n - t;
        sum += rain;
        if (sum >= k)
        {
            ans = t;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
```

## C++参考代码

[下载源文件](solution.cpp)

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;

    long long sum = 0;
    int ans = -1;
    for (int t = 1; t <= 2 * n - 1; t++)
    {
        int rain = t <= n ? t : 2 * n - t;
        sum += rain;
        if (sum >= k)
        {
            ans = t;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
```

C 版本使用 C99 或更新标准编译，C++ 版本使用 C++11 或更新标准编译。

## 易错点

- 第 n 分钟的峰值只出现一次。
- 判断条件是累计值 `>= k`，不只是相等。
- 在完整一分钟结束后检查，答案是分钟数。
- `k` 可达 $10^{12}$，累计雨量可达 $10^{10}$，必须用足够大的整数类型。
