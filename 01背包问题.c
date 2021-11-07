#include<stdio.h>
int v[]={6,3,5,4,6};
int w[]={2,2,6,5,4};
int dp[100][100];
 
int Max(int a,int b){
	if(a>=b){
		return a;
	}else{
		return b;
	}
}
 
int getAns(int i,int wi){
	
	for(int x=0;x<=i;x++){
		dp[x][0]=0;
	}
	for(int x=0;x<=wi;x++){
		dp[0][x]=0;
	}
	
	for(int x=1;x<=i;x++){
		for(int y=1;y<=wi;y++){
			if(y>=w[x-1]){
				dp[x][y]=Max(dp[x-1][y],v[x-1]+dp[x-1][y-w[x-1]]);
			}else{
				dp[x][y]=dp[x-1][y];
			}
			printf("%4d",dp[x][y]);
		}
		printf("\n");
	}
	return dp[i][wi];
}
 
 
int main(){
	int max=getAns(5,10);
	printf("%d\n",max);
	return 0;
} 

