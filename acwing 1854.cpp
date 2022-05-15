#include<iostream>
using namespace std;
int b[4], a[4];//before after
int main()
{
    for(int i=0; i<4; i++) cin>>b[i]>>a[i];
    cout<<a[1]+a[2]+a[3]-b[1]-b[2]-b[3]<<endl;
    cout<<a[2]+a[3]-b[2]-b[3]<<endl;
    cout<<a[3]-b[3]<<endl;
    return 0;
}
