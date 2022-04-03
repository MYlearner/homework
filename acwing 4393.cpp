#include<bits/stdc++.h>
using namespace std;
int main()
{
    int sum=0;
    string s;
    int num[5];
    for(int i=1;i<5;++i)
    cin>>num[i];
    cin>>s;
    for(int i=0;i<s.size();++i)
    sum+=num[s[i]-'0'];
    cout<<sum<<endl;
}
