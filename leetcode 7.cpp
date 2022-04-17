class Solution {
public:
    int reverse(int x) {
        if(x==0)
        return 0;
        if(x==INT_MIN)
        return 0;
    else
    {
        int a1=0;
        if(x>0)
        {
            while(x)
            {
int a2=x%10;
if(a1<=(INT_MAX-a2)/10)
             {  a1=a1*10+a2;
                x/=10;}
                else
                return 0;
            }
return a1;
        }
        else
        {
          x=-x; 
           while(x)
            {
int a2=x%10;
if(a1<=(INT_MAX-a2)/10)
              {  a1=a1*10+a2;
                x/=10;}
                else 
                return 0;
            }
            return -a1;
        }
    }
    }
};
