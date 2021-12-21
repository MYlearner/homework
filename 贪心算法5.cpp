#include <iostream>
#include <cmath>
using namespace std;
 
bool compare(int Num1,int Num2);
int main(int argc, char* argv[])
{
	int N;
	cout<<"please enter the number n:"<<endl;
	cin>>N;
	int *array = new int [N];
	for(int i=0;i<N;i++)
		cin>>array[i];
	
	int temp;
	for(i=0; i<=N-1 ; ++i)
	{
		for(int j=0;j<N-i-1;j++)
			if( compare(array[j],array[j+1]) )
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	}
cout<<"the max number is:";
	for( i=N-1 ; i>=0 ; --i)
		cout<<array[i];
	cout<<endl;
	delete [] array;
	system("pause");
	return 0;
}
 
bool compare(int Num1,int Num2)
{
	int count1=0,count2=0;
	int MidNum1 = Num1,MidNum2 = Num2;
	while( MidNum1 )
	{
		++count1;
		MidNum1 /= 10;
	}
	
	while( MidNum2 )
	{
		++count2;
		MidNum2 /= 10;
	}
	
	int a = Num1 * pow(10,count2) + Num2;
	int b = Num2 * pow(10,count1) + Num1;
return (a>b)? true:false;
} 
