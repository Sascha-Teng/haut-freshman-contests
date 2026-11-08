#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    puts("...+---+");
    for (int i = 0; i < n; i++)
    {
        puts("../.....\\");
        puts(".+.......+");
        puts("..\\...../");
        puts("...+---+");
    }
    return 0;
}
