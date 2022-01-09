#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
const int N = 1010;
int g[N][N];
int dist[N][N]; // 距离
bool st[N][N];
typedef pair<int, int> PII;
int n, x, y, xx, yy; // xx,yy是地图的边界
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}; // 上下左右
void bfs(int x, int y)
{
    // memset(dist, -1,  sizeof dist);
    deque<PII> q;
    q.push_front({x, y});
    st[x][y] = 1;
    dist[x][y] = 0;
    while (q.size())
    {
        // cout << "=\n";
        PII t = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a > xx || b < 0 || b > yy) continue;
            if(st[a][b]) continue;
            if(g[a][b] == 1)
            {
                dist[a][b] = dist[t.first][t.second] + 1;
                q.push_back({a,b});
            }
            else
            {
                dist[a][b] = dist[t.first][t.second];
                q.push_front({a, b});
            }
            st[a][b] = 1;
        }
    }
}

int main()
{
    cin >> n >> x >> y;
    xx = x + 1, yy = y + 1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = 1; // 有草堆为1，无为0
        xx = max(xx, a + 1), yy = max(yy, b + 1);
    }

    bfs(x, y);

    cout << dist[0][0];
}
