#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,x3,y1,y2,y3;
    char map[10][10];
    for(int i=0;i<10;++i)
     for(int j=0;j<10;++j)
     {cin>>map[i][j];
     if(map[i][j]=='B')
     {
         x1=i;
         y1=j;
     }
     else if(map[i][j]=='R')
     {
         x2=i;
         y2=j;
     }
    else  if(map[i][j]=='L')
     {
         x3=i;
         y3=j;
     }
     }
     int count=0;
     if(x1==x2&&x2==x3)
     {
         if((y1>y2&&y2>y3)||(y1<y2&&y2<y3))
         {
             count=abs(y3-y1)+1;
         }
         else 
         count=abs(y3-y1)-1;
     }
     else  if(y1==y2&&y2==y3)
     {
         if((x1>x2&&x2>x3)||(x1<x2&&x2<x3))
         {
             count=abs(x3-x1)+1;
         }
         else 
         count=abs(x3-x1)-1;
     }
    else 
     {
        count=abs(y3-y1)+abs(x3-x1)-1;
     }
     cout<<count <<endl;
}
