class Solution {
public:
    int largestInteger(int num) {
        vector<bool>flag;//��¼��λ������������ż��
        vector<int>ji;//�������ӽ���
        vector<int>ou;//��ż���ӽ���
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
//����ż������������Ӧλ�����
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
