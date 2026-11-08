#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int L, s, e, T;
    cin >> L >> s >> e >> T;

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
    cout << ans << '\n';
    return 0;
}
