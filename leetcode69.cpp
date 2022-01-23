class Solution {
public:
    int mySqrt(int x) {
        long long int pow;
 int left=1,right=x;
 long long int ans;
        if(x==0)
        return 0;
            while(left<=right)
            {
                long long int mid=(right-left)/2+left;
                pow=mid*mid;
                if(pow==x)
                {return mid;
                }
                else if(pow<x)
                {
                    ans=mid;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
        return ans;
        }
};
