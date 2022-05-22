#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n;
bool a[N][N];
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
bool iscom(int x, int y)
{
    if(a[x][y]==0) return 0;
    int cnt=0;
    for(int d=0; d<4; d++)
    {
        int x1=x+dx[d], y1=y+dy[d];
        if(x1>=0 && x1<=n && y1>=0 && y1<=n && a[x1][y1])
            cnt++;
    }
    return cnt==3;
}
int main()
{
    cin>>n;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int x, y; cin>>x>>y;
        for(int d=0; d<4; d++)
{
            int x1=x+dx[d], y1=y+dy[d];
            if(x1>=0 && x1<=n && y1>=0 && y1<=n)
                ans-=iscom(x1, y1);
        }
        a[x][y]=1;
        for(int d=0; d<4; d++)
        {
            int x1=x+dx[d], y1=y+dy[d];
            if(x1>=0 && x1<=n && y1>=0 && y1<=n)
                ans+=iscom(x1, y1);
        }
        ans+=iscom(x, y);
        cout<<ans<<endl;
    }
    return 0;
}

