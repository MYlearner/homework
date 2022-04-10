#include<iostream>
using namespace std;

const int N=100005;
int n,m,ans;
int a[N];
char s[N];


bool check(int x) {
    int p=1-x,cnt=0;//cnt��һ�������2��С��2���������������ڵ���2���������� 
    for(int i=1; i<=m; i++) {
        while(p+x+x<=a[i]) p+=x,cnt++;//�������������p�������ƶ�x�ľ��룬ţ��ͷ���ͼ�һͷ 
        p=a[i];//��p=a[i],p����ǰһͷţ��λ�� 
    }
    while(p+x<=n) p+=x,cnt++; //��Ϊ���ڲ���λ��û�������һ��λ��n�������������Ҫ���������ţ��ֱ���ӵ����ܼ�λ�� 
    return cnt>=2;//��������ţ���������ڵ���2��֤�����ǵķ����ǿ��еģ���x��һ�ִ� 
}

int main() {
    cin>>n;
    cin>>s+1;
    for(int i=1; i<=n; i++)
        if(s[i]=='1') a[++m]=i;
    int l=1,r=n;
    for(int i=1; i<m; i++) r=min(r,a[i+1]-a[i]);
    while(l<=r) {
        int mid=l+r>>1;
        if(check(mid)) {
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    cout<<ans;
    return 0;
}
 
