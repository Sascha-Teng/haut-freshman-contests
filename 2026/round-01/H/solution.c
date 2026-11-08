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
