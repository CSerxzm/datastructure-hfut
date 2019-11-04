#include "createGrpAdjLinkedList.h"
#include "linkedQueue.h"
#include "linkedstack.h"
#define MAXLEN 30
#define MAX 999

int A[MAXLEN][MAXLEN];
/*int DFS1(Graph &G,int m)
{
	EdgeNode *p;
	int i,j=0;
	for(i=1;i<=G.VerNum;i++)
		visited[i]=false;
	i=m;
	while(j<G.VerNum)
	{
		visit(G,i);
		j++;
		p=G.VerList[i].firstEdge;
		while(visited[p->adjVer])
		{
			p=p->next;
			if(!p)
				return 0;
		}
		i=p->adjVer;
	}
}*/
void DFS(Graph &G,int m,int &j)
{
	EdgeNode *p;
	if(j<G.VerNum)
	{
		visit(G,m);
		j++;
		p=G.VerList[m].firstEdge;
		while(p)
		{
			if(!visited[p->adjVer])
				DFS(G,p->adjVer,j);
			else
				p=p->next;
		}
	}
}
void DFStravel(Graph &G,int m)
{
	int i,j=0;
	for(i=1;i<=G.VerNum;i++)
		visited[i]=false;
	DFS(G,m,j);
}
void BFS(Graph &G,int m)
{
	Queue Q;
	int i;
	EdgeNode *p;
	for(i=1;i<=G.VerNum;i++)
		visited[i]=false;
	visit(G,m);
	Q.enQueue(m);
	p=G.VerList[m].firstEdge;
	while(!Q.empty())
	{
		i=p->adjVer;
		if(!visited[i])
		{
			visit(G,i);
			Q.enQueue(i);
		}
		p=p->next;
		if(!p)
		{
			Q.getFront(i);
			Q.outQueue();
			p=G.VerList[i].firstEdge;
		}
	}
}

int Edgenum(Graph &G)
{
	int i,num=0;
	EdgeNode *p;
	for(i=1;i<=G.VerNum;i++)
	{
		p=G.VerList[i].firstEdge;
		while(p)
		{
			num++;
			p=p->next;
		}
	}
	if(G.gKind==UDG||G.gKind==UDN)
		num=num/2;
	return num;
}
//深度生成树
Edge edge[MAXLEN];
void DFS_tree(Graph &G,int m,int &j)
{
	EdgeNode *p;
	visited[m]=true;
	p=G.VerList[m].firstEdge;
	while(p&&j<G.VerNum)
	{
		if(!visited[p->adjVer])
		{
			edge[j].start=m;
			edge[j].end=p->adjVer;
			j++;
			DFS_tree(G,p->adjVer,j);
		}
		else
			p=p->next;
	}
}
void DFS_spantree(Graph &G)
{
	int j=0,i;
	for(i=1;i<=G.VerNum;i++)
		visited[i]=false;
	DFS_tree(G,1,j);
	for(i=0;i<G.VerNum-1;i++)
		cout<<"("<<G.VerList[edge[i].start].data<<","<<G.VerList[edge[i].end].data<<") ";
}
//广度生成树
void BFS_spantree(Graph &G,int m)
{
	Queue Q;
	int i,j,k=0;
	EdgeNode *p;
	for(i=1;i<=G.VerNum;i++)
		visited[i]=false;
	visited[m]=true;
	Q.enQueue(m);
	p=G.VerList[m].firstEdge;
	j=m;
	while(!Q.empty()&&k<G.VerNum)
	{
		i=p->adjVer;
		if(!visited[i])
		{
			visited[i]=true;
			edge[k].start=j;
			edge[k].end=i;
			k++;
			Q.enQueue(i);
		}
		p=p->next;
		if(!p)
		{
			Q.getFront(j);
			Q.outQueue();
			p=G.VerList[j].firstEdge;
		}
	}
	for(i=0;i<G.VerNum-1;i++)
		cout<<"("<<G.VerList[edge[i].start].data<<","<<G.VerList[edge[i].end].data<<") ";
}

