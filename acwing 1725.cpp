 #include <bits/stdc++.h>
using namespace std;
const int N=5;
string s[N];
set<set<char>> w[N];

void insert(vector<pair<int, int>> c)
{
    set<char> con;
    for(auto it: c)
        con.insert(s[it.first][it.second]);
    //��������ţ
    w[con.size()].insert(con);
}

int main()
{
    for(int i=0; i<3; i++) cin>>s[i];
    //��
    for(int i=0; i<3; i++)
        insert({{i, 0}, {i, 1}, {i, 2}});
    //��
    for(int i=0; i<3; i++)
        insert({{0, i}, {1, i}, {2, i}});
    //�����Խ���
    insert({{0, 0}, {1, 1}, {2, 2}});
    insert({{2, 0}, {1, 1}, {0, 2}});

    cout<<w[1].size()<<endl<<w[2].size();
    return 0;
}
 
