class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>an1,an2;
        int size1=nums1.size();
        int size2=nums2.size();
        for(int i=0;i<size1;++i)
        {
            if(an1.find(nums1[i])==an1.end())
            {
                an1.insert(pair(nums1[i],i));
}
        }
            for(int i=0;i<size2;++i)
        {
            if(an2.find(nums2[i])==an2.end())
            {
                an2.insert(pair(nums2[i],i));
}
            }
                vector<int>re1,re2;
                for(auto i:an2)
                {
                    if(an1.find(i.first)==an1.end())
                    {
                        re2.push_back(i.first);
}
                }
                    for(auto i:an1)
                {
                    if(an2.find(i.first)==an2.end())
                    {
                        re1.push_back(i.first);
}
}
        vector<vector<int>>re;
        re.push_back(re1);
        re.push_back(re2);
        return re;
                    
}
        
    
};
