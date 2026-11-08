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
