# D · 故站

[牛客原题](https://ac.nowcoder.com/acm/contest/143651/D) · [题面](problem.md)

## 解题思路

本题没有输入，只需要输出题目指定的一行文字：

```text
Hautoj will be back?
```

C 可以用 `puts` 输出字符串并自动换行；C++ 可以用 `cout` 输出字符串与换行符。

## 正确性说明

程序直接输出题目要求的字符串，大小写、空格和问号完全一致，因此满足要求。

## 复杂度分析

输出长度固定，时间复杂度和额外空间复杂度均为 $O(1)$。

## C 语言参考代码

[下载源文件](solution.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("Hautoj will be back?");
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
    cout << "Hautoj will be back?\n";
    return 0;
}
```

C 版本使用 C99 或更新标准编译，C++ 版本使用 C++11 或更新标准编译。

## 易错点

- `Hautoj` 只有首字母大写。
- 使用半角问号，单词之间是一个空格。
- 样例输入中的“无”表示没有输入，不需要读取这个字。
- 不要输出引号或提示文字。
