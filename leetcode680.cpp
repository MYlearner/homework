/*class Solution {
public:
    bool validPalindrome(string s) {
        int left=0,right=s.length()-1;
        int count=0;
        while(count<2)
        {
            while(left<right&&s[left]==s[right])
        {
            left++;
            right++;
        }
        if(s[left]!=s[right])
    {
        count++;
    }
   else if(s[left+1]==s[right])
    {
        left++;
    }
    else if(s[left]==s[right-1])
    {
        right--;
    }

    if(count<2&&((left==right)||(left>right)))
    {
        break;
        return true;
    }

}
        if(count<2&&((left==right)||(left>right)))
    {
        return true;
    }
    else 
    return false;

    }
};*/
class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};
