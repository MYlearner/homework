#include <bits/stdc++.h>
using namespace std;

int a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;
    int dist1 = abs(a - b);    //第一种情况：直接从 a 到 b
    int dist2 = min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x));   //第二种情况，
    cout << min(dist1, dist2) << endl;
}
