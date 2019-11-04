#include "picture.h"

int main()
{
	Graph G;//�ڽӱ��ʾ��
	Graph1 G1;//�ڽӾ����ʾ��
	CreateGraphFromFile("Udn6.grp",G);
	//printGraph(G);

	cout<<"��ȱ���:";
	DFStravel(G,1);
	cout<<"\n��ȱ���:";
	BFS(G,1);

	cout<<"\n(����)����ͼ�ߵ���Ŀ: "<<Edgenum(G);

	cout<<"\n prim  �㷨: ";
	prim(G,1);

	cout<<"\nKruskal�㷨: ";
	Kruskal(G);
	cout<<endl;
	int i=1;
	cout<<"Dijkstra�㷨:"<<endl;
	Dijkstra(G, path, dist, i);
	PrintDijkstra(G, path, dist, i);
	cout<<endl;

	cout<<"Floyd�㷨:\n";
	transform(G,G1);
	Floyd(G1, dist2, path2);
	PrintFloyd(G1, dist2, path2);

	CreateGraphFromFile("kPath91.grp",G);
	transform(G,G1);

	cout<<"\n��������\n";
	if(TopologicalSortS(G,topoList))
	{
		for(i=1;i<G.VerNum;i++)
			cout<<G.VerList[topoList[i]].data<<" ";
	}
	else
		cout<<"δ�ҵ����Ϊ0�Ķ���.";

	cout<<"\n\nAOE";
	KeyPath(G1,topoList);

	cout<<"\n"<<endl;
	return 0;
}