#include <iostream>
using namespace std;
 
void GreedyChoose(int len,int *s,int *f,bool *flag);
 
int main(int argc, char* argv[])
{
	int s[11] ={1,3,0,5,3,5,6,8,8,2,12};
	int f[11] ={4,5,6,7,8,9,10,11,12,13,14};
 
	bool mark[11] = {0};
 
	GreedyChoose(11,s,f,mark);
	for(int i=0;i<11;i++)
		if(mark[i])
			cout<<i<<" ";
	system("pause");
	return 0;
}
 
void GreedyChoose(int len,int *s,int *f,bool *flag)
{
	flag[0] = true;
	int j = 0;
	for(int i=1;i<len;++i)
		if(s[i] >= f[j])
		{
			flag[i] = true;
			j = i;
		}
}
