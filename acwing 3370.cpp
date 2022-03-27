#include<bits/stdc++.h>
using namespace std;
long long n,i,j,x;
string a,b,c,d;
string an[13]={"Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig","Rat"};//初始化
map<string,long long> year;
int main()
{
    year["Bessie"]=0;//初始化，本蒟蒻后期会测试别的数可不可以
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>b>>b>>c>>d>>d>>d;//读掉一些不需要的东西
        if(b=="previous")
        {
            for(j=year[d]-1;;j--)   if(an[(j%12+12)%12]==c) break;//查找年份（(j%12+12)%12是怕有负数，特判，有必要理解一下）
            year[a]=j;
        }
        else
        {
            for(j=year[d]+1;;j++)   if(an[(j%12+12)%12]==c) break;//查找年份（(j%12+12)%12是怕有负数，特判，有必要理解一下）
            year[a]=j;
        }
    }
    cout<<abs(year["Elsie"]);
    return 0;
}

