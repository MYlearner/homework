#include <bits/stdc++.h>
using namespace std;

int a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;
    int dist1 = abs(a - b);    //��һ�������ֱ�Ӵ� a �� b
    int dist2 = min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x));   //�ڶ��������
    cout << min(dist1, dist2) << endl;
}
