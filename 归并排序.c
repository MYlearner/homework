//采用哨兵实现merge
 #define MAXLIMIT    65535
 void merge(int *datas,int p,int q,int r)
 {
     int n1 = q-p+1;  //第一个有序子数组元素个数
     int n2 = r-q;      //第二个有序子数组元素个数
     int *left = (int*)malloc(sizeof(int)*(n1+1));
     int *right = (int*)malloc(sizeof(int)*(n2+1));
     int i,j,k;
     //将子数组复制到临时辅助空间
     for(i=0;i<n1;++i)
         left[i] = datas[p+i];
     for(j=0;j<n2;++j)
         right[j] = datas[q+j+1];
     //添加哨兵
     left[n1] = MAXLIMIT;
     right[n2] = MAXLIMIT;
     //从第一个元素开始合并
     i = 0;
     j = 0;
     //开始合并
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
