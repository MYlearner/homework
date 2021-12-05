#include<iostream>
#include<algorithm>
using namespace std;
struct mooncake{
	double store;
	double sell;
	double price;
}cake[1010];
bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
} 
int main(){
	int n;
	double D;
	scanf("%d%lf",&n,&D);
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].store);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].sell);
		cake[i].price=cake[i].sell/cake[i].store;
	}
	sort(cake,cake+n,cmp);
	double ans=0;
	for(int i=0;i<n;i++){
		if(cake[i].store<=D){
			D-=cake[i].store;
			ans+=cake[i].sell;
		}else{
			ans+=cake[i].price*D;
			break;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}

```

#include <iostream>
using namespace std;
const int maxn=100010;
int school[maxn]={0};
int main(){
	int n,schID,score;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&schID,&score);
		school[schID]+=score;
	}
	int k=1,MAX=-1;
	for(int i=1;i<=n;i++){
		if(school[i]>MAX){
			MAX=school[i];
			k=i; 
		}
	}
	printf("%d %d\n",k,MAX);
	return 0; 
} 

