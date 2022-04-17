#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int cnt[11];     //记录id为1-10的奶牛每次在哪边

int main()
{
    int n;
    cin>>n;
    int res=0;                        //记录答案
    memset(cnt,-1,sizeof cnt);        //初始化为-1，如果cnt[id]==-1则表示第一次出现，无须考虑要不要加1
    for(int i=1;i<=n;i++)
    {
        int id,x;
        cin>>id>>x;
        if(cnt[id]==-1)
        {
            cnt[id]=x;
        }
        else
            if(cnt[id]!=x)             //表示当前cnt[id]的值与现在不一样，所以过了马路，答案+1
            {
                res++; 
                cnt[id]=x;         //更新当前奶牛所在位置
            }
    }
    cout<<res<<endl;
    return 0;
}

