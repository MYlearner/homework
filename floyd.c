#include<iostream>
#include<sstream>
using namespace std;
const int Max=100;
string Int_to_String(int n)//int转换string 
{
ostringstream stream;
stream<<n; //n为int类型
return stream.str();
}
class MGraph{
    public:
        MGraph(){

        }
        MGraph(int n,int e);
        ~MGraph(){

        }
    public:
    int vertex[Max];
    int arc[Max][Max];
    int vertexNum,arcNum;
};
MGraph::MGraph(int n,int e){
    int i,j;
    vertexNum=n;
    arcNum=e;
    for(int i=0;i<vertexNum;i++)
    vertex[i]=i;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    arc[i][j]=10000;
    cout<<"请输入图中各边的情况："<<endl;
    for(int k=0;k<e;k++){
        cin>>i>>j;
        cin>>arc[i][j];
    }
}
void Dijkstra(MGraph G,int v){
    int dist[Max],s[Max];
    string path[Max]; 
    for(int i=0;i<G.vertexNum;i++)
    {
    dist[i]=G.arc[v][i];
    if(dist[i]!=10000)
    path[i]=Int_to_String(G.vertex[v])+"->"+Int_to_String(G.vertex[i]);
    else
    path[i]="";
    }
    s[0]=v;
    dist[v]=0;
    int num=1;
    for(int i=0;i<G.vertexNum;i++)
    {
    int t=10000,k;
    for(int j=0;j<G.vertexNum;j++)
    {
        if(dist[j]<t&&dist[j]!=0)
        {
        t=dist[j];
        k=j;
        }
    }
    cout<<"终点为："<<k<<"  最短路径长度为："<<dist[k]<<"  过程："<<path[k]<<endl;
    s[num++]=k;
    for(int j=0;j<G.vertexNum;j++){
        if(dist[j]!=0&&dist[j]>(dist[k]+G.arc[k][j])){
            dist[j]=dist[k]+G.arc[k][j];
            path[j]=path[k]+"->"+Int_to_String(j);
        }
    }
    dist[k]=0;
    if(num==G.vertexNum)
    break;
    }
    cout<<"找到终点的顺序为："<<endl;
    for(int i=1;i<num;i++)
    cout<<s[i]<<" "; 
    cout<<endl;
}
int main(){
   int n,e,v;
   cout<<"输入起点下标："<<endl; 
   cin>>v;
   cout<<"输入图的顶点数和边数："<<endl;
   cin>>n>>e;
   MGraph G(n,e);
   Dijkstra(G,v);
   return 0;
}
