#include<iostream>
using namespace std;

const int N=100005;
int n,m,ans;
int a[N];
char s[N];


bool check(int x) {
    int p=1-x,cnt=0;//cnt不一定恒等于2，小于2代表方案不合理，大于等于2代表方案合理 
    for(int i=1; i<=m; i++) {
        while(p+x+x<=a[i]) p+=x,cnt++;//如果符合条件，p就往后移动x的距离，牛的头数就加一头 
        p=a[i];//令p=a[i],p就是前一头牛的位置 
    }
    while(p+x<=n) p+=x,cnt++; //因为存在插入位置没包含最后一个位置n的情况，所以需要继续往后加牛，直到加到不能加位置 
    return cnt>=2;//如果加入的牛的数量大于等于2，证明我们的方案是可行的，即x是一种答案 
}

int main() {
    cin>>n;
    cin>>s+1;
    for(int i=1; i<=n; i++)
        if(s[i]=='1') a[++m]=i;
    int l=1,r=n;
    for(int i=1; i<m; i++) r=min(r,a[i+1]-a[i]);
    while(l<=r) {
        int mid=l+r>>1;
        if(check(mid)) {
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    cout<<ans;
    return 0;
}
 
