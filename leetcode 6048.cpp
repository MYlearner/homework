class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int num[1000010];//weizhi
        int size[1000010];//cangdu
        for(int i=0;i<1000010;++i)
        {
            num[i]=-1;
            size[i]=INT_MAX;
        }
        for(int i=0;i<cards.size();++i)
        {
            if(num[cards[i]]==-1)
            {
                num[cards[i]]=i;
}
            else
            {
                if((i-num[cards[i]]+1)<size[cards[i]])
                {
                    size[cards[i]]=i-num[cards[i]]+1;
}
                num[cards[i]]=i;
            }
}
        vector<int>re;
        for(int i=0;i<1000010;++i)
        {
            if(num[i]!=-1)
            {
                if(size[i]!=INT_MAX)
                    re.push_back(size[i]);
            }
}
        sort(re.begin(),re.end());
        if(re.empty())
            return -1;
        else
        return re[0];
    }
};
