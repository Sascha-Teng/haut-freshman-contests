#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    long long r, y;
    cin >> r >> y;

    long long ans = 2 * (r < y ? r : y);
    cout << ans << '\n';
    return 0;
}
