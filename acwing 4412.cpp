#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=200010;
map<int,pair<int,int> > mp;
pair<int,int> p[N];

int num[N];
int main(void){
    int n,i,cnt=0,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    for(i=1;i<=n;i++){
        int x=num[i];
        if(mp.count(x)==0){
            mp[x].first=i;
            mp[x].second=i;
        }else{
            mp[x].second=i;
        }
    }
    map<int,pair<int,int> >::iterator it;
    for(it=mp.begin(),i=1;it!=mp.end();it++,i++){
        p[i].first=(*it).second.first;
        p[i].second=(*it).second.second;
    }
    sort(p,p+n+1);
    int l=0,r=0;
    for(i=0;i<=n;i++){
        if(p[i].first==0){
            continue;
        }
        if(p[i].first<r){
            r=max(p[i].second,r);
        }else{
            cnt++;
            l=p[i].first;
            r=p[i].second;
        }
    }
    cnt--;
    ans=1;
    for(i=1;i<=cnt;i++){
        ans=(ans*2)%MOD;
    }
    printf("%d\n",ans);



    return 0;
}

 
