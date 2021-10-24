学习情况简述
（本周学习了什么？遇到了什么问题？有什么感想或收获？等）
本周学习了堆以及其相关知识
要实现的操作
1.插入一个数
2.求集合中最小的值
3.删除最小值
(STL中priority_queue可以实现）
4.删除任意一个元素
5.修改任意一个元素
堆是一个完全二叉树
性质：每个父节点小于等于左右结点（小根堆）
存储：用一个一维数组（一号位置存根节点，左儿子为2x，右儿子为2x+1）

操作：（1）down（x） //一个结点变大，下移（通过比较与两个儿子结点比较，与最小的结点交换）
（2）up（x） //一个结点变小，上移（通过与父节点比较，如果比父节点小则进行交换）
1.插入操作
heap[++size]=x;up[size];
2.求集合中最小值
heap[1];
3.删除最小值（将最后一个元素覆盖一个元素，然后down）
heap[1]=heap[size];size- -;down[1];
4.删除任意一个元素
heap[k]=heap[size];size- -;down(k);up(k);
5.修改任意一个元素
heap[k]=x;down(k);up(k);
本周练习过的代码（例）
（本周练习写过的代码，如实填写，疑似抄袭会单独测试）
代码1：堆的数据结构
struct MaxHeap
{
    EType *heap; //存放数据的空间，下标从1开始存储数据，下标为0的作为工作空间，存储临时数据。
    int MaxSize; //MaxSize是存放数据元素空间的大小
    int HeapSize; //HeapSize是数据元素的个数
};
MaxHeap H;void MaxHeapInsert(MaxHeap &H, EType &x)
{
    if(H.HeapSize==H.MaxSize) return false;
    
    int i=++H.HeapSize;
    while(i!=1&&x>H.heap[i/2])
    {
        H.heap[i]=H.heap[i/2];
        i/=2;
    }
    H.heap[i]=x;
    return true;
}
代码2：删除
void MaxHeapDelete(MaxHeap &H, EType &x)
{
    if(H.HeapSize==0) return false;
    x=H.heap[1];
    H.heap[0]=H.heap[H.HeapSize--];
    int i=1, son=i*2;
     while(son<H.HeapSize)
        {
            if(son<H.HeapSize&&H.heap[son]<H.heap[son+1])
                son++;
            if(H.heap[i]>H.heap[son])
                break;
             H.heao[i]=H.heap[son];
            i=son;
            son*=2;
        }
        H.heap[i]=H.heap[0];
    return true;
    
}
代码3：
#include<iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
 
void quick_build(int a[], int len, int root)
{
    int left=root*2+1;
    int flag=left;
    while(left<len)
    {
        int right=left+1;
        while(right<len&&a[right]>a[left])
            flag=right;
        
    }
    if(a[root]<a[flag])
    {
        swap(a[root],a[flag]);
        heap_build(a,len,flag);
}
 
void quick_sort(int a[], int len)
{
    for(int i=len/2;i>0;i--)
        heap_build(a,len, i);
    for(int j=len-1;j>0;j--)
    {
        swap(a[0],a[j]);
        heap_build(a,0,j);
    }         
}

本周练习过的代码
代码4：堆排序
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;

int n,m;
int h[N],s;

void down(int u)
{
    int t=u;
    if(u*2<=s&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=s&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t)
    {
        swap(h[t],h[u]);
        down(t);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    s=n;
    
    for(int i=n/2;i;i--) down(i);
    
    while(m--)
    {
        printf("%d ",h[1]);
        h[1]=h[s];
        s--;
        down(1);
    }
    
    return 0;
    
}
代码5：模拟堆
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
const int N=100010;

int h[N],ph[N], hp[N],cnt;

void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void down(int u)
{
    int t=u;
    if(u*2<=cnt&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=cnt&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t)
    {
        heap_swap(u,t);
        down(t);
    }
}

void up(int u)
{
    while(u/2&&h[u]<h[u/2])
    {
        heap_swap(u,u/2);
        u/=2;
    }
}

int main()
{
    int n,m=0;
    scanf("%d",&n);
    while(n--)
    {
        char op[5];
        int k,x;
        scanf("%s",op);
        if(!strcmp(op,"I"))
        {
            scanf("%d",&x);
            cnt++;
            m++;
            ph[m]=cnt,hp[cnt]=m;
            h[cnt]=x;
            up(cnt);
        }
        else if(!strcmp(op,"PM")) printf("%d\n",h[1]);
        else if(!strcmp(op,"DM")) 
        {
            heap_swap(1,cnt);
            cnt--;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,cnt);
            cnt--;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d",&k,&x);
            k=ph[k];
            h[k]=x;
            up(k);
            down(k);
        }
    }
    
}
代码6：标准库堆的使用
#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
template<typename Container>
void PrintContainer(Container container)
{
    for (auto i : container)
    {
        cout << i << ' ';
    }
    cout << endl;
}
int main()
{
    int a[] = {10, 50, 40, 20, 30};
    vector<int> ivec(a, a+5);
    PrintContainer(ivec);
 
    make_heap(ivec.begin(), ivec.end(), greater<int>());//建堆
    PrintContainer(ivec);
 
    pop_heap(ivec.begin(), ivec.end(), greater<int>());//先pop,然后在容器中删除
    ivec.pop_back();
    PrintContainer(ivec);
 
    ivec.push_back(100);//先在容器中加入，再push
    push_heap(ivec.begin(), ivec.end(), greater<int>());
    PrintContainer(ivec);
 
    sort_heap(ivec.begin(), ivec.end());
    PrintContainer(ivec);
 
    return 0;
}
