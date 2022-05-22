#include <bits/stdc++.h>
using namespace std;
using T = pair<int, int>;

int n;
vector<T> cows;
map<int, bool> cx, cy;

bool dfs (int cur, int use)
{
    if (use > 3) return false;
    if (cur == n) return true;

    int x = cows[cur].first, y = cows[cur].second;
    if (cx[x] || cy[y]) return dfs(cur + 1, use); // 如果已经被覆盖，就不需要加线了

    bool can = 0;
    if (!cx[x]) cx[x] = true, can |= dfs(cur + 1, use + 1), cx[x] = false;
    if (!cy[y]) cy[y] = true, can |= dfs(cur + 1, use + 1), cy[y] = false;
    return can;
}

int main ()
{
    cin >> n;
    for (int i = 1, x, y; i <= n && cin >> x >> y; i ++ ) cows.push_back({x, y});
    cout << dfs (0, 0) << endl;
    return 0;
}
