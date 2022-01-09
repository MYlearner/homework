#include<iostream>
#include<string>
using namespace std;

int turn(string c)
{
    int sum=0;
    for(int i=0;i<c.length();++i)
    {
        sum=sum*2+(c[i]-'0');
    }
    return sum;
}

int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();++i)
    {
        int ans=0;
        int len=b.length()-1;
        int count =0;
        char c=a[i];
        a[i]=(char)('1'-a[i]+'0');
        ans=turn(a);
        int num1=ans;
        while(ans!=0)
        {
        int d=ans%3;
        if(d!=(b[len--]-'0'))
        {
            count++;
        }
        ans=ans/3;
        }
        if(count==1&&len<0){
        cout<<num1;
        return 0;
        }
        else
        a[i]=c;
    }
}
