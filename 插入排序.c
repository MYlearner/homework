void insert_sort(int *datas,int length)
 {
     int i,j;
     int key,tmp;
     //�жϲ����Ƿ�Ϸ�
     if(NULL == datas || 0==length)
     {
         printf("Check datas or length.\n");
         exit(1);
     }
     //�����±��Ǵ�0��ʼ�ģ��ӵڶ���Ԫ�أ���Ӧ�±�1����ʼ��ǰ����
     for(j=1;j<length;j++)
     {
         key = datas[j];  //��¼��ǰҪ�����Ԫ��
         i = j-1;  //ǰ���Ѿ������Ԫ��
       //Ѱ�Ҵ�����Ԫ�ص�λ�ã���С������������ǴӴ�С��Ϊdatas[i]<key
         while(i>=0 && datas[i] > key)
         {
             /��tmp = datas[i+1];
             datas[i+1] = datas[i];
             datas[i] = tmp;*/������̲���Ҫ���н�������ΪҪ�����ֵ������key�У�û�б����ǵ�
             datas[i+1] = datas[i];
             i--;   //��ǰ�ƶ�
         }
         datas[i+1] = key;  //����ȷ��������Ԫ�ص�λ��
   }
}
