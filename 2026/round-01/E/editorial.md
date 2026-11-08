# E · 回首

[牛客原题](https://ac.nowcoder.com/acm/contest/143651/E) · [题面](problem.md)

## 解题思路

恰好改变两次方向，意味着整条路线分为三段，每段都至少走一步。

设第一次折返位置为 $x$，第二次折返位置为 $y$，路线就是 $s\to x\to y\to e$。枚举 $0\le x,y\le L$，检查两种方向：

- 先右、再左、最后右：$x>s$、$y<x$、$e>y$。
- 先左、再右、最后左：$x<s$、$y>x$、$e<y$。

符合其中一种方向后，再检查总步数：

$$
|x-s|+|y-x|+|e-y|=T.
$$

满足就将答案加一。$L$ 最大为 500，只需检查 $501^2=251001$ 对位置，不需要按可能达到十亿的 $T$ 一分钟一分钟模拟。

## 正确性说明

任何合法路线都有唯一的两次折返位置，因此会被枚举到。严格的大小关系保证三段都非空，且方向恰好变化两次。每段单向行走，两个端点都在区间内，所以中途也不会越界；步数检查保证恰好用时 T。反过来，通过所有检查的位置对确定唯一合法路线。因此没有遗漏，也没有重复计算。

## 复杂度分析

两层循环各枚举 $L+1$ 个位置，时间复杂度 $O(L^2)$，额外空间复杂度 $O(1)$。

## C 语言参考代码

[下载源文件](solution.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int L, s, e, T;
    scanf("%d%d%d%d", &L, &s, &e, &T);

    int ans = 0;
    for (int x = 0; x <= L; x++)
    {
        for (int y = 0; y <= L; y++)
        {
            int rightFirst = x > s && y < x && e > y;
            int leftFirst = x < s && y > x && e < y;
            int steps = abs(x - s) + abs(y - x) + abs(e - y);
            if ((rightFirst || leftFirst) && steps == T)
                ans++;
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
    int L, s, e, T;
    cin >> L >> s >> e >> T;

    int ans = 0;
    for (int x = 0; x <= L; x++)
    {
        for (int y = 0; y <= L; y++)
        {
            int rightFirst = x > s && y < x && e > y;
            int leftFirst = x < s && y > x && e < y;
            int steps = abs(x - s) + abs(y - x) + abs(e - y);
            if ((rightFirst || leftFirst) && steps == T)
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
```

C 版本使用 C99 或更新标准编译，C++ 版本使用 C++11 或更新标准编译。

## 易错点

- 方向判断必须使用严格不等号，否则可能把长度为零的段计入。
- 只检查总步数不够，还必须检查方向。
- 出发前、到达后的转身不计入。
- $T$ 很大也不必循环 $T$ 次；三段总长最多为 $3L$。
