#include <bits/stdc++.h>
using namespace std;
int n, k, c[100010];
int check(int x) { //求h是否成立 
    int ans = 0;
    for (int i = 1;i <= n; i++) if (c[i] >= x) ans++;
    return ans >= x;
}
int main() {
    scanf("%d%d", &n, &k);
    int l = 100010, r = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]), l = min(l, c[i]), r = max(r, c[i]);
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (!check(mid)) r = mid - 1;
        else l = mid;
    }
    sort(c + 1, c + 1 + n);
    for (int i = n;i > 0; i--) {
        if (k == 0) break;
        if (c[i] <= l) c[i]++, k--; 
    }
    l = 0, r = 100000;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (!check(mid)) r = mid - 1;
        else l = mid;
    }
    printf("%d", l);
    return 0
}
