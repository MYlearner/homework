#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
    int y;
}a[101];
int n;
int main()
{
    int i,j,k,ans=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++){
                if(i==j||j==k||k==i)continue;
                if(a[i].x==a[j].x&&a[j].y==a[k].y)ans=max(ans,abs(a[i].y-a[j].y)*abs(a[j].x-a[k].x));
            }
    cout<<ans;
}

