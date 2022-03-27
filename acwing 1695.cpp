#include<iostream>
using namespace std;
int main()
{
    int num[4]={0,1,2,3};
    int re[4]={0};
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        swap(num[a],num[b]);
        re[num[c]]++;
    }
    cout<<max(re[1],max(re[2],re[3]))<<endl;


    return 0;
}

