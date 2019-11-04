#include<iostream>
#include<graphics.h>
#include<string.h>
#include<math.h>
#include<conio.h>
using namespace std;
typedef int elementType;

typedef struct node
{
	elementType data;
	struct node *lchild;
	struct node *rchild;
}Bnode;

void destroy(Bnode *&p)
{
	if(p)
	{
		destroy(p->lchild);
		destroy(p->rchild); 
		delete p;
		p=NULL;
	}
}
void creat(Bnode *&T,int A[],int i,const int n)
{
	if(i<n)
	{
		T=new Bnode;
		T->data=A[i];
		T->rchild=NULL;
		T->lchild=NULL;
		creat(T->rchild,A,2*i+1,n);
		creat(T->lchild,A,2*i,n);
	}
}
int TreeHeight(Bnode *T)
{
	int m,n;
	if(!T)
	{
		return 0;
	}
	else
	{
		m=TreeHeight(T->lchild);
		n=TreeHeight(T->rchild);
		return (m>n?m:n)+1;
	}
}

void graph(Bnode *T, Bnode *T1, int first, int floor,int rate, double x, double  y, double  x1, double  y1)
{
	char s[5];
	if (T1)
	{
		floor++;
		int r = 20;
		if (first == 1)
		{
			fillcircle(x, y, r);
			settextstyle(r, r, _T("ËÎÌו"));
			sprintf(s,"%d",T->data);
			outtextxy(x-r/2, y-r/2, s);
			first = 0;
		}
		else
		{
			line(x, y, x1, y1);
			fillcircle(x, y, r);
			fillcircle(x1, y1, r);
			//outtextxy(x - r / 2, y - r / 2, T->data);	
			//outtextxy(x1 - r / 2, y1 - r / 2, T1->data);
			sprintf(s,"%d",T->data);
			outtextxy(x-r/2, y-r/2, s);
			sprintf(s,"%d",T1->data);
			outtextxy(x1-r/2, y1-r/2, s);
		}
		graph(T1,T1->lchild, first, floor,rate, x1, y1, x1 - 550 / pow(2, floor), y1 + 150 * floor/rate);
		graph(T1,T1->rchild, first, floor,rate, x1, y1, x1 + 550 / pow(2, floor), y1 + 150 * floor/rate);
	}
}
void Tree(Bnode *T)
{
	initgraph(1200, 500);
	setorigin(600, 0);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	settextcolor(BLACK);
	int rate = TreeHeight(T);
	graph(T,T, 1, 0,rate, 0, 40, 0, 40);
	_getch();
	closegraph();

}