//普林算法
typedef struct minEdgeType
{
	int v;
	cellType eweight;
}minEdgeType;

bool judgevisited(Graph &G)
{
	int i;
	for(i=1;i<=G.VerNum;i++)
	{
		if(!visited[i])
			return false;
	}
	return true;
}
minEdgeType WE[MAXLEN];
Edge TE[MAXLEN];
void prim(Graph &G,int m)
{
	int i,j=1,k=m;
	EdgeNode *p;
	for(i=1;i<=G.VerNum;i++)
	{
		visited[i]=false;
		WE[i].eweight=MAX;
		TE[i].eweight=MAX;
	}
	visited[m]=true;
	while(!judgevisited(G))
	{
			for(i=1;i<=G.VerNum;i++)
			{
				if(visited[i])
				{
					p=G.VerList[i].firstEdge;
					while(p)//找出临街边最小值
					{
						if(!visited[p->adjVer]&&p->eInfo<WE[i].eweight)
						{
							WE[i].v=p->adjVer;
							WE[i].eweight=p->eInfo;
						}
							p=p->next;
					}
				}
			}
			eInfoType minweight=MAX;
			int minpoint1=MAX;
			int minpoint2=MAX;
			for(i=1;i<=G.VerNum;i++)
			{
				if(minweight>WE[i].eweight&&visited[i])
				{
					minweight=WE[i].eweight;
					WE[i].eweight=MAX;
					minpoint1=i;
					minpoint2=WE[i].v;
				}
			}
			TE[j].start=minpoint1;
			TE[j].end=minpoint2;
			TE[j].eweight=minweight;
			visited[minpoint1]=true;
			visited[minpoint2]=true;
			j++;
	}
	for(j=1;j<=G.VerNum;j++)
		if(TE[j].eweight!=MAX)
		cout<<"("<<G.VerList[TE[j].start].data<<","<<G.VerList[TE[j].end].data<<") ";
}
//Kruskal算法
int flag[MAXLEN];
void Kruskal(Graph &G)
{
	int i,j=1,k,mark1,mark2;
	EdgeNode *p;
	for(i=1;i<=G.VerNum;i++)
	{
		visited[i]=false;
		TE[i].eweight=MAX;
		flag[i]=i;
	}
	while(j<=G.VerNum)
	{
		for(i=1;i<=G.VerNum;i++)
		{
			p=G.VerList[i].firstEdge;
			while(p)
			{
				if(flag[i]!=flag[p->adjVer]&&TE[j].eweight>=p->eInfo)
				{
					TE[j].eweight=p->eInfo;
					TE[j].start=i;
					TE[j].end=p->adjVer;
					if(flag[i]<flag[p->adjVer])
					{
						mark1=flag[i];
						mark2=flag[p->adjVer];
					}
					else
					{
						mark1=flag[p->adjVer];
						mark2=flag[i];
					}
				}
				p=p->next;
			}
		}
		visited[TE[j].start]=true;
		visited[TE[j].end]=true;
		flag[TE[j].start]=mark1;
		flag[TE[j].end]=mark1;
		for(k=1;k<=G.VerNum;k++)
		{
			if(flag[k]==mark2)
				flag[k]=mark1;
		}
		j++;
	}
	for(j=1;j<G.VerNum;j++)
		cout<<"("<<G.VerList[TE[j].start].data<<","<<G.VerList[TE[j].end].data<<") ";
}

