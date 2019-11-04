#include <iostream>
#include "seqQueue.h"
#include "createTree.h"
using namespace std;

void PreOrderTraverse(csNode *T)
{
	if(T)
	{
		cout<<T->data<<" "; 
		PreOrderTraverse(T->firstChild);
		PreOrderTraverse(T->nextSibling);			
	}
}

void InOrderTraverse(csNode *T)
{
	if(T)
	{
		InOrderTraverse(T->firstChild);
		cout<<T->data<<" "; 
		InOrderTraverse(T->nextSibling);		
	}
}

void cengci(csNode *T)
{
	queue Q;
	int i=0;
	initialQueue(&Q);
	csNode *p=T;
	if(p)
	{
		while(i==0||!queueEmpty(&Q))
		{	
			i=1;
			if(p)
			{
				cout<<p->data<<" ";
				enQueue(&Q,p);
				p=p->nextSibling;
			}
			else
			{
				queueFront(&Q,p);
				p=p->firstChild;
				outQueue(&Q);
			}
		}
	}
}
void PostOrderTraverse(csNode *T)
{
	if(T)
	{
		PostOrderTraverse(T->firstChild);
		PostOrderTraverse(T->nextSibling);
		cout<<T->data<<" "; 
	}
}


int Forestheight(csNode *T)
{
	int m,n;
	if(!T)
			return 0;
	m=Forestheight(T->firstChild);
	n=Forestheight(T->nextSibling);
	return (m+1)>n?(m+1):n;
}

void ForestNumber(csNode *T,int &num)
{
	if(T)
	{
		num++;
		ForestNumber(T->firstChild,num);
		ForestNumber(T->nextSibling,num);
	}
}

void ForestLeaves(csNode *T,int &num)
{
	if(T&&!T->firstChild)
	{
		num++;
		ForestLeaves(T->nextSibling,num);
	}
	else if(T)
	{
		ForestLeaves(T->firstChild,num);
		ForestLeaves(T->nextSibling,num);
	}
}

/*void  ForestInOrder(csNode *T,int num)
{
	csNode *p;
	if(T)
	{
		num++;
		cout<<"("<<T->data<<","<<num<<")   ";
		p=T->nextSibling;
		while(p)
		{
			cout<<"("<<p->data<<","<<num<<")   ";
			ForestInOrder(p->firstChild,num);
			p=p->nextSibling;
		}
	}
	if(T&&T->firstChild)
		ForestInOrder(T->firstChild,num);
}
*/
int ForestDreege(csNode *T,int i)
{
	int num=0,m=0,n=0;
	csNode *p;
	p=T;
	if(p)
	{
		if(i==0)
			m=ForestDreege(T->nextSibling,0);
		while(p)
		{
			num++;
			p=p->nextSibling;
		}
		if(m>num)
			num=m;
		n=ForestDreege(T->firstChild,1);
		return (num>n)?num:n;
	}
}
void ForestInOrder(csNode *T,int num,int i)
{
	csNode *p;
	if(T)
	{
		if(i==0)
			num++;
		cout<<"("<<T->data<<","<<num<<") ";
		ForestInOrder(T->firstChild,num,0);
		ForestInOrder(T->nextSibling,num,1);
	}
	
}

void showForest(csNode *T)
{
	if(T)
	{
		cout<<T->data;
		if(T->firstChild)
		{
			cout<<"(";
			showForest(T->firstChild);
		}
		if(T->nextSibling)
		{
			cout<<",";
			showForest(T->nextSibling);
		}
		else
			cout<<")";
	}
}
