#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int flag[1000010]={0};
    int n,k;
    int num[500010]={0};
    cin>>n>>k;
    for(int i=0;i<n;++i)
    cin>>num[i];
    int left=0;
    int right=0;
    int left1=0;
    int right1=0;
    if(k>=n)
    cout<<1<<" "<<n<<endl;
   else{
    int length=0;
    int k1=0;
    for(int i=0;i<n;++i)
    {
        flag[num[i]]++;
        if(flag[num[i]]==1)
        {
            k1++;
        }
        if(k1<=k)
        {
            if((i-left+1)>length)
            {
                length=i-left+1;
                right1=i;
                left1=left;
            }
            
        }
        if(k1>k)
        {
            flag[num[left]]--;
            if(flag[num[left]]==0)
            k1--;
            left++;
        }
    }
    cout<<left1+1<<" "<<right1+1<<endl;
   }
}
