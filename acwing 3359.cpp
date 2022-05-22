#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;

int n;
int a;
int odd,even;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>a;
      if(a&1) odd++;//求出初始时的奇数组数量
      else even++;//求出初始时的偶数组数量
    }

    int res;
    while(even<odd) even++,odd-=2;//每次奇数组-2，偶数组+1

    if(even==odd) res=even+odd;//如果奇数组最后数量和偶数组相同，那么最终的组数就是偶数组+奇数组
    else res=odd*2+1;//否则就是奇数组的数量小于偶数组的数量，那么最终除了每个偶数组和奇数组对应上，还会在
    //末尾形成一个偶数组，即类似于   偶，奇，偶，奇，偶    这样的排列
    cout<<res;
    return 0;
}

