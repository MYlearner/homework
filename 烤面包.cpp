#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int count=0;
    if(n*2<k)
    {
        cout<<1<<endl;
        return 0;
    }
    else
    {if((n*2)%k==0)
    count=(n*2)/k;
    else 
    count=(n*2)/k+1;
    cout<<count<<endl;
    }
    return 0;
}
