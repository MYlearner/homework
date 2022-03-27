#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    string s1;
    map<char,int>re;
    cin>>s1;
    int size1=s1.size();
    for(int i=0;i<size1;++i)
    re[s1[i]]=i;
    string s2;
    cin>>s2;
    int a1=0;
    int size2=s2.size();
    for(int i=0;i<size2;++i)
    {
        if(re[s2[i]]<=re[s2[i-1]])
        a1++;
    }
    cout<<++a1;
    return 0;
}
