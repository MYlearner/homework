#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num[3];
    cin>>num[0]>>num[1]>>num[2];
    sort(num,num+3);
    int max1=0,min1=0;
    if(num[2]-num[1]==1&&num[1]-num[0]==1)
    {
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }
    if(num[2]-num[1]==2||num[1]-num[0]==2)
    {
        min1=1;
        max1=max(num[2]-num[1],num[1]-num[0])-1;
    }
    else if(num[2]-num[1]==1||num[1]-num[0]==1)
    {
        min1=2;
        max1=max(num[2]-num[1],num[1]-num[0])-1;
    }
    else
    {
        min1=2;
        max1=max(num[2]-num[1],num[1]-num[0])-1;
    }
    cout<<min1<<endl;
    cout<<max1<<endl;
    return 0;
}
