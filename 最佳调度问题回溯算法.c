#include<stdio.h>
#include<math.h>
#define MAX 100
#define MAX_VALUE 32767

int a[3][MAX]={0};		//用于存放调度任务的信息，第1行为任务编号，第2行为任务所需时间，第3行为调度结果
int s[MAX]={0};			//表示当前机器需要工作的时间
int nbest[MAX]={0};		//表示当前调度结果
int minn=MAX_VALUE;		//表示调度后的最少时间
int n;					//表示任务数
int k;					//表示机器数

//向文件读入一个数字 
void fileWriteInt(int i){
	FILE *fp;
	fp = fopen("i:\\算法\\回溯法\\output.txt", "a");
	
	if (fp == NULL) {			//若打开文件失败则退出
        printf("不能打开文件！\n");
        return ;
    }
	
	fprintf(fp,"%d\n",i); 
	
	fclose(fp);	
}

 //从文件读取数据 
void fileRead(){
	FILE *fp;
	fp = fopen("i:\\算法\\回溯法\\input.txt", "r");
	if (fp == NULL) {			//若打开文件失败则退出
        printf("不能打开文件！\n");
        return ;
    }
 	//从文件中读任务数n和机器数k 
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&k);
		
	
	//从文件中读取集合S中的n正整数元素
	for(int i=1;i<=n;i++){
		a[0][i]=i;
		fscanf(fp,"%d",&a[1][i]);
		a[3][i]=0;
	}
	
	fclose(fp);	
}

void search(int x,int y){        
        //最佳调度算法
        if(y>minn)      //隐约束剪枝
            return;
        if(x>n){        //到达叶结点
            if(y<minn){     //判断最优解，更新最优解和最优值
                minn = y;       
                for(int i=1;i<=n;i++){
                    a[2][i] = nbest[i];
                }
            }
            return;
        }
        for(int i=1;i<=k;i++){
            if(s[i]+a[1][x]<minn){      //显约束剪枝
                s[i] += a[1][x];
                nbest[x]=i;
                search(x+1,fmax(y,s[i]));        //递归
                s[i] -= a[1][x];
            }
        }
        return;
    }


int main(){
	fileRead();
	search(1,0);
	fileWriteInt(minn);
	return 0;
}
 

