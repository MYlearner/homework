#include <bits/stdc++.h>

//#define int long long
#define help {cin.tie(NULL); cout.tie(NULL);}
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N=3e5+5,mod=998244353;
int n,m,t,x,y,color[N],f[N],cnt1,cnt2;
vector<int> adj[N];
bool dfs(int x,int c)
{
    color[x]=c;
    if(c==1)cnt1++;
    else
        cnt2++;
    for(int y:adj[x])
        if(!color[y])
        {
            if(!dfs(y,3-c))return false;
        }
        else if(color[y]==c)return false;
    return true;
}
int main()
{
    help;
    f[0]=1;
    for(int i=1;i<N;i++)f[i]=1ll*2*f[i-1]%mod;
    for(cin>>t;t;t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)adj[i].clear(),color[i]=0;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            adj[x].pb(y),adj[y].pb(x);
        }
        int res=1;
        for(int i=1;i<=n;i++)
            if(!color[i])
            {
                cnt1=cnt2=0;
                if(!dfs(i,1))
                {
                    res=0;
                    break;
                }
                res=1ll*res*(f[cnt1]+f[cnt2])%mod;
            }
        cout<<res<<'\n';
    }
    return 0;
}

