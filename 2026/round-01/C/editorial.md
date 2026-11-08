# C · 藤萱

[牛客原题](https://ac.nowcoder.com/acm/contest/143651/C) · [题面](problem.md)

## 解题思路

设数量较少的颜色有 $m=\min(r,y)$ 朵。每朵这种颜色的花最多与两朵另一种颜色的花相邻，因此美丽值最多为 $2m$。

这个上限可以达到：两种颜色先交替排成一圈；如果较多的颜色还有剩余，把剩余花插入同色花旁边，不会减少原有的异色相邻对数。所以答案是 $2\min(r,y)$。如果某种颜色为零，答案就是零。

## 正确性说明

每一对异色相邻花朵都恰好包含一朵数量较少的颜色的花，每朵这样的花最多贡献两对，因此答案不超过两倍的较少数量。交替排列，并将剩余的同色花接在同色位置，能够达到这个上限，所以公式给出的就是最大值。

## 复杂度分析

时间复杂度 $O(1)$，额外空间复杂度 $O(1)$。

## C 语言参考代码

[下载源文件](solution.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long r, y;
    scanf("%lld%lld", &r, &y);

    long long ans = 2 * (r < y ? r : y);
    printf("%lld\n", ans);
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
    long long r, y;
    cin >> r >> y;

    long long ans = 2 * (r < y ? r : y);
    cout << ans << '\n';
    return 0;
}
```

C 版本使用 C99 或更新标准编译，C++ 版本使用 C++11 或更新标准编译。

## 易错点

- 这是花环，首尾也相邻，不能按一条直线计算。
- 允许某一种颜色为零。
- 不需要真的生成花环，数量可能达到十亿。
