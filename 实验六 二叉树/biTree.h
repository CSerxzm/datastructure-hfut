#include "seqstack.h"
#include "seqQueue.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

//stack <TriTree> Stack;
bool ReadFileToArray(char fileName[],char strLine[100][3],int &nArrLen)
{
	FILE *fp;
	char str[1000];
	fp=fopen(fileName,"r");
	if(!fp)
	{
		cout<<"打开文件失败."<<endl;
		return false;
	}
	
	if(fgets(str,1000,fp)!=NULL)
	{
		if(strcmp(str,"BinaryTree\n")!=0)
		{
			cout<<"格式错误."<<endl;
			fclose(fp);
			return false;
		}
	}
	nArrLen=0;
	while(fscanf(fp,"%c %c %c\n",&strLine[nArrLen][0],&strLine[nArrLen][1],&strLine[nArrLen][2])!=EOF)
	{
		nArrLen++;
	}
	fclose(fp);
	return true;
}

bool CreateBiTreeFromFile(BiNode *&pBT,char strLine[100][3],int nLen,int &nRow)
{
	if( (nRow>=nLen) || (nLen==0) )
		return false;
	pBT = new BiNode;
	pBT->data=strLine[nRow][0];
	pBT->lchild = NULL;
	pBT->rchild = NULL;
	
	int nRowNext = nRow;
	if(strLine[nRowNext][1]=='1')
	{
		nRow++;
		CreateBiTreeFromFile(pBT->lchild,strLine,nLen,nRow);
	}
	if(strLine[nRowNext][2]=='1')
	{
		nRow++;
		CreateBiTreeFromFile(pBT->rchild,strLine,nLen,nRow);
	}
	return true;

}

void DestroyBiTree(BiNode *pBT)
{
	if(pBT)
	{
		DestroyBiTree(pBT->lchild);
		DestroyBiTree(pBT->rchild);
		delete pBT;
	}
}

void InTraverse(BiNode *T)
{
	if(T)
	{
		InTraverse(T->lchild);
		cout<<T->data<<" "; 
		InTraverse(T->rchild);		
	}
}

void PreOrderTraverse(BiNode *T)
{
	if(T)
	{
		cout<<T->data<<" ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);		
	}
}

void InOrderTraverse(BiNode *T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data<<" "; 
		InOrderTraverse(T->rchild);		
	}
}

void PostOrderTraverse(BiNode *T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data<<" "; 		
	}
}

void GetNodeNumber(BiNode *T,int &num)
{
	if(T)
	{
		GetNodeNumber(T->lchild,num);
		num++;
		GetNodeNumber(T->rchild,num);
	}
}

int BiTreeDepth(BiNode *T)
{
	int m,n;
	if(!T)
		return 0;
	else
	{
		m=BiTreeDepth(T->lchild);
		n=BiTreeDepth(T->rchild);
		return (m>n ? m:n)+1;
	}
}

void BiTreeLeaves(BiNode *T,int &num)
{
	if(!T->lchild&&!T->rchild)
		num++;
	if(T->lchild)
		BiTreeLeaves(T->lchild,num);
	if(T->rchild)
		BiTreeLeaves(T->rchild,num);
}

void InTraverse(BiNode *T,int num)
{
	if(T)
	{
		num++;
		InTraverse(T->lchild,num);
		cout<<T->data<<" "<<num<<"\t"; 
		InTraverse(T->rchild,num);		
	}
}

void DoubleBiNode(BiNode *T)
{
	if(T)
	{
		DoubleBiNode(T->lchild);
		if(T->rchild&&T->lchild)
			cout<<T->data<<" ";
		DoubleBiNode(T->rchild);
	}
}

void RelationBiNode(BiNode *T,elementType x)
{
	BiNode *p;
	p=T;
	if(p)
	{
		if((p->rchild&&p->rchild->data==x)||(p->lchild&&p->lchild->data==x))
		{
				if(p->lchild&&p->lchild->data==x)
				{
					cout<<"父结点:"<<p->data<<endl;
					cout<<"左兄弟结点:"<<p->lchild->data;
					if(p->lchild->lchild)
						cout<<"左孩子:"<<p->lchild->lchild->data<<endl;
					if(p->lchild->rchild)
						cout<<"右孩子:"<<p->lchild->rchild->data<<endl;
				}
				if(p->rchild&&p->rchild->data==x)
				{
					cout<<"父结点:"<<p->data<<endl;
					cout<<"右兄弟结点:"<<p->rchild->data;
					if(p->rchild->lchild)
						cout<<"左孩子:"<<p->rchild->lchild->data<<endl;
					if(p->rchild->rchild)
						cout<<"右孩子:"<<p->rchild->rchild->data<<endl;
				}
		}
		else
		{
			RelationBiNode(p->lchild,x);
			RelationBiNode(p->rchild,x);
		}
	}
}

