//�������� 
//��һ������Ҫ�ŵ����飬�ڶ���������һ���������������������Ա����
void kuaipai(int array[],int low,int hight)
{
	int i,j,t,m;
	if(low<hight)
	{
		i=low;
		j=hight;
		t=array[low];//��һ����Ϊ��
		while(i<j)
		{
			while(i<j && array[j]>t)//���ұ��ҳ�С�������
				j--;
			if(i<j)//��С�������array[j]�ŵ����array[i]��λ��
			{
				m=array[i];
				array[i]=array[j];
				array[j]=m;
				i++;
			}
			while(i<j && array[i]<=t)//������ҳ����������
				i++;
			if(i<j)//�����������array[i]�����ұ�array[j]��λ��
			{
				m=array[j];
				array[j]=array[i];
				array[i]=m;
				j--;
			}	
		}
		
		array[i]=t;//������м�,���ھ������������˷ֱ���[0 i-1]��[i+1 hight],�ֱ����
		kuaipai(array,0,i-1);
		kuaipai(array,i+1,hight);
	}
}
void PX_kuaipai(int buf[],int size)
{
	kuaipai(buf,0,size-1);
}
void main()
{
	while(1)
	{
		int m,i;
		cin>>m;
		int *buf=new int[m];
		for(i=0;i<m;i++)
			cin>>buf[i];
		PX_kuaipai(buf,m);
		for(i=0;i<m;i++)
			cout<<buf[i];
		cout<<'\n';
		delete []buf;
	}
	
}
