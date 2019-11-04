#include <iostream>
#include "biTree.h"
using namespace std;

int main()
{
	char strLine[100][3];
	int nArrLen=0,nLen,nRow=0;
	BiNode *pBT;
	ReadFileToArray("bt21.txt",strLine,nArrLen);
	CreateBiTreeFromFile(pBT,strLine,nArrLen,nRow);

	cout<<"先序遍历:";
	PreOrderTraverse(pBT);
	cout<<endl;
	cout<<"中序遍历:";
	InOrderTraverse(pBT);
	cout<<endl;
	cout<<"后序遍历:";
	PostOrderTraverse(pBT);
	cout<<endl;

	cout<<"树的高度:"<<BiTreeDepth(pBT)<<endl;
	int num=0;
	BiTreeLeaves(pBT,num);
	cout<<"树叶的数目:"<<num<<endl;
	
	num=0;
	GetNodeNumber(pBT,num);
	cout<<"结点的数目:"<<num<<endl;

	cout<<"中序遍历每个结点的层数:"<<endl;
	InTraverse(pBT,0);
}