class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>occ;
int length=1;
int size=s.size();
if(size==0||size==1)
return size;
int left=0,right=1;
occ.insert(s[left]);
if(size==2)

{
if(s[0]==s[1])
return 1;
else 
return 2;
}
while(right<size)
{
while(right<size&&!occ.count(s[right]))
{
    
    occ.insert(s[right]);
    right++;
}
length=max(length,(right-left));
if(right!=size)
    {
        while(s[left]!=s[right])
        {
            occ.erase(s[left]);
            left++;
        }
        if(s[left]==s[right])
{
            occ.erase(s[left]);
            left++;
        }
    }

}
    return length;}
};
