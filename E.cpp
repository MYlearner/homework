#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n,k,q;
    cin>>t;
    while (t--) {
        cin>>n>>k>>q;
        k = k % (2*n);
        if(q&1) {
            int seg_1 = n - q;
            int seg_2 = n + n - q;
            if(k <= seg_1) {
                cout << q + k <<'\n';
            }
            else if(k > seg_2) {
                cout << k - seg_2 <<'\n';
            }
            else {
                cout << n + seg_1 + 1 - k <<'\n';
            }
        }
        else {
            int seg_1 = q - 1;
            int seg_2 = q + n;
            if(k <= seg_1) {
                cout << q - k <<'\n';
            }
            else if(k > seg_2) {
                cout << n + seg_2 - k <<'\n';
            }
            else {
                cout << k - seg_1 <<'\n';
            }
        }
        
    }
    
}
