#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int f[N];
int w[3], v[3];
int main()
{
    int x, y, m;
    for(int i = 1; i <= 2; i++) cin >> w[i], v[i] = w[i];
    cin >> m;
    for(int i = 1; i <= 2; i++)
        for(int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m];
    return 0;
}

