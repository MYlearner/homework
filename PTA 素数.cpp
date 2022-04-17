#include<bits/stdc++.h> 
using namespace std;
bool num[1010];
bool check(int a1)
{
	for(int i=2;i*i<=a1;++i)
	{
		if(a1%i==0)
		return false;
	}
	return true;
}
int main()
{
	vector<int>ve;
ios::sync_with_stdio(false);
cin.tie(0);
int m,n;
int sum=0;
cin>>m>>n;
for(int i=2;i<n+10;++i)
num[i]=1;
num[0]=0;
num[1]=0;
for(int i=2;i<n+1;++i)
{
if(num[i]==1)
{
for(int j=i*i;j<n+1;j+=i)
num[j]=0;
}
}
for(int i=m;i<n+1;++i)
{
	if(num[i]==1)
	ve.push_back(i);
}
int size=ve.size();
for(int i=0;i<size-2;++i)
{

for(int j=i+1;j<size-1;++j)
for(int k=j+1;k<size;++k)
{
	
	int a1=ve[i]*ve[j]+ve[k];
	int a2=ve[j]*ve[k]+ve[i];
	int a3=ve[k]*ve[i]+ve[j];
	bool a11=(a1<=n?num[a1]:check(a1));
	if(a11==1)
{
	bool a12=(a2<=n?num[a2]:check(a2));
	if(a12==1)
	{
		bool a13=(a3<=n?num[a3]:check(a3));
		if(a13==1)
		sum++;
	}
}
	
}
}

cout<<sum<<endl;
return 0; 
} 
