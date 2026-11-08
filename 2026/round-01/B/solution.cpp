#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long long a, b, s, w;
    cin >> a >> b >> s >> w;

    long long diff = a >= b ? a - b : b - a;
    long long rise = (s + diff) / 2;
    long long ans = rise < w ? rise : w;
    cout << ans << '\n';
    return 0;
}
