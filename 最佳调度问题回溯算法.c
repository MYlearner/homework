#include<stdio.h>
#include<math.h>
#define MAX 100
#define MAX_VALUE 32767

int a[3][MAX]={0};		//���ڴ�ŵ����������Ϣ����1��Ϊ�����ţ���2��Ϊ��������ʱ�䣬��3��Ϊ���Ƚ��
int s[MAX]={0};			//��ʾ��ǰ������Ҫ������ʱ��
int nbest[MAX]={0};		//��ʾ��ǰ���Ƚ��
int minn=MAX_VALUE;		//��ʾ���Ⱥ������ʱ��
int n;					//��ʾ������
int k;					//��ʾ������

//���ļ�����һ������ 
void fileWriteInt(int i){
	FILE *fp;
	fp = fopen("i:\\�㷨\\���ݷ�\\output.txt", "a");
	
	if (fp == NULL) {			//�����ļ�ʧ�����˳�
        printf("���ܴ��ļ���\n");
        return ;
    }
	
	fprintf(fp,"%d\n",i); 
	
	fclose(fp);	
}

 //���ļ���ȡ���� 
void fileRead(){
	FILE *fp;
	fp = fopen("i:\\�㷨\\���ݷ�\\input.txt", "r");
	if (fp == NULL) {			//�����ļ�ʧ�����˳�
        printf("���ܴ��ļ���\n");
        return ;
    }
 	//���ļ��ж�������n�ͻ�����k 
    fscanf(fp,"%d",&n);
    fscanf(fp,"%d",&k);
		
	
	//���ļ��ж�ȡ����S�е�n������Ԫ��
	for(int i=1;i<=n;i++){
		a[0][i]=i;
		fscanf(fp,"%d",&a[1][i]);
		a[3][i]=0;
	}
	
	fclose(fp);	
}

void search(int x,int y){        
        //��ѵ����㷨
        if(y>minn)      //��Լ����֦
            return;
        if(x>n){        //����Ҷ���
            if(y<minn){     //�ж����Ž⣬�������Ž������ֵ
                minn = y;       
                for(int i=1;i<=n;i++){
                    a[2][i] = nbest[i];
                }
            }
            return;
        }
        for(int i=1;i<=k;i++){
            if(s[i]+a[1][x]<minn){      //��Լ����֦
                s[i] += a[1][x];
                nbest[x]=i;
                search(x+1,fmax(y,s[i]));        //�ݹ�
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
 

