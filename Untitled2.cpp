#include<iostream>
#include<math.h>
using namespace std;
int main()
{


int N;
cin>>N;
int num[10000];
for(int i=1;i<N+1;++i)
cin>>num[i];//µÚ1£¬2£¬3£¬4£¬5 
int re[N+1];//µÚ1£¬2£¬34£¬5 
re[0]=0;
re[1]=num[1];
re[2]=num[1]+num[2];
for(int i=3;i<N+1;++i)
{
	re[i]=min(re[i-1]+num[i],re[i-2]+num[i-1]+num[i-2]);
}
cout<<re[N]<<endl;


return 0;
}
