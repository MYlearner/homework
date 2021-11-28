#include <iostream>
#include <string>
#include <vector>
#define  VertexType string
typedef int EdgeType;
using namespace std;

/********链表队列LinkQueue************/
typedef int QElemType;

/*LinkQueue节点数据结构*/
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

/*LinkQueue数据结构*/
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;

/*LinkQueue初始化*/
bool InitQueue(LinkQueue &Q)
{
	QNode *temp = new QNode;
	if (!temp) return false;
	temp->data = -1;
	temp->next = NULL;
	Q.front = Q.rear = temp;
	return true;
}

/*判断LinkQueue是否为空*/
bool isEmpty(const LinkQueue Q)
{
	return Q.front->next == NULL;
}

/*入队操作*/
bool EnQueue(LinkQueue &Q, QElemType i)
{
	QNode *temp = new QNode;
	if (!temp) return false;
	temp->data = i;
	temp->next = NULL;
	Q.rear->next = temp;
	Q.rear = temp;

	return true;
}

/*出队操作*/
QElemType DeQueue(LinkQueue &Q)
{
	QNode *ptr = Q.front->next;
	if (ptr->next)
		Q.front->next = ptr->next;
	else
		Q.front->next = NULL;
	int Data = ptr->data;
	delete(ptr);
	return Data;
}
/***********邻接表数据结构*************/

/*相邻接点的数据结构*/
typedef struct EdgeNode 
{
	int adivex;         //邻接点下标
	EdgeType weight;    //顶点与邻接点之间的权重
	struct EdgeNode *next;//指向顶点的下一个邻接点
}EdgeNode;

/*顶点的数据结构*/
typedef struct VertexNode
{
	VertexType data;    //顶点存储的数据类型
	EdgeNode *firstedge;//指向第一个邻接点
}VertexNode,*AdjList;

/*图的数据结构*/
typedef struct        
{
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdiList;

/*创建图*/
void CreateALFraph(GraphAdiList &G)
{
	cout << "请输入顶点数和边数" << endl;
	cin >> G.numVertexes >> G.numEdges;
	cout << "请输入每个顶点的名称" << endl;
	G.adjList = new VertexNode[G.numVertexes];
	for (int i = 0; i < G.numVertexes; i++)
	{
		cin >> G.adjList[i].data;
		G.adjList[i].firstedge = NULL;
	}

	int i, j ,Weight;
	for (int k = 0; k < G.numEdges; k++)
	{
		cout << "请输入第"<<k+1<<"条边上的顶点序号和权重" << endl;
		cin >> i >> j>> Weight;

		/*头插法将节点接到邻接表上*/
		EdgeNode *temp1 = new EdgeNode;
		temp1->adivex = j;
		temp1->weight = Weight;
		temp1->next = G.adjList[i].firstedge;
		G.adjList[i].firstedge = temp1;

		EdgeNode *temp2 = new EdgeNode;
		temp2->adivex = i;
		temp2->weight = Weight;
		temp2->next = G.adjList[j].firstedge;
		G.adjList[j].firstedge = temp2;	
	}
}

/*输出邻接表*/
void Display(const GraphAdiList G)
{
	for (int i = 0; i < G.numVertexes; i++)
	{
		cout << G.adjList[i].data << "->{";
		EdgeNode *ptr = G.adjList[i].firstedge;
		while (ptr)
		{
			cout << " [" << ptr->adivex<<","<<ptr->weight<<"]";
			ptr = ptr->next;
		}
		cout << " }" << endl;
	}
}

void DFS(GraphAdiList G, int i,vector<bool> &visited)
{
	visited[i] = true;
	cout << G.adjList[i].data<<" ";
	EdgeNode *ptr = G.adjList[i].firstedge;
	while (ptr)
	{
		if (!visited[ptr->adivex])
			DFS(G, ptr->adivex,visited);
		ptr = ptr->next;
	}
}
 
void DFSTraverse(GraphAdiList G, vector<bool> &visited)
{
	for (int i = 0; i < G.numVertexes; i++)
		visited[i] = false;

	/*如果是连通图就不必循环*/
	for (int i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFS(G, i, visited);
	}

	/*DFS(G, i, visited);*/
}

void BFSTraverse(GraphAdiList G, vector<bool> &visited)
{
	LinkQueue Q;
	InitQueue(Q);

	for (int i = 0; i < G.numVertexes; i++)
		visited[i] = false;

	for (int i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			cout << G.adjList[i].data << " ";
			EnQueue(Q, i);
			while (!isEmpty(Q))
			{
				int index = DeQueue(Q);
				EdgeNode *ptr = G.adjList[index].firstedge;
				while (ptr)
				{
					if (!visited[ptr->adivex])
					{
						visited[ptr->adivex] = true;
						cout << G.adjList[ptr->adivex].data << " ";
						EnQueue(Q, ptr->adivex);
					}
					ptr = ptr->next;
				}
			}
		}
		
	}
}

int main()
{
	GraphAdiList Graph;
	CreateALFraph(Graph);
	vector<bool> visited(Graph.numVertexes);//定义访问数组

	cout << "邻接表如下：" << endl;
	Display(Graph);

	cout << "深度遍历" << endl;
	DFSTraverse(Graph, visited);

	cout <<endl<< "广度遍历" << endl;
	BFSTraverse(Graph, visited);

	system("pause");
}
