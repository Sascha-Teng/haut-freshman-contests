#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;

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
    cout << ans << '\n';
    return 0;
}
