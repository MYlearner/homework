class Solution {//ĞÂÌØĞÔfor (auto str_1 : dp[j])
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> dp(n+1);
		dp[0].emplace_back("");

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= i - 1; ++j) {
				// left_vector = dp[j]
				// right_vector = dp[i-1-j]
				for (auto str_1 : dp[j]) {
					for (auto str_2 : dp[i - 1 - j]) {
						dp[i].emplace_back("(" + str_1 + ")" + str_2);
					}
				}
			}
		}

		return dp[n];
	}
};
