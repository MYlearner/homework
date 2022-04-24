#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;    cin >> n;
    int m;    cin >> m;

    int cur = n;
    int day = 0;
    while (cur > 0)
    {
        cur --;
        day ++;
        if (day % m == 0)
        {
            cur ++;
        }
    }

    cout << day << endl;
    return 0;
}

