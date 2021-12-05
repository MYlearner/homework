#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Inteval{
	int x,y;
}I[maxn];
bool cmp(Inteval a,Inteval b){
	if(a.x!=b.x) return a.x>b.x;
	else return a.y<b.y;
}
int main(){
	int n;
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++){
			scanf("%d%d",&I[i].x,&I[i].y);
		}
		sort(I,I+n,cmp);
		int ans=1,lastX=I[0].x;
		for(int i=1;i<n;i++){
			if(I[i].y<=lastX){
				lastX=I[i].x;
				ans++; 
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

