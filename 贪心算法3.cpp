#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
	int s[10] = {2,3,4,5,6,7,8,9,10,11};
	int f[10] = {3,5,7,6,9,8,12,10,13,15};
	int TotalLength = (3-2);                 
 
	for(int i=1,int j=0; i<10 ; ++i)
	{
		if(s[i] >= f[j])
		{
			TotalLength += (f[i]-s[i]);
			j = i;
		}
		else
		{
			if(f[i] <= f[j])
				continue;
			else
			{
				TotalLength += f[i] - f[j];
				j = i;
			}
		}
	}
 
	cout<<TotalLength<<endl;
	system("pause");
	return 0;
}
