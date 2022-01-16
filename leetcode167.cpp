class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        vector<int>re;
        while(left<right)
        {
int sum=numbers[left]+numbers[right];
if(sum==target)
{
    break;
}
else if(sum>target)
{
    right--;
}
else
{
    left++;
}
        }
   re.push_back(left+1);
    re.push_back(right+1);
    return re;
     }
};
