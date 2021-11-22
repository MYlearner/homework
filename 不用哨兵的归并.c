 int merge(int *datas,int p,int q,int r)
 {
     int n1 = q-p+1;
     int n2 = r-q;
     int *left = (int*)malloc(sizeof(int)*(n1+1));
     int *right = (int*)malloc(sizeof(int)*(n2+1));
     int i,j,k;
     memcpy(left,datas+p,n1*sizeof(int));
     memcpy(right,datas+q+1,n2*sizeof(int));
     i = 0;
     j = 0;
     for(k=p;k<=r;++k)
     {
         if(i <n1 && j< n2)  //归并两个子数组
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
         else
          break;
     }
     //将剩下的合并到数组中
     while(i != n1)
         datas[k++] = left[i++];
     while(j != n2)
         datas[k++] = right[j++];
     free(left);
     free(right);
 }
