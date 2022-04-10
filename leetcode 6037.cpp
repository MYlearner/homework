class Solution {
public:
    int largestInteger(int num) {
        vector<bool>flag;//记录该位置是奇数还是偶数
        vector<int>ji;//将奇数加进来
        vector<int>ou;//将偶数加进来
        if(num<10)
        return num;
        int sum=0;
        while(num)
        {
            int a=num%10;
            if(a%2==0)
            { 
            flag.push_back(1);
            ou.push_back(a);
        }
        else
        { 
        ji.push_back(a);
        flag.push_back(0);
        }
        num/=10;
        }
//奇数偶数各自排序后对应位置输出
         sort(ji.begin(),ji.end());
         sort(ou.begin(),ou.end());
reverse(ji.begin(),ji.end());
reverse(ou.begin(),ou.end());
reverse(flag.begin(),flag.end());
        int a1=0,b1=0;
        for(int i=0;i<flag.size();++i)
        {
            if(flag[i]==1)
sum=(sum*10+ou[a1++]);
else
sum=(sum*10+ji[b1++]);

        }
   return sum; }
};
