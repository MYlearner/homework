#include<bits/stdc++.h>
using namespace std;
long long n,i,j,x;
string a,b,c,d;
string an[13]={"Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig","Rat"};//��ʼ��
map<string,long long> year;
int main()
{
    year["Bessie"]=0;//��ʼ�������X�m���ڻ���Ա�����ɲ�����
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>b>>b>>c>>d>>d>>d;//����һЩ����Ҫ�Ķ���
        if(b=="previous")
        {
            for(j=year[d]-1;;j--)   if(an[(j%12+12)%12]==c) break;//������ݣ�(j%12+12)%12�����и��������У��б�Ҫ���һ�£�
            year[a]=j;
        }
        else
        {
            for(j=year[d]+1;;j++)   if(an[(j%12+12)%12]==c) break;//������ݣ�(j%12+12)%12�����и��������У��б�Ҫ���һ�£�
            year[a]=j;
        }
    }
    cout<<abs(year["Elsie"]);
    return 0;
}

