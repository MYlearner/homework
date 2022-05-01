#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);




int n,x;
cin>>n>>x;
int num[n];
int sum=0;
int x1=5-x;
for(int i=0;i<n;++i)
{
	cin>>num[i];
	if(num[i]<=x1)
	{
		sum++;
	}
 } 

cout<<sum/3<<endl;	


	return 0;
}
