#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	
string s;
cin>>s;
 
 
if(s.size()==1)
{
	cout<<"Bob "<<(s[0]-'a')+1<<endl;
	continue ;
}
else if(s.size()==2)
{
	int a1=(s[0]-'a')+(s[1]-'a')+2;
	cout<<"Alice "<<a1<<endl;
	continue ;
}
else
{
	if(s.size()%2==0)
	{
		int sum=0;
		for(int i=0;i<s.size();++i)
		{
			sum+=(s[i]-'a'+1);
		}
		cout<<"Alice "<<sum<<endl;
		continue ;
	}
	else
	{
		int sum=0;
		for(int i=1;i<s.size()-1;++i)
		{
			sum+=(s[i]-'a'+1);
		}
		int a1=s[0]-'a'+1;
		int a2=s[s.size()-1]-'a'+1;
		sum+=(a1>a2?a1:a2);
		int a3=sum-(a1<a2?a1:a2);
		cout<<"Alice "<<a3<<endl;
		continue ;
	}
}
}
	return 0;
}
