#include<iostream>
using namespace std;
int main()
{
    int n,x; cin>>n>>x;
    int a[6][3]={{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
    cout<<a[n%6][x];
}
