#include <bits/stdc++.h>
using namespace std;
int x[3][2], y[3][2];

int f(int a, int b)
{
    int x1=max(x[a][0], x[b][0]), y1=max(y[a][0], y[b][0]);
    int x2=min(x[a][1], x[b][1]), y2=min(y[a][1], y[b][1]);
    return max(0, x2-x1)*max(0, y2-y1);
}

int main()
{
    for(int i=0; i<3; i++)
        for(int j=0; j<2; j++)
            cin>>x[i][j]>>y[i][j];
    int res=0;
    for(int i=0; i<2; i++)
        res+=f(i, i)-f(i, 2);
    cout<<res;
    return 0;
}
 
