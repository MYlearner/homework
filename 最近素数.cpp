#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int re[1002];
	int num[1001];
	num[2]=0;
	num[3]=0;
	for(int i=0;i<N;++i)
	{
		cin>>re[i];
	}
	for(int i=2;i<1001;++i)
	{
		if(num[i]!=1){
		
		for(int j=2*i;j<1001;j+=i)
		{
			num[j]=1;
		}
	}
	}
for(int s=0;s<N;++s)
	{
		if(num[re[s]]==0)
	{
			cout<<re[s]<<endl;}
		else
		{
		int p=re[s]-1;
		int q=re[s]+1;
		while(num[p]==1)
		{
			--p;
		}
		while(num[q]==1)
		{
			++q;
		}
		if((re[s]-p)>(q-re[s]))
		{
			cout<<q<<endl;
		}
		else if((re[s]-p)<=(q-re[s]))
		{
			cout<<p<<endl;
		}
	}

	}
	return 0;
}
