//ϣ������ȥ����Ϊd1�ķ�Ϊһ�飬���ֳ�d1��ֱ���в�������Ȼ��ÿ���ӦԪ�ط���һ��Ȼ��ȡd2...֪��d=1
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
