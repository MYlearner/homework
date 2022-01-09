#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
int s[1000010],b[25010];
int main(){
    IOS;
    int n,m;
    cin>>n>>m;

    //标准差分
    for(int i = 1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        s[a]++;
        s[b+1]--;
    }
    for(int i = 1;i<=n;++i)s[i]+=s[i-1];

    //桶排序
    for(int i = 1;i<=n;++i)b[s[i]]++;  //s[i]<=25000

    //找(n+1)/2大的数
    int k = (n+1)/2;
    for(int i = 0;i<=25000;++i){
        k-=b[i];
        if(k<=0){
            cout<<i;
            return 0;
        }
    }
    return 0;
}

