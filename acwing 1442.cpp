#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
string word;

int main()
{
    cin>>n>>k;
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>word;
        if(word.length() + num > k)
        {
            cout<<endl<<word;
            num = word.length();
        }
        else
        {
            num += word.length();
            if(i != 0)
                cout<<" ";
            cout<<word;
        }
}
return 0;
}
