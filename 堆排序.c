//堆排序:树形选择排序，将带排序记录看成完整的二叉树，第一步：建立初堆，第二步：调整堆
//第二步：调整堆
void HeapAdjust(int a[],int s,int n)
{
	//调整为小根堆，从小到大
	int rc=a[s];
	for(int j=2*s;j<=n;j*=2)
	{
		if(j<n && a[j]>a[j+1])//判断左右子数大小
			j++;
		if(rc<=a[j])
			break;
		a[s]=a[j];
		s=j;
	}
	a[s]=rc;
}
//第一步：建初堆
void CreatHeap(int a[],int n)
{
	//小根堆
	for(int i=n/2;i>0;i--)
		HeapAdjust(a,i,n);
}
//整合
void HeapSort(int a[],int n)
{
	CreatHeap(a,n);//第一步，建立初堆
	for(int i=n;i>1;i--)
	{
		int x=a[1];//堆顶与最后一个元素互换
		a[1]=a[i];
		a[i]=x;
		HeapAdjust(a,1,i-1);
	}
 
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n+1];
	for(int j=1;j<n;j++)//注意：这里是从1开始的
		cin>>a[j];
	HeapSort(a,n);
	for(int i=1;i<n;i++)
		cout<<a[i];
	delete []a;
}
