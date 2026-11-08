# B · 雨山

[牛客原题](https://ac.nowcoder.com/acm/contest/143651/B) · [题面](problem.md)

## 解题思路

设从左往右的累计上升量为 $U$，累计下降量为 $D$。总起伏量给出 $U+D=s$，起点与终点的高度差给出 $U-D=b-a$。

反向行进时，原来的下降变成上升，因此两个方向的上升量分别为 $U$ 和 $D$。选择较大的一个：

$$
\max(U,D)=\frac{s+|a-b|}{2}.
$$

雨量还不能超过初始水汽 $w$，所以答案为 $\min(w,(s+|a-b|)/2)$。不需要知道具体山形。

## 正确性说明

两个方程确定了两个方向的累计上升量。每上升一单位，若仍有水汽就降雨一单位，所以某个方向的雨量是该方向上升量与水汽量的较小值。选上升量较大的方向，再取水汽限制，得到最大雨量。

## 复杂度分析

时间复杂度 $O(1)$，额外空间复杂度 $O(1)$。

## C 语言参考代码

[下载源文件](solution.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long a, b, s, w;
    scanf("%lld%lld%lld%lld", &a, &b, &s, &w);

    long long diff = a >= b ? a - b : b - a;
    long long rise = (s + diff) / 2;
    long long ans = rise < w ? rise : w;
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
    long long a, b, s, w;
    cin >> a >> b >> s >> w;

    long long diff = a >= b ? a - b : b - a;
    long long rise = (s + diff) / 2;
    long long ans = rise < w ? rise : w;
    cout << ans << '\n';
    return 0;
}
```

C 版本使用 C99 或更新标准编译，C++ 版本使用 C++11 或更新标准编译。

## 易错点

- 下降不会补充水汽，不能反复使用同一份水汽。
- 高度差要取绝对值，因为可以选择方向。
- 使用 `long long`；C 的读写格式为 `%lld`。题目保证分子为偶数。
