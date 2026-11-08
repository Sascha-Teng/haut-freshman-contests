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
