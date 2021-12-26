/*class Solution {
public:
    int candy(vector<int>& ratings) {
        int num=sizeof(ratings);
        int can[num-1];
        int j=1;
        int sum1=1;
        while(ratings[0]>ratings[j]&&j<num-1)
        { 
            sum1++;
            ++j;

        }
        double sumcandy=sum1;
        can[0]=sum1;
        int i=1;
        while(i<num-1)
        {
if(ratings[i]>ratings[i-1])
{
    can[i]++;
}
int p=i+1;
int sum2=1;
while(ratings[i]>ratings[p]&&p<num-1)
{
sum2++;
p++;
}
if(can[i]<sum2)
can[i]=sum2;
sumcandy=sumcandy+can[i];
    }
    if(ratings[num-1]>ratings[num-2])
    can[num-1]=can[num-2]+1;
    else
    can[num-1]=1;
    sumcandy+=can[num-1];
    sumcandy=(int)sumcandy;
    return sumcandy;
    }
};*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int result=0;
        vector<int> num(ratings.size(),1);//初始化为1
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
                num[i]=num[i-1]+1;
            }
        }
        for(int i=ratings.size()-1;i>=1;i--){
            if(ratings[i-1]>ratings[i]){
                num[i-1]=max(num[i-1],num[i]+1);
            }
        }
        for(int i=0;i<ratings.size();i++){ //计算结果
            result+=num[i];
        }
        return result;
    }
};
