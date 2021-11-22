//�����ڱ�ʵ��merge
 #define MAXLIMIT    65535
 void merge(int *datas,int p,int q,int r)
 {
     int n1 = q-p+1;  //��һ������������Ԫ�ظ���
     int n2 = r-q;      //�ڶ�������������Ԫ�ظ���
     int *left = (int*)malloc(sizeof(int)*(n1+1));
     int *right = (int*)malloc(sizeof(int)*(n2+1));
     int i,j,k;
     //�������鸴�Ƶ���ʱ�����ռ�
     for(i=0;i<n1;++i)
         left[i] = datas[p+i];
     for(j=0;j<n2;++j)
         right[j] = datas[q+j+1];
     //����ڱ�
     left[n1] = MAXLIMIT;
     right[n2] = MAXLIMIT;
     //�ӵ�һ��Ԫ�ؿ�ʼ�ϲ�
     i = 0;
     j = 0;
     //��ʼ�ϲ�
     for(k=p;k<=r;k++)
     {
         if(left[i] < right[j])
         {
             datas[k] = left[i];
             i++;
         }
         else
         {
             datas[k] = right[j];
             j++;
         }
     }
     free(left);
     free(right);
 }
