#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int minn1 = 1e4, minn2 = -1e4;
ll sum;
int main()
{
    int x;
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> x;
        if(x >= 0)
            sum += x;
        if(x >= 0 && x % 2 != 0)
            minn1 = min(minn1, x);
        if(x <= 0 && x % 2 != 0)
            minn2 = max(minn2, x);
    }
    if(sum % 2 == 0) 
        sum = max(sum - minn1, sum + minn2);
    cout << sum << endl;
    return 0;
}


