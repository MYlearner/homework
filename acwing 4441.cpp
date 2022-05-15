#include<iostream>
#include<algorithm>
using namespace std;
//#include<bits/stdc++.h>
#define ll long long
const int N = 100010;
typedef pair<int, char> PII;
PII a[N];
int main()
{
    int n,ans=0x3f3f3f3f;
    char b;
    cin >> n;
    for (int i = 0,x; i < n; i++)
    {
        cin >> b >> x;
        a[i] = { x,b };
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j].second == 'L')
            {
                if (a[j].first < a[i].first)m++;
            }
            else
            {
                if (a[j].first > a[i].first)m++;
            }   
        }
        ans = min(ans, m);
    }
    cout << ans;
    return 0;
}
