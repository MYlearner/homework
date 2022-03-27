class Solution {
public:
    bool winnerOfGame(string colors) {
        int size=colors.size();
       // if(size==1||size==2)
       // return false;
        int a1=0,a2=0;
        for(int i=1;i<size-1;++i)
        {
if(colors[i]=='A')
{
    if(colors[i]==colors[i+1]&&colors[i]==colors[i-1])
    a1++;
}
else if(colors[i]=='B')
{
    if(colors[i]==colors[i+1]&&colors[i]==colors[i-1])
    a2++;
}

        }
     //   cout<<a1<<" "<<a2<<endl;
        if(a1>=(a2+1))
        return true;
        else 
        return false;
    }
};
