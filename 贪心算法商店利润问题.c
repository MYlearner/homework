#include <stdio.h>
#include <stdlib.h>
struct edge{
	int profit;
	int time;
}e[100],S;
int f[100];
int getf(int u)
{
	if(f[u]==-1)return u;
	else {
		f[u]=getf(f[u]);
		return f[u];
	}
}

int main()
{
	int i,j,N,k;
	int sum=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		f[i]=i;
	memset(f,-1,sizeof(f));
	for(i=0;i<N;i++)
		scanf("%d %d",&e[i].profit,&e[i].time);
	for(i=0;i<N-1;i++)
		for(j=i+1;j<N;j++)
			if(e[i].profit<e[j].profit)
			{
				S=e[i];
				e[i]=e[j];
				e[j]=S;
			}
	for(i=0;i<N;i++)
	{
		k=getf(e[i].time);
		if(k>=1){
			sum+=e[i].profit;
			f[k]=k-1;
		}
		
	}
	printf("%d",sum);
	return 0;
}

