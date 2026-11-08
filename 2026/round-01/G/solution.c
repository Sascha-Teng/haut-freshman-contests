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
