#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5];
    for(int i=1;i<=4;i++) cin>>a[i];
    if (a[2]<a[3] or a[1]>a[4]) cout<<a[2]-a[1]+a[4]-a[3]<<endl;
    else cout<<max(a[2],a[4])-min(a[1],a[3])<<endl;
    return 0;
}
