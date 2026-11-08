#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, s;
    scanf("%d%d", &n, &s);
    if (s < 1 || s > 9 * n)
    {
        puts("-1");
        return 0;
    }

    int remaining = s;
    int previous = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int d = (i == 1 ? 1 : 0); d <= 9; d++)
        {
            if (i > 1 && abs(d - previous) > 1)
                continue;

            int low = 0, high = 0;
            int smallest = d, largest = d;
            for (int k = i + 1; k <= n; k++)
            {
                if (smallest > 0) smallest--;
                if (largest < 9) largest++;
                low += smallest;
                high += largest;
            }

            int rest = remaining - d;
            if (low <= rest && rest <= high)
            {
                putchar('0' + d);
                remaining = rest;
                previous = d;
                break;
            }
        }
    }
    putchar('\n');
    return 0;
}
