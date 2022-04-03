class Solution {
public:
    string convert(string s, int num ) {
        int size=s.size();
        if(size<=num||num==1)
        return s;
        string s1;  
for(int i=0;i<num;++i)
{
s1+=s[i];
int temp1=2*(num-1-i);
int temp2=2*i;
int sum=1;
int temp=temp1;
int start=i;
while((start+temp)<size)
{
    if(temp!=0)
{
    start+=temp;
s1+=s[start];
}
sum++;
if(sum%2==1)
temp=temp1;
else 
temp=temp2;
}
}
return s1;
}
};
