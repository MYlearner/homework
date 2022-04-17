#include<bits/stdc++.h> 
using namespace std;
bool check(string s)
{
	int size=s.size();
	for(int i=1;i<size;++i)
	{
		int a1=s[i-1]-'a';
		int a2=s[i-1]-'A';
		if(a1>=0&&a1<=25)
		{
			char c1=s[i-1]-1;
			char c2='A'+(s[i-1]-'a');
			if(s[i]==c1||s[i]==c2)
		{ 
				
				if(c1<'a')
				return false;
		}
			else
			return false;
		}
		else if(a2>=0&&a2<25)
		{
			char c1=s[i-1]+1;
			char c2='a'+(s[i-1]-'A');
			if(s[i]==c1||s[i]==c2)
		{
				if(c1>'Z')
				return false;
		}
			else
			return false;
		}
	}
	
	return true;
	
	

}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
int n;
cin>>n;
while(n--)
{
string s;
cin>>s;
    if(s.size()==1)
        cout<<"Y"<<endl;
    else{
if(check(s))
cout<<"Y"<<endl;
else
cout<<"N"<<endl; 
}
}
	return 0;
}
