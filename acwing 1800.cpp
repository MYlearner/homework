#include <bits/stdc++.h>
using namespace std;
const int N=7;
int main()
{
    int n; cin>>n;
    //奶牛的名字和累计产奶量
    unordered_map<string, int> m;
    for(int i=0; i<n; i++)
    {
        string s; int x;
        cin>>s>>x;
        m[s]+=x;
    }
    vector<pair<int, string>> v;
    for(pair<string, int> i: m)
        v.push_back({i.second, i.first});
    sort(v.begin(), v.end());
    int it=0;
    //当所有奶牛都产奶时才移动指针
    if(v.size()==N)
        while(it<v.size() && v[it].first==v[0].first)
            it++;//统计产奶量最少的奶牛的数量
    if(it<v.size() && (v.size()==1 || v[it].first!=v[it+1].first))
        cout<<v[it].second;
    else cout<<"Tie";
    return 0;
}


