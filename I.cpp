#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>> n;
    int nums[n];
    int N=n;
    int muilt = 1;
    unordered_map<int,int> hash;
    int count_0,count_1,count__1;
    while(N--) {
        cin >> nums[N];
        hash[nums[N]]++;
    }
    int res = n;
    if(hash[0]) {
        if(hash[0] == 1)
            cout << 1 <<'\n';
        if(hash[0] > 1)
            cout << 0 <<'\n';
        return 0;
    }
    
    for(auto& e:hash) {
        if(e.first == 1)
            continue;
        if(e.second > 1)
            res = res - e.second + 1;
    }
    if(hash[1])
        cout << res - hash[1]<<'\n';
    else 
        cout << res <<'\n';

}
