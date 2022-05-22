#include <iostream>

#define x first
#define y second

using namespace std;
using PII = pair<int, int>;

const int N = 20;
int n, ans;
int path[N];
PII cow[N];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int get_d(int a, int b) {
    auto [ax, ay] = cow[path[a]];
    auto [bx, by] = cow[path[b]];
    int d = -1;
    for (int k = 0; k < 4; k ++)
        if (ax + abs(ax - bx) * dx[k] == bx &&
            ay + abs(ay - by) * dy[k] == by) {
            d = k;
            break;
        }
    return d;
}

bool check() {
    // 1. ����·�� (0, 0) -> path[1, n] -> (0, 0)
    // 2. ÿͷ��ţ��λ�ô�ǡ��ת��һ��
    for (int i = 1, lastd = -1; i <= n + 1; i ++) {
        int d = get_d(i - 1, i);
        if (d == -1 || d == lastd) return 0;
        lastd = d;
    }
    return 1;

}

void dfs(int u, int s) {
    if (u > n) {
        if (check()) ans ++;
        return;
    }

    for (int i = 1; i <= n; i ++) {
        if (s >> i & 1) continue;
        path[u] = i;
        dfs(u + 1, s | 1 << i);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> cow[i].x >> cow[i].y;

    dfs(1, 0);

    cout << ans << endl;

    return 0;
}
