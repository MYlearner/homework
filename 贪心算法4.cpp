#include <iostream>
using namespace std;
 
int main(int argc, char* argv[])
{
	int array[10];
	for(int i=0;i<10;i++)
		cin>>array[i];
 
	int temp;
	for(i=0; i<=9 ; ++i)
		for(int j=0;j<10-1-i;j++)
			if(array[j] > array[j+1] )
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	for(i=0;i<10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
