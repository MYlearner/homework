class Solution {
public:
    string removeDigit(string s1, char c) {
     int k=0;
	int flag=0;
	for(int i=0;i<s1.size();++i)
	{
		if(s1[i]==c)
		{
			++k;
			flag=i;
		}
	}
	if(k==1)
	{string re;
		for(int i=0;i<s1.size();++i)
		{if(i!=flag)
			re+=s1[i];
		}
		return re;   
    }
        else
        {int a1=0;
            for(int i=1;i<s1.size();++i)
            {
                if(s1[i-1]==c)
                {
                    if(s1[i-1]<s1[i])
                    { int f=i-1;
                    string s2;
                     a1=1;
                    for(int i=0;i<s1.size();++i)
                    {if(i!=f)
                        s2+=s1[i];
                     
}
                    return s2;
                }
                    
                }
}
if(a1==0)
{/* 
    for(int i=1;i<s1.size();++i)
            {
                if(s1[i-1]==c)
                {
                    if(s1[i]==c)
                    {a3=1;
                         int f=i-1;
                    string s2;
                     a1=1;
                    for(int i=0;i<s1.size();++i)
                    {if(i!=f)
                        s2+=s1[i];
                    }
                        return s2;
                }
}
        }*/
    int a3=0;
 if(a3==0)
 {
     for(int i=s1.size()-1;i>0;--i)
     {
         if(s1[i]==c)
         {
             int d1=i;
             string s3;
             for(int i=0;i<s1.size();++i)
             {
                 if(i!=d1)
                 {
                     s3+=s1[i];
                 }
             }
          return s3;
         }
}
 }
}
        }
        return " ";
    }
};
