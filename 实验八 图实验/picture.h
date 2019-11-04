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
//���������
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
//���������
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

//�����㷨
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
					while(p)//�ҳ��ٽֱ���Сֵ
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
//Kruskal�㷨
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

//Dijkstra�㷨
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
			cout<<" �޿ɴ�·����"<<endl;
		else
		{
			cout<<"��̾���:"<<dist[i];
			cout<<" ·��:";
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
//floy�㷨
cellType dist2[MAXLEN][MAXLEN];
int path2[MAXLEN][MAXLEN];
typedef struct GraphAdjMatrix
{
	elementType Data[MAXLEN+1];                 //�������飬��Ŷ���Ԫ�ص�ֵ��Data[0]��Ԫ����
	cellType AdjMatrix[MAXLEN+1][MAXLEN+1];  //�ڽӾ��������±�Ϊ0��Ԫ���ã���AdjMatrix[1][1]��Ԫ��ʼ
	int VerNum;       //������
	int ArcNum;       //�����ߣ���
	GraphKind gKind;  //ͼ������:0-����ͼ��1-��������2-����ͼ��3-������
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
	//��ʼ����������·������
	for(i=1;i<=G.VerNum;i++)
	{
		for(j=1;j<=G.VerNum;j++)
		{
			dist2[i][j]=G.AdjMatrix[i][j];   //��������ʼ��Ϊ�ڽӾ���
			                                        //��ʼ��·������·������Ԫ��path[i][j]�б�����j�����ǰ���Ķ�����
            if( i!=j && G.AdjMatrix[i][j]<MAX)  //���i,j֮����ڱߣ���j��ǰ��Ϊi������ǰ����Ϊ-1
				path2[i][j]=i;
			else
				path2[i][j]=-1;													
		}
	}

	//��k=1��ʼ��������k=G.verNum������ѡ��һ������k����Ϊ����i��j֮�����ת���㣬�Ż�����i��j֮��ľ���
	//������Floyd�㷨�ĺ���--����forѭ��
	for(k=1; k<=G.VerNum; k++)
	{
		for(i=1; i<=G.VerNum; i++)
		{
			for(j=1; j<=G.VerNum;j++)
			{
				if(i!=j && dist2[i][k]+dist2[k][j]<dist2[i][j])  //k��Ϊ��ת���㣬i��j֮������С������k��Ϊ��ת�㣬����i��j֮��ľ���
				{
					dist2[i][j]=dist2[i][k]+dist2[k][j];  //���¾���
					path2[i][j]=path2[k][j];  //�޸�ǰ������					
				}
			}	
		}
	}
}

//��ӡFloyd�㷨���������·��
void PrintFloyd(Graph1 &G, cellType dist2[MAXLEN][MAXLEN], int path2[MAXLEN][MAXLEN])
{
	int sPath[MAX];  //����һ������ջ����������
	int pra;  //ǰ�������
	int top=-1;  //ջ��
	int i;

	int j;
	int m;

	for(i=1; i<=G.VerNum; i++)
	{		
		for(j=1; j<=G.VerNum; j++)
		{
			cout<<G.Data[i]<<" to "<<G.Data[j];
			if(dist2[i][j]==MAX)
				cout<<" �޿ɴ�·����"<<endl;
			else
			{
				cout<<" ��̾���:"<<dist2[i][j];
				cout<<" ·��:";

				top++;
				sPath[top]=j;   //sPath[0]Ϊ��ǰ����i
				pra=path2[i][j];  //i�����ǰ������
				while(pra!=i)
				{
					top++;
					sPath[top]=pra;
					pra=path2[i][pra];
				}
				top++;
				sPath[top]=i;  //�ӽ���ʼ����i
				
				if(dist2[i][j]!=MAX)
				{
					for(m=top;m>=0;m--)  //sPath[top]Ϊָ������ʼ����
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

//��������
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
			inds[k]++;  //���Ϊk�Ķ�����ȼ�1
			p=p->next;
		}
	}
}

int TopologicalSortS(Graph &G, int topoList[])
{
	int inds[MaxVerNum];  //����ͼ�и�����������
	linkedstack * top; //����ջ���������Ϊ0�Ķ���
	int i;
	int v;  //���涥����
	int vCount=0;  //��¼���Ϊ0�Ķ�����
	EdgeNode *p;   //��������ָ��

	initialStack(top);  //��ʼ��ջ

	//��ʼ��
	for(i=1;i<=G.VerNum;i++)
	{
		inds[i]=0;       //ÿ��������ȳ�ʼ��Ϊ0
		topoList[i]=-1;  //�������г�ʼ��Ϊ-1
	}
	//���ڽӱ��ȡ����ĳ�ʼ���
	GetInDegrees(G,inds);
	//���Ϊ0�Ķ�������ջ
	for(i=1;i<=G.VerNum;i++)
	{
		if(inds[i]==0)
			pushStack(top,i);
	}

	while(!stackEmpty(top))  //һ�ε������Ϊ0�Ķ��㣬���ڽӵ���ȼ�1
	{
		gettop(top,v);
		popStack(top);//����һ�����0���㵽v
		topoList[vCount+1]=v;  //����v������������
		vCount++;  //���Ϊ0��������1

		//��v�ڽӵĶ�����ȼ�1
		p=G.VerList[v].firstEdge;
		while(p)
		{
			v=p->adjVer;  //����ȡ���ڽӵ�
			inds[v]--;
			if(inds[v]==0)  //�����ȼ�1���Ϊ0������v��ջ
				pushStack(top,v);
			p=p->next;
		}
	}

	if(vCount==G.VerNum)
		return 1;  //��������ɹ�
	else
		return 0;  //���ڻ�·����������ʧ�ܡ�
}

/*void KeyPath(Graph &G, int topoList[])
{
	int i,j;
	int vPre;//���涥���ǰ�����
	int vSuc;//���涥��ĺ�̽��
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
	cout<<"�ؼ�·��:  ";
	v=topoList[1];
	for(int i=1;i<=G.VerNum;i++)
		visited[i]=0;
	cout<<G.Data[v]<<"  ";
	while(v!=-1)
	{
		w=FirstAdj(G,v); //����v�ĵ�һ���ڽӵ�
		while(w!=-1)
		{
			if(vet[w]==vlt[w]) //����ؼ�������Ķ���
			{
				cout<<G.Data[w]<<"  ";
				visited[w]=1;
				break;
			}
			else
				w=NextAdj(G,v,w); //������һ���ڽӵ�
		}
		v=w;
	}
}
void KeyPath(Graph1 &G, int topoList[])
{
	int i,j;
	int vPre;//���涥���ǰ�����
	int vSuc;//���涥��ĺ�̽��
	int vet[MAXLEN];
	int vlt[MAXLEN];
	for(i=1;i<=G.VerNum;i++)
		vet[i]=0;
	for(i=1;i<=G.VerNum;i++)
	{
		vPre=topoList[i];
		for(j=1;j<=G.VerNum;j++)
		{ //vPre��j ����
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