//Dijkstra算法
int path[MAXLEN];
int dist[MAXLEN];
void Dijkstra(Graph &G, int path[], int dist[], int vID)
{
	int solved[MAX];
	int i,j;
	int v; 
	eInfoType minDist;  
	EdgeNode *p; 
	for(i=1;i<=G.VerNum;i++)
	{
		solved[i]=0;  
		dist[i]=MAX;  
		path[i]=-1;
	}
	solved[vID]=1; 
	dist[vID]=0;
	path[vID]=-1;
	for(i=1;i<=G.VerNum;i++)
	{
		if(i==vID)
			continue;
		p=G.VerList[i].firstEdge;
		while(p && p->adjVer!=vID)
			p=p->next;
		if(p && p->adjVer==vID)  
		{
			dist[i]=p->eInfo;
			path[i]=vID;
		}	
	}
	for(i=1;i<G.VerNum;i++)
	{
		minDist=MAX;
		for(j=1;j<=G.VerNum;j++)
		{
			if(solved[j]==0 && dist[j]<minDist)
			{
				v=j; 
				minDist=dist[j];
			}
		}
		if(minDist==MAX) 
			return;
		solved[v]=1;
		for(j=1;j<=G.VerNum;j++)
		{
			p=G.VerList[j].firstEdge;
			while(p && p->adjVer!=v)
				p=p->next;
			if(p && p->adjVer==v && solved[j]==0 && minDist+p->eInfo<dist[j])
			{
				dist[j]=minDist+p->eInfo;
				path[j]=v;
			}		
		}
	}
}
void PrintDijkstra(Graph &G, int path[], int dist[], int vID)
{
	int sPath[MAX];
	int vPre;
	int i,j;
	int top=-1;
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<G.VerList[vID].data<<" to "<<G.VerList[i].data;
		if(dist[i]==MAX)
			cout<<" 无可达路径。"<<endl;
		else
		{
			cout<<"最短距离:"<<dist[i];
			cout<<" 路径:";
		}

		top++;
		sPath[top]=i;  
		vPre=path[i]; 
		while(vPre!=-1)  
		{
			top++;
			sPath[top]=vPre; 
			vPre=path[vPre]; 
		}
		if(dist[i]!=MAX)
		{
			for(j=top;j>=0;j--)
			{
				cout<<G.VerList[sPath[j]].data<<"  ";
			}
		}

		top=-1;
		cout<<endl;
	}
}
//floy算法
cellType dist2[MAXLEN][MAXLEN];
int path2[MAXLEN][MAXLEN];
typedef struct GraphAdjMatrix
{
	elementType Data[MAXLEN+1];                 //顶点数组，存放顶点元素的值，Data[0]单元不用
	cellType AdjMatrix[MAXLEN+1][MAXLEN+1];  //邻接矩阵，数组下标为0单元不用，从AdjMatrix[1][1]单元开始
	int VerNum;       //顶点数
	int ArcNum;       //弧（边）数
	GraphKind gKind;  //图的类型:0-无向图；1-无向网；2-有向图；3-有向网
} Graph1;
void transform(Graph &G,Graph1 &G1)
{
	int i,j;
	EdgeNode *p;
//	G1.gKind=G.gKind;
	G1.VerNum=G.VerNum;
	G1.ArcNum=G.ArcNum;
	for(i=1;i<=G1.VerNum;i++)
		for(j=1;j<=G1.VerNum;j++)
		{
			G1.AdjMatrix[i][j]=MAX;
		}
	for(i=1;i<=G.VerNum;i++)
	{
		G1.Data[i]=G.VerList[i].data;
		p=G.VerList[i].firstEdge;
		while(p)
		{
			G1.AdjMatrix[i][p->adjVer]=p->eInfo;
			p=p->next;
		}
	}
}
void Floyd(Graph1 &G, cellType dist2[MAXLEN][MAXLEN], int path2[MAXLEN][MAXLEN])
{
	int i,j,k;
	//初始化距离矩阵和路径矩阵
	for(i=1;i<=G.VerNum;i++)
	{
		for(j=1;j<=G.VerNum;j++)
		{
			dist2[i][j]=G.AdjMatrix[i][j];   //距离矩阵初始化为邻接矩阵
			                                        //初始化路径矩阵，路径矩阵元素path[i][j]中保存编号j顶点的前驱的顶点编号
            if( i!=j && G.AdjMatrix[i][j]<MAX)  //如果i,j之间存在边，则j的前驱为i。否则前驱置为-1
				path2[i][j]=i;
			else
				path2[i][j]=-1;													
		}
	}

	//从k=1开始，迭代到k=G.verNum。依次选择一个顶点k，作为顶点i、j之间的中转顶点，优化顶点i、j之间的距离
	//下面是Floyd算法的核心--三重for循环
	for(k=1; k<=G.VerNum; k++)
	{
		for(i=1; i<=G.VerNum; i++)
		{
			for(j=1; j<=G.VerNum;j++)
			{
				if(i!=j && dist2[i][k]+dist2[k][j]<dist2[i][j])  //k作为中转跳点，i、j之间距离变小，接收k作为中转点，更新i、j之间的距离
				{
					dist2[i][j]=dist2[i][k]+dist2[k][j];  //更新距离
					path2[i][j]=path2[k][j];  //修改前驱顶点					
				}
			}	
		}
	}
}

