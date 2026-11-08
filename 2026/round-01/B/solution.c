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
