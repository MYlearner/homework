#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    //找出覆盖两个牧场的最小矩形坐标
    int sx1=min(x1, x3), sy1=min(y1, y3), sx2=max(x2, x4), sy2=max(y2, y4);
    //矩形边长的最大值
    int s=max(sx2-sx1, sy2-sy1);
    cout<<s*s;
    return 0;
}
 
