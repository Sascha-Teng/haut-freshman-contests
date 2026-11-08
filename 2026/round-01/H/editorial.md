# H · 一步之遥

[牛客原题](https://ac.nowcoder.com/acm/contest/143651/H) · [题面](problem.md)

## 解题思路

位数相同的正整数，从左到右比较，第一处不同的数位越小，整个数就越小。因此，我们希望从左到右，每次选择尽可能小的数字。

但不能只看当前：选了一个小数字后，剩余位置可能无法凑出要求的数位和。例如样例 `4 16`，首位若选 2，后面即使依次选 3、4、5，总和也只有 14。

### 先记录剩余位置能否填完

用 `can[len][prev][sum]` 记录一件事：前一位数字是 `prev`，后面还要填 `len` 位，能否让这 `len` 位的数位和恰好为 `sum`，并满足相邻数位差不超过 1。值为 1 表示能，0 表示不能。

这里的 `sum` 不包括前一位 `prev`。

- 没有剩余位置时，只能凑出和 0，所以 `can[0][prev][0] = 1`，其余情况为 0。
- 还有位置时，尝试下一位数字 `d`。它必须在 0 到 9 之间，且与 `prev` 的差不超过 1。
- 如果 `sum >= d`，并且 `can[len - 1][d][sum - d]` 为 1，就说明选择 `d` 后，剩下的部分也能填完，因此当前情况可行。

按 `len` 从小到大计算，所需的较短情况就都已经算好了。这种先记录小问题答案、再解决大问题的方法称为动态规划；本题只需把它理解为一张“能否填完”的表。

### 再从左到右填写答案

第一位按 1 到 9 尝试，其余位按 0 到 9 尝试。每个候选数字需要满足相邻限制，并且查表确认剩余位置能补足目标和。

选择第一个可行数字，减去它占用的数位和，继续填下一位。如果找不到可行数字，输出 `-1`。

答案最多有 100 位，不能存进普通整数变量。用字符数组保存，每个数字转换成 `'0' + d`，最后补上字符串结束符 `\0`。

## 正确性说明

当剩余长度为 0 时，只有和为 0 的情况可行，初始化正确。对更长的情况，任何合法填法的下一位都必须满足相邻限制，余下部分恰好是表中更短的情况；反过来，符合相邻限制的下一位与一个可行的余下部分拼接后一定合法。因此按长度计算的表准确记录了所有可行情况。

构造答案时，每次查表都保证当前选择能扩展为完整合法答案。又因为数字从小到大尝试，选到的是在当前前缀下最小的可行数字。如果存在更小的合法答案，在与当前答案首次不同的位置，它必须使用更小且可行的数字，这与我们已经选择最小可行数字矛盾。因此构造结果就是最小答案。

如果没有候选数字可选，表明不存在满足要求的补全，输出 `-1` 正确。

## 复杂度分析

表有 $(n+1)\times10\times(s+1)$ 个位置，每个位置最多检查 10 个数字。因此时间复杂度为 $O(n\times s\times10\times10)$；10 是固定常数，也可写作 $O(ns)$。构造答案另需 $O(10n)$ 时间。

表的空间复杂度为 $O(10ns)$，即 $O(ns)$，答案还需 $O(n)$ 空间。代码按题目上限分配 `101 × 10 × 901` 个字节，约 0.87 MiB，放在全局区。

## C 语言参考代码

[下载源文件](solution.c)

```c
#include <stdio.h>
#include <stdlib.h>

/* 全局数组自动初始化为 0 */
static unsigned char can[101][10][901];

int main(void)
{
    int n, s;
    scanf("%d%d", &n, &s);
    /* can[len][prev][sum]: 前一位为 prev，后面 len 位能否凑出 sum */
    for (int prev = 0; prev <= 9; prev++)
        can[0][prev][0] = 1;

    for (int len = 1; len <= n; len++)
    {
        for (int prev = 0; prev <= 9; prev++)
        {
            for (int sum = 0; sum <= s; sum++)
            {
                for (int d = 0; d <= 9; d++)
                {
                    if (abs(d - prev) <= 1 && sum >= d &&
                        can[len - 1][d][sum - d])
                    {
                        can[len][prev][sum] = 1;
                        break;
                    }
                }
            }
        }
    }

    char answer[101];
    int remaining = s;
    int prev = 0;
    for (int pos = 0; pos < n; pos++)
    {
        int chosen = -1;
        for (int d = (pos == 0 ? 1 : 0); d <= 9; d++)
        {
            if (pos > 0 && abs(d - prev) > 1)
                continue;
            if (remaining >= d && can[n - pos - 1][d][remaining - d])
            {
                chosen = d;
                break;
            }
        }
        if (chosen == -1)
        {
            puts("-1");
            return 0;
        }
        answer[pos] = (char)('0' + chosen);
        remaining -= chosen;
        prev = chosen;
    }
    answer[n] = '\0';
    puts(answer);
    return 0;
}
```

## C++参考代码

[下载源文件](solution.cpp)

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

/* 全局数组自动初始化为 0 */
static unsigned char can[101][10][901];

int main()
{
    int n, s;
    cin >> n >> s;
    /* can[len][prev][sum]: 前一位为 prev，后面 len 位能否凑出 sum */
    for (int prev = 0; prev <= 9; prev++)
        can[0][prev][0] = 1;

    for (int len = 1; len <= n; len++)
    {
        for (int prev = 0; prev <= 9; prev++)
        {
            for (int sum = 0; sum <= s; sum++)
            {
                for (int d = 0; d <= 9; d++)
                {
                    if (abs(d - prev) <= 1 && sum >= d &&
                        can[len - 1][d][sum - d])
                    {
                        can[len][prev][sum] = 1;
                        break;
                    }
                }
            }
        }
    }

    char answer[101];
    int remaining = s;
    int prev = 0;
    for (int pos = 0; pos < n; pos++)
    {
        int chosen = -1;
        for (int d = (pos == 0 ? 1 : 0); d <= 9; d++)
        {
            if (pos > 0 && abs(d - prev) > 1)
                continue;
            if (remaining >= d && can[n - pos - 1][d][remaining - d])
            {
                chosen = d;
                break;
            }
        }
        if (chosen == -1)
        {
            cout << "-1\n";
            return 0;
        }
        answer[pos] = (char)('0' + chosen);
        remaining -= chosen;
        prev = chosen;
    }
    answer[n] = '\0';
    cout << answer << '\n';
    return 0;
}
```

C 版本使用 C99 或更新标准，C++ 版本使用 C++11 或更新标准。

## 易错点

- 第一位不能是 0，后面的位可以是 0。
- 差的绝对值“不超过 1”包括相邻数字相等。
- 只选当前最小数字不够，必须确认后面能补足数位和。
- 查表前检查剩余和不小于候选数字，避免负数下标。
- 答案使用字符串，不能用 `int` 或 `long long` 保存。
