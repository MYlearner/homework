//ֱ�Ӳ������򣺽���һ�����ݿ���һ��˳��������������һ�β������
void InsertSort(int a[], int n)  
{  
    for(int i= 1; i<n; i++){  
        if(a[i] < a[i-1]){               //����i��Ԫ�ش���i-1Ԫ�أ�ֱ�Ӳ��롣С�ڵĻ����ƶ����������  
            int j= i-1;   //�������һ������
            int x = a[i];        //����Ϊ�ڱ������洢������Ԫ��  
            a[i] = a[i-1];           //�Ⱥ���һ��Ԫ�� (��Ϊa[i]����X�����Բ��¶�ʧ) 
            while(j>=0 && x < a[j]){  //�����������Ĳ���λ��  (������)
                a[j+1] = a[j];  
                j--;         //Ԫ�غ���  
            }  
            a[j+1] = x;      //���뵽��ȷλ��  
        }  
    }  
      
} 
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int j=0;j<n;j++)
		cin>>a[j];
	InsertSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i];
	delete []a;
}
