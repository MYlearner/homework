class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_map<string, int> result;
        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            string tmp = "";
            for (int j = i; j < nums.size(); j++) {
                if(nums[j] % p == 0) count += 1;
                if(count > k) break;
                tmp += nums[j] + '0';
                result[tmp] = 1;
            }
        }
        return result.size();
    }
};