//打印Floyd算法给出的最短路径
void PrintFloyd(Graph1 &G, cellType dist2[MAXLEN][MAXLEN], int path2[MAXLEN][MAXLEN])
{
	int sPath[MAX];  //定义一个类似栈操作的数组
	int pra;  //前驱结点编号
	int top=-1;  //栈顶
	int i;

	int j;
	int m;

	for(i=1; i<=G.VerNum; i++)
	{		
		for(j=1; j<=G.VerNum; j++)
		{
			cout<<G.Data[i]<<" to "<<G.Data[j];
			if(dist2[i][j]==MAX)
				cout<<" 无可达路径。"<<endl;
			else
			{
				cout<<" 最短距离:"<<dist2[i][j];
				cout<<" 路径:";

				top++;
				sPath[top]=j;   //sPath[0]为当前顶点i
				pra=path2[i][j];  //i顶点的前驱顶点
				while(pra!=i)
				{
					top++;
					sPath[top]=pra;
					pra=path2[i][pra];
				}
				top++;
				sPath[top]=i;  //加进起始顶点i
				
				if(dist2[i][j]!=MAX)
				{
					for(m=top;m>=0;m--)  //sPath[top]为指定的起始顶点
					{
						cout<<G.Data[sPath[m]]<<"  ";
					}
				}
				
				top=-1;
				cout<<endl;				
			}	
		}
	}
}

//拓扑排序
int topoList[MAXLEN];
void GetInDegrees(Graph &G, int inds[])
{
	EdgeNode *p; 
	int i;
	int k;
	for(i=1;i<=G.VerNum;i++)
	{
		p=G.VerList[i].firstEdge;
		while(p)
		{
			k=p->adjVer;
			inds[k]++;  //编号为k的顶点入度加1
			p=p->next;
		}
	}
}

int TopologicalSortS(Graph &G, int topoList[])
{
	int inds[MaxVerNum];  //保存图中各个顶点的入度
	linkedstack * top; //定义栈，保存入度为0的顶点
	int i;
	int v;  //保存顶点编号
	int vCount=0;  //记录入度为0的顶点数
	EdgeNode *p;   //边链表结点指针

	initialStack(top);  //初始化栈

	//初始化
	for(i=1;i<=G.VerNum;i++)
	{
		inds[i]=0;       //每个顶点入度初始化为0
		topoList[i]=-1;  //拓扑序列初始化为-1
	}
	//从邻接表读取顶点的初始入度
	GetInDegrees(G,inds);
	//入度为0的顶点编号入栈
	for(i=1;i<=G.VerNum;i++)
	{
		if(inds[i]==0)
			pushStack(top,i);
	}

	while(!stackEmpty(top))  //一次弹出入度为0的顶点，其邻接点入度减1
	{
		gettop(top,v);
		popStack(top);//弹出一个入度0顶点到v
		topoList[vCount+1]=v;  //顶点v存入拓扑序列
		vCount++;  //入度为0顶点数加1

		//与v邻接的顶点入度减1
		p=G.VerList[v].firstEdge;
		while(p)
		{
			v=p->adjVer;  //依次取出邻接点
			inds[v]--;
			if(inds[v]==0)  //如果入度减1后变为0，顶点v入栈
				pushStack(top,v);
			p=p->next;
		}
	}

	if(vCount==G.VerNum)
		return 1;  //拓扑排序成功
	else
		return 0;  //存在回路，拓扑排序失败。
}

