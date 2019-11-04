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

	cout<<"�������:";
	PreOrderTraverse(pBT);
	cout<<endl;
	cout<<"�������:";
	InOrderTraverse(pBT);
	cout<<endl;
	cout<<"�������:";
	PostOrderTraverse(pBT);
	cout<<endl;

	cout<<"���ĸ߶�:"<<BiTreeDepth(pBT)<<endl;
	int num=0;
	BiTreeLeaves(pBT,num);
	cout<<"��Ҷ����Ŀ:"<<num<<endl;
	
	num=0;
	GetNodeNumber(pBT,num);
	cout<<"������Ŀ:"<<num<<endl;

	cout<<"�������ÿ�����Ĳ���:"<<endl;
	InTraverse(pBT,0);
}