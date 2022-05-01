class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        set<string> st;
        
        int len = (int)s.size();
        for(int i = 1; i <= len; i++) {
            st.insert(s.substr(0, i));
        }
        
        int cnt = 0;
        for(string s : words) {
            if(st.count(s)) {
                cnt ++;
            }
        }
        return cnt;
    }
};

