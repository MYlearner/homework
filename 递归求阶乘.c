#include<iostream>
using namespace std;
int F(int n){
	if(n==0) return 1; //�ݹ�߽�
	else return F(n-1)*n;
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",F(n));
	return 0;
}
