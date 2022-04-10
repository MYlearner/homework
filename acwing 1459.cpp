#include <bits/stdc++.h>
using namespace std;
int k, n, a[20], f[20][20]; 
int main() {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) scanf("%d", &a[j]);
        for (int j = 1; j < n; j++)
            for (int x = j + 1; x <= n; x++) f[a[j]][a[x]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (f[i][j] == k) ans++;
    } printf("%d\n", ans);
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) printf("%d ", f[i][j]);
    //     puts("");
    // }
    return 0;
}

