void insert_sort(int *datas,int length)
 {
     int i,j;
     int key,tmp;
     //判断参数是否合法
     if(NULL == datas || 0==length)
     {
         printf("Check datas or length.\n");
         exit(1);
     }
     //数组下标是从0开始的，从第二个元素（对应下标1）开始向前插入
     for(j=1;j<length;j++)
     {
         key = datas[j];  //记录当前要插入的元素
         i = j-1;  //前面已经有序的元素
       //寻找待插入元素的位置，从小到到排序，如果是从大到小改为datas[i]<key
         while(i>=0 && datas[i] > key)
         {
             /×tmp = datas[i+1];
             datas[i+1] = datas[i];
             datas[i] = tmp;*/这个过程不需要进行交换，因为要插入的值保存在key中，没有被覆盖掉
             datas[i+1] = datas[i];
             i--;   //向前移动
         }
         datas[i+1] = key;  //最终确定待插入元素的位置
   }
}
