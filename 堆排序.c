//������:����ѡ�����򣬽��������¼���������Ķ���������һ�����������ѣ��ڶ�����������
//�ڶ�����������
void HeapAdjust(int a[],int s,int n)
{
	//����ΪС���ѣ���С����
	int rc=a[s];
	for(int j=2*s;j<=n;j*=2)
	{
		if(j<n && a[j]>a[j+1])//�ж�����������С
			j++;
		if(rc<=a[j])
			break;
		a[s]=a[j];
		s=j;
	}
	a[s]=rc;
}
//��һ����������
void CreatHeap(int a[],int n)
{
	//С����
	for(int i=n/2;i>0;i--)
		HeapAdjust(a,i,n);
}
//����
void HeapSort(int a[],int n)
{
	CreatHeap(a,n);//��һ������������
	for(int i=n;i>1;i--)
	{
		int x=a[1];//�Ѷ������һ��Ԫ�ػ���
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
	for(int j=1;j<n;j++)//ע�⣺�����Ǵ�1��ʼ��
		cin>>a[j];
	HeapSort(a,n);
	for(int i=1;i<n;i++)
		cout<<a[i];
	delete []a;
}
