#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y; cin>>x>>y;
    int ans=0, dist=1, d=1;
    //dist: ����
    //d: ����(1���� -1����)
    while(1)
    {
        if((d==1 && x<=y && y<=x+dist) || (d==-1 && y<=x && x<=y+dist))
        {
            //�ҵ���Bessie
            ans+=abs(y-x);
            cout<<ans;
            break;
        }
        //û���ҵ�Bessie
        else dist*=2, ans+=dist, d*=-1;
    }
    return 0;
}