void FindBiNode(BiNode *T,int num,char x)
{
	if(T)
	{
		num++;
		FindBiNode(T->lchild,num,x);
		if(T->data==x)
			cout<<"查找结点"<<x<<"的层次:"<<num<<endl;

		FindBiNode(T->rchild,num,x);
			
	}
}

void SwapSubTree(BiNode *T)
{
	BiNode *Temp;
	if(T)
	{
		SwapSubTree(T->lchild);
		SwapSubTree(T->rchild);
		Temp=T->lchild;
		T->lchild=T->rchild;
		T->rchild=Temp;
	}
}

void ArrayToBiTree(BiNode *&T,char a[30],const int i,const int n)
{
	if(i<n&&a[i]!='/')
	{
		T=new BiNode;
		T->data=a[i];
		T->lchild=NULL;
		T->rchild=NULL;
		ArrayToBiTree(T->lchild,a,2*i,n);
		ArrayToBiTree(T->rchild,a,2*i+1,n);
	}
}

void BiTreecopy(BiNode *T,BiNode *&R)
{
	BiNode *rchild,*lchild;
	if(!T)
		R=NULL;
	else
	{
		R=new BiNode;
		R->data=T->data;
		BiTreecopy(T->rchild,rchild);
		BiTreecopy(T->lchild,lchild);
		R->rchild=rchild;
		R->lchild=lchild;	
	}
}

void BiTreeSearch(BiNode *pBT,elementType x)
{
	BiNode *p;
	int tag[100];
	seqstack S;
	initialStack(S);
	p=pBT;
	while(p||!stackEmpty(S))
	{
		if(p)
		{
			pushStack(S,p);
			tag[S.top]=0;
			if(p->data==x)
			{
				while(!stackEmpty(S))
				{
					popStack(S,p);
					cout<<p->data<<" ";
				}
				break;
			}
			else
				p=p->lchild;
		}
		else
		{
			topStack(S,p);
			if(tag[S.top]==0)
			{
				tag[S.top]=1;
				p=p->rchild;
			}
			else
			{
				popStack(S,p);
				p=NULL;
			}
		}
	}
}
void arrangementPrint(BiNode *pBT)
{
	queue Q;
	initialQueue(&Q);
	BiNode *p=pBT;
	if(p)
	{
		cout<<"二叉树按层次打印:";
		cout<<p->data<<" ";
		enQueue(&Q,p);
		while(!queueEmpty(&Q))
		{
			queueFront(&Q,p);
			outQueue(&Q);
			if(p->lchild)
			{
				cout<<p->lchild->data<<" ";
				enQueue(&Q,p->lchild);
			}
			if(p->rchild)
			{
				cout<<p->rchild->data<<" ";
				enQueue(&Q,p->rchild);
			}
		}
		cout<<endl;
	}
	else
		cout<<"树为空."<<endl;
}
void createSubTree(BiNode *q,int k)
{
	BiNode *u;
	elementType x;
	cin>>x;
	if(x!='/')
	{
		u = new BiNode;
		u->data=x;
		u->lchild=NULL;
		u->rchild=NULL;
		if(k==1)
			q->lchild=u;
		if(k==2)
			q->rchild=u;
		createSubTree(u,1);
		createSubTree(u,2);
	}
}

void createBiTree(BiNode *&BT)
{
	BiNode *p;
	char x;
	cout<<"按照先序输入二叉树(/表示没有子树):";
	cin>>x;
	if(x=='/')
		return ;
	BT=new BiNode;
	BT->data=x;
	BT->lchild=NULL;
	BT->rchild=NULL;
	p=BT;
	createSubTree(p,1);
	createSubTree(p,2);
}

void showseqstack(seqstack S)
{
	int i=0;
	for(;i<=S.top;i++)
		cout<<S.data[i]->data<<" ";
	cout<<endl;
}


void BiTree(BiNode *T,seqstack S)
{
	if(T)
	{
		pushStack(S,T);
		BiTree(T->lchild,S);
		BiTree(T->rchild,S);
		showseqstack(S);
	}
}
