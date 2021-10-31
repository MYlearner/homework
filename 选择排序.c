//希尔排序：去增量为d1的分为一组，共分成d1组分别进行插入排序，然后每组对应元素放在一起，然后取d2...知道d=1
void ShellSort(int a[],int n)
{
	int dk;
	int tmp;
	for(dk=n/2;dk>0;dk/=2)
		for(int i=dk;i<n;i++)
		{
			tmp=a[i];
			for(int j=i;j>=dk;j-=dk)
				if(tmp<a[j-dk])
					a[j]=a[j-dk];
				else break;
			a[j]=tmp;
		}
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int j=0;j<n;j++)
		cin>>a[j];
	ShellSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i];
	delete []a;
}
