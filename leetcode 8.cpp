class Solution {
public:
    int myAtoi(string s) {
        int size=s.size();
        int i=0;
while(i<size&&s[i]==' ')
++i;
if(i==size)
return 0;
else
{
if(s[i]=='-')
{
    ++i;
    int res=0;
    while(i<size&&s[i]=='0')
    ++i;
    if(i==size)
    return 0;
    else
    {
        while(i<size&&(s[i]-'0'>=0)&&(s[i]-'0'<=9))
{
    int a1=s[i]-'0';
    if(res<=(INT_MAX-a1)/10)
    {
        res=res*10+a1;
        ++i;
    }
    else
    {
        return INT_MIN;
    }
}
    }
    return -res;
}
else
{
    if(s[i]=='+')
    {
        ++i;
    }
    int res=0;
    while(i<size&&s[i]=='0')
    ++i;
    if(i==size)
    return 0;
    else
    {
        while(i<size&&((s[i]-'0'>=0)&&(s[i]-'0'<=9)))
{
    int a1=s[i]-'0';
    if(res<=(INT_MAX-a1)/10)
    {
        res=res*10+a1;
        ++i;
    }
    else
    {
        return INT_MAX;
    }
}
    }
    return res;
}
}
return 0;
    }
};
