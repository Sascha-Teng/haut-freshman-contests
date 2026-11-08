#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n, s, p, q;
    cin >> n >> s >> p >> q;

    int ans = -1;
    int minDist = n;  // 任意两间教室的距离最多为 n - 1

    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a >= p && b >= q && c == 0)
        {
            int d = abs(i - s);

            if (d < minDist)
            {
                minDist = d;
                ans = i;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
