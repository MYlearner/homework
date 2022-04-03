#include <iostream>
#include <cstring>
#include <algorithm> 

using namespace std;
typedef long long LL; 
template <typename T> T chMa(T &x, T y) { if (y > x) x = y; return x; } 
const int N = 2010;

LL n, m, x;
LL a[N], b[N], c[N * N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    for (int i = 1; i <= m; i++) cin >> b[i], b[i] += b[i - 1];
    cin >> x; 

    //Ԥ����һ������[tar]����ʾ�Ͳ�����tar���������󳤶�
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++) 
            chMa (c[b[j] - b[i - 1]], (LL)(j - i + 1)); 
    for (int i = 1; i < N * N; i++)
        chMa (c[i], c[i - 1]);

    LL res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            LL tar = x / (a[j] - a[i - 1]); 
            if (tar >= N * N) chMa (res, (j - i + 1) * m); //����Խ��
            else chMa (res, c[tar] * (j - i + 1));
        }
    cout << res;
}

 
