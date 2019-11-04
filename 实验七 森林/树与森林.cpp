#include <iostream>
#include "forest.h"
using namespace std;

int main()
{
	pTree T;
	int num=0;
	csNode *pforest;
	char fileName[10];

	cout<<"�������ļ�:";
	scanf("%s",fileName);
	if(!CreateTreeFromFile(fileName,T))
	{
		exit(0);
	}
	createCsTree(pforest,T);

	cout<<"�������:";
	PreOrderTraverse(pforest);
	cout<<endl;

	cout<<"�������:";
	InOrderTraverse(pforest);
	cout<<endl;

	cout<<"�������:";
	PostOrderTraverse(pforest);
	cout<<endl;

	cengci(pforest);
	cout<<endl;

	cout<<"���ĸ߶�:"<<Forestheight(pforest)<<endl;

	ForestNumber(pforest,num);
	cout<<"ɭ�ֽ������:"<<num<<endl;

	num=0;
	ForestLeaves(pforest,num);
	cout<<"ɭ��Ҷ�ӽ����:"<<num<<endl;

	cout<<"ɭ�ֵĶ�:";
	cout<<ForestDreege(pforest,0)<<endl;

	cout<<"����������ֵ�����κ�";
	ForestInOrder(pforest,0,0);
	cout<<endl;

	cout<<"���������ʾ����:";
	showForest(pforest);
	cout<<endl;
	return 0;
}