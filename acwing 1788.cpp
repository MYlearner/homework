#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int cnt[11];     //��¼idΪ1-10����ţÿ�����ı�

int main()
{
    int n;
    cin>>n;
    int res=0;                        //��¼��
    memset(cnt,-1,sizeof cnt);        //��ʼ��Ϊ-1�����cnt[id]==-1���ʾ��һ�γ��֣����뿼��Ҫ��Ҫ��1
    for(int i=1;i<=n;i++)
    {
        int id,x;
        cin>>id>>x;
        if(cnt[id]==-1)
        {
            cnt[id]=x;
        }
        else
            if(cnt[id]!=x)             //��ʾ��ǰcnt[id]��ֵ�����ڲ�һ�������Թ�����·����+1
            {
                res++; 
                cnt[id]=x;         //���µ�ǰ��ţ����λ��
            }
    }
    cout<<res<<endl;
    return 0;
}

