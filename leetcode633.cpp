class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1)
        return true;
        else if(c==2)
        return true;
        else if(c==3)
        return false;
long a=0,b=sqrt(c);
while(a<=b)
{
   long a1= a*a+b*b;
    if(a1==c)
    {
    return true;
    break;
    }
   else if(a1<c)
    {
        a++;
    }
    else 
    {
        b--;
    }
}
return false;
}
};
