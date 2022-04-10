#include <iostream>
using namespace std;

int c[4], w[4]; // c[]为桶容量，w[]为当前桶中有多少牛奶
int min1,min2,min3;

int main()
{
    for (int i = 1; i <= 3; i++)    cin >> c[i] >> w[i];

    int time = 100; 
    while (true)
    {
        if (time) {min1 = min(w[1], c[2] - w[2]); w[1] -= min1, w[2] += min1;  time--;}
        if (time) {min2 = min(w[2], c[3] - w[3]); w[2] -= min2, w[3] += min2;  time--;}
        if (time) {min3 = min(w[3], c[1] - w[1]); w[3] -= min3, w[1] += min3;  time--;}
        if (!time)  break;
    }

    printf("%d\n%d\n%d", w[1], w[2], w[3]);
    return 0;
}

