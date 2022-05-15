#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y; cin>>x>>y;
    int ans=0, dist=1, d=1;
    //dist: 距离
    //d: 方向(1向右 -1向左)
    while(1)
    {
        if((d==1 && x<=y && y<=x+dist) || (d==-1 && y<=x && x<=y+dist))
        {
            //找到了Bessie
            ans+=abs(y-x);
            cout<<ans;
            break;
        }
        //没有找到Bessie
        else dist*=2, ans+=dist, d*=-1;
    }
    return 0;
}

