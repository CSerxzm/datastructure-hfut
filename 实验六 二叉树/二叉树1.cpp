#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include "biTree.h"
using namespace std;

void graph(BiNode *T, BiNode *T1, int first, int floor,int rate, double x, double  y, double  x1, double  y1)
{
	if (T1)
	{
		floor++;
		//int r = 80 / rate;
		int r = 20;
		if (first == 1)
		{
			fillcircle(x, y, r);
			settextstyle(r, r*4/5, _T("����"));
			outtextxy(x-r/2, y-r/2, T->data);
			first = 0;
		}
		else
		{
			line(x, y, x1, y1);
			fillcircle(x, y, r);
			fillcircle(x1, y1, r);
			outtextxy(x - r / 2, y - r / 2, T->data);	
			outtextxy(x1 - r / 2, y1 - r / 2, T1->data);
		}
		graph(T1,T1->lchild, first, floor,rate, x1, y1, x1 - 500 / pow(2, floor), y1 + 200 * floor/rate);
		graph(T1,T1->rchild, first, floor,rate, x1, y1, x1 + 500 / pow(2, floor), y1 + 200 * floor/rate);
	}
}
void Tree(BiNode *T)
{
	char n;
	initgraph(1200, 800);
	setorigin(600, 0);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(RGB(7, 190, 234));
	setlinecolor(BLACK);
	settextcolor(BLACK);
	int rate = BiTreeDepth(T);
	graph(T,T, 1, 0,rate, 0, 40, 0, 40);
	_getch();
	closegraph();
}

int main()
{
	char strLine[100][3];
	int nArrLen=0,nLen,nRow=0;
	char a[16]={' ','A','B','C','D','E','/','G','/','/','J','K','/','/','N','O'};//�̲�P122
	BiNode *pBT,*p,*R;
	char s[10],c;
	//cout<<"ѡ��ʵ������(bt8,bt9,bt14,bt21,bt26,bt31,bt151,bt261):";
	//cin>>s;
	if(ReadFileToArray("bt8.btr",strLine,nArrLen))
	{
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

		cout<<"����Ϊż���Ľ��:";
		DoubleBiNode(pBT);

		cout<<"\n�������ÿ�����Ĳ���:"<<endl;
		InTraverse(pBT,0);

		cout<<"\n������ҽ���ֵ:";
		cin>>c;
		RelationBiNode(pBT,c);

		num=0;
		cout<<"\n������ҽ���ֵ:";
		cin>>c;
		FindBiNode(pBT,num,c);

		SwapSubTree(pBT);
		cout<<"����������������:";
		PreOrderTraverse(pBT);
		SwapSubTree(pBT);

		ArrayToBiTree(p,a,1,16);
		cout<<"\n"<<"�̲�p122����ת��Ϊ��������,�������:";
		PreOrderTraverse(p);
		cout<<endl;

		BiTreecopy(pBT,R);
		cout<<"\n"<<"��pBT����Ϊ������R,�������:";
		PreOrderTraverse(R);
		
		cout<<"\n������ҽ��:";
		cin>>c;
		cout<<"\n�������:";
		BiTreeSearch(pBT,c);

		cout<<endl;
		arrangementPrint(pBT);

		Tree(pBT);

		seqstack S;
		initialStack(S);
		BiTree(pBT,S);
	}
}