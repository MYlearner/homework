class Solution {
public:
    long long appealSum(string &s) {
        long ans = 0L, sum_g = 0L;
        vector<int> pos(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            int c = s[i] - 'a';
            sum_g += i - pos[c];
            ans += sum_g;
            pos[c] = i;
        }
        return ans;
    }
};

