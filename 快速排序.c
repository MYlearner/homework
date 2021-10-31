//快速排序 
//第一个参数要排的数组，第二个参数第一个数，第三个参数数组成员个数
void kuaipai(int array[],int low,int hight)
{
	int i,j,t,m;
	if(low<hight)
	{
		i=low;
		j=hight;
		t=array[low];//第一个数为轴
		while(i<j)
		{
			while(i<j && array[j]>t)//从右边找出小于轴的数
				j--;
			if(i<j)//将小于轴的数array[j]放到左边array[i]的位置
			{
				m=array[i];
				array[i]=array[j];
				array[j]=m;
				i++;
			}
			while(i<j && array[i]<=t)//从左边找出大于轴的数
				i++;
			if(i<j)//将大于轴的数array[i]放在右边array[j]的位置
			{
				m=array[j];
				array[j]=array[i];
				array[i]=m;
				j--;
			}	
		}
		
		array[i]=t;//轴放在中间,现在就有两个区域了分别是[0 i-1]和[i+1 hight],分别快排
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
