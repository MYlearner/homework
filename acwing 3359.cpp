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
      if(a&1) odd++;//�����ʼʱ������������
      else even++;//�����ʼʱ��ż��������
    }

    int res;
    while(even<odd) even++,odd-=2;//ÿ��������-2��ż����+1

    if(even==odd) res=even+odd;//������������������ż������ͬ����ô���յ���������ż����+������
    else res=odd*2+1;//������������������С��ż�������������ô���ճ���ÿ��ż������������Ӧ�ϣ�������
    //ĩβ�γ�һ��ż���飬��������   ż���棬ż���棬ż    ����������
    cout<<res;
    return 0;
}

