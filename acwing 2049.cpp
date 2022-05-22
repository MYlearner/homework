#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e4 + 10;
int a[6][N];

bool cmp(int i, int j) {
    int c = 0;
    for (int k = 1; k <= 5; k ++)
        c += a[k][i] < a[k][j];
    return c > 2;
}

int main() {
    int n; cin >> n;
    for (int k = 1; k <= 5; k ++)
        for (int i = 1; i <= n; i ++) {
            int x; cin >> x;
            a[k][x] = i;
            a[0][i] = x;
        }

    sort(a[0] + 1, a[0] + n + 1, cmp);

    for (int i = 1; i <= n; i ++)
        cout << a[0][i] << '\n';

    return 0;
}

