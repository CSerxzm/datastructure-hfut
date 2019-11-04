#include "picture.h"

int main()
{
	Graph G;//邻接表表示法
	Graph1 G1;//邻接矩阵表示法
	CreateGraphFromFile("Udn6.grp",G);
	//printGraph(G);

	cout<<"深度遍历:";
	DFStravel(G,1);
	cout<<"\n广度遍历:";
	BFS(G,1);

	cout<<"\n(有向)无向图边的数目: "<<Edgenum(G);

	cout<<"\n prim  算法: ";
	prim(G,1);

	cout<<"\nKruskal算法: ";
	Kruskal(G);
	cout<<endl;
	int i=1;
	cout<<"Dijkstra算法:"<<endl;
	Dijkstra(G, path, dist, i);
	PrintDijkstra(G, path, dist, i);
	cout<<endl;

	cout<<"Floyd算法:\n";
	transform(G,G1);
	Floyd(G1, dist2, path2);
	PrintFloyd(G1, dist2, path2);

	CreateGraphFromFile("kPath91.grp",G);
	transform(G,G1);

	cout<<"\n拓扑排序\n";
	if(TopologicalSortS(G,topoList))
	{
		for(i=1;i<G.VerNum;i++)
			cout<<G.VerList[topoList[i]].data<<" ";
	}
	else
		cout<<"未找到入度为0的顶点.";

	cout<<"\n\nAOE";
	KeyPath(G1,topoList);

	cout<<"\n"<<endl;
	return 0;
}