/*void KeyPath(Graph &G, int topoList[])
{
	int i,j;
	int vPre;//保存顶点的前驱结点
	int vSuc;//保存顶点的后继结点
	int vet[MAXLEN];
	int vlt[MAXLEN];
	EdgeNode *p;
	for(i=1;i<=G.VerNum;i++)
		vet[i]=0;
	for(i=1;i<=G.VerNum;i++)
	{
		vPre=topList[i];
			p=G.VerList[vPre].firstEdge;
			while(p)
			{
				if(p->eInfo+vet[vPre]>vet[p->adjVer])
				{
					vet[p->adjVer]=p->eInfo+vet[vPre];
				}
				p=p->next;
			}
		}
	}
	for(i=1;i<=G.VerNum;i++)
	{

	}

}
*/
int FirstAdj(Graph1 &G,int v)
{
	int i;
	for(i=1;i<=G.VerNum;i++)
	{
		if(G.AdjMatrix[v][i]!=MAX&&!visited[i])
			return i;
	}
	return -1;
}
int NextAdj(Graph1 &G,int v,int w)
{
	int i;
	for(i=w+1;i<=G.VerNum;i++)
	{
		if(G.AdjMatrix[v][i]!=MAX&&!visited[i])
			return i;
	}
	return -1;
}
void PrintKeyPath(Graph1 &G,int topoList[],int vet[MAXLEN],int vlt[MAXLEN])
{
	int v,w;
	cout<<"关键路径:  ";
	v=topoList[1];
	for(int i=1;i<=G.VerNum;i++)
		visited[i]=0;
	cout<<G.Data[v]<<"  ";
	while(v!=-1)
	{
		w=FirstAdj(G,v); //搜索v的第一个邻接点
		while(w!=-1)
		{
			if(vet[w]==vlt[w]) //输出关键活动关联的顶点
			{
				cout<<G.Data[w]<<"  ";
				visited[w]=1;
				break;
			}
			else
				w=NextAdj(G,v,w); //搜索下一个邻接点
		}
		v=w;
	}
}
void KeyPath(Graph1 &G, int topoList[])
{
	int i,j;
	int vPre;//保存顶点的前驱结点
	int vSuc;//保存顶点的后继结点
	int vet[MAXLEN];
	int vlt[MAXLEN];
	for(i=1;i<=G.VerNum;i++)
		vet[i]=0;
	for(i=1;i<=G.VerNum;i++)
	{
		vPre=topoList[i];
		for(j=1;j<=G.VerNum;j++)
		{ //vPre与j 相邻
		if(G.AdjMatrix[vPre][j]>=1 && G.AdjMatrix[vPre][j]<MAX)
		if( vet[j]<vet[vPre]+G.AdjMatrix[vPre][j] )
			vet[j]=vet[vPre]+G.AdjMatrix[vPre][j];
		}
	}
	for(i=1;i<=G.VerNum;i++)
		vlt[i]=vet[G.VerNum];
	for(i=G.VerNum; i>=1; i--)
	{
			vSuc=topoList[i];
		for(j=G.VerNum;j>=1;j--)
		{ 

			if(G.AdjMatrix[j][vSuc]>=1 && G.AdjMatrix[j][vSuc]<MAX) 
				if( vlt[j]>vlt[vSuc]-G.AdjMatrix[j][vSuc] )
				vlt[j]=vlt[vSuc]-G.AdjMatrix[j][vSuc];
		}
	}
	PrintKeyPath(G,topoList,vet,vlt);
}
