#include <iostream>
#include "forest.h"
using namespace std;

int main()
{
	pTree T;
	int num=0;
	csNode *pforest;
	char fileName[10];

	cout<<"请输入文件:";
	scanf("%s",fileName);
	if(!CreateTreeFromFile(fileName,T))
	{
		exit(0);
	}
	createCsTree(pforest,T);

	cout<<"先序遍历:";
	PreOrderTraverse(pforest);
	cout<<endl;

	cout<<"中序遍历:";
	InOrderTraverse(pforest);
	cout<<endl;

	cout<<"后序遍历:";
	PostOrderTraverse(pforest);
	cout<<endl;

	cengci(pforest);
	cout<<endl;

	cout<<"树的高度:"<<Forestheight(pforest)<<endl;

	ForestNumber(pforest,num);
	cout<<"森林结点总数:"<<num<<endl;

	num=0;
	ForestLeaves(pforest,num);
	cout<<"森林叶子结点数:"<<num<<endl;

	cout<<"森林的度:";
	cout<<ForestDreege(pforest,0)<<endl;

	cout<<"先序输出结点值及其层次号";
	ForestInOrder(pforest,0,0);
	cout<<endl;

	cout<<"输出广义表表示的树:";
	showForest(pforest);
	cout<<endl;
	return 0;
}