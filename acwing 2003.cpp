#include <bits/stdc++.h>
using namespace std;

int res;
string s;
stack<int> st; 

int main(){

    cin >> s;
    int n = s.size();

    if(n & 1){
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i ++ ){
        if (st.empty())    
            st.push(i);  
        else if (s[st.top()] == '(' && s[i] == ')')    
            st.pop();
        else
            st.push(i);
    }

    if (st.size() >= 2){
        int pos = st.top();
        st.pop();
if (s[pos] == ')') {
            for (int i = 0; i < pos; ++i)
                if (s[i] == ')')    
                    res++;
        }
        else {
            for (int i = pos; i < n; ++ i )
                if (s[i] == '(')    
                    res++;
        }
    }
    cout << res << endl;
    return 0;
} 

