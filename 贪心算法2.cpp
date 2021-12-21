#include <iostream>
using namespace std;
 
struct Node
{
	float weight;
	float value;
	bool mark;
	char char_mark;
	float pre_weight_value;
};
 
int main(int argc, char* argv[])
{
	float Weight[7] = {35,30,60,50,40,15,20};
	float Value [7] = {10,40,30,50,35,40,30};
	Node array[7];
	for(int i=0; i<7; i++)
	{
		array[i].value = Value[i];
		array[i].weight = Weight[i];
		array[i].char_mark = 65 + i;
		array[i].mark = false;
		array[i].pre_weight_value = Value[i] / Weight[i];
	}
	
	for(i=0;i<7;i++)
		cout<<array[i].pre_weight_value<<" ";
	cout<<endl;
	
	float weight_all=0.0;
	float value_all = 0.0;
	float max = 0.0;
	char charArray[7];
	int flag,n = 0;
	
	while(weight_all <= 150)
	{
		for(int index=0;index < 7; ++index)
		{
			if(array[index].pre_weight_value > max && array[index].mark == false)
			{
				max = array[index].pre_weight_value ;
				flag = index;
			}
		}
		
		charArray[n++] = array[flag].char_mark;
		array[flag].mark = true;
		weight_all += array[flag].weight;
		value_all += array[flag].value;
		max = 0.0;
	}
	
	for(i=0;i<n-1;i++)
		cout<<charArray[i]<<" ";
	cout<<endl;
	cout<<"weight_all:"<<weight_all- array[n-1].weight<<endl;
	cout<<"value_all:"<<value_all<<endl;

	system("pause");
	return 0;
}
