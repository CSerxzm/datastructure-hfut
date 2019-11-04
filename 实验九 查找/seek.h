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
void show(Bnode *p)
{
	if(p)
	{
		show(p->lchild);
		cout<<p->data<<" ";
		show(p->rchild);
	}
}
int bin_search(elementType A[],int n,elementType x)
{
	int mid,low=0,high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(A[mid]==x)
			return mid;
		else if(A[mid]>x)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

void insert(Bnode **T,Bnode *S)
{
	if(*T==NULL)
		*T=S;
	else if(S->data<(*T)->data)
		insert(&((*T)->lchild),S);
	else
		insert(&((*T)->rchild),S);
}

void creat_bst(Bnode **T,elementType x)
{
	Bnode *p;
	p=new Bnode;
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	insert(&(*T),p);
}

Bnode * bst_search(Bnode *T,elementType x)
{
	Bnode *p=T;
	while(p!=NULL)
	{
		if(x==p->data)
			return p;
		else if(x<p->data)
			p=p->lchild;
		else
			p=p->rchild;
	}
	return p;
}

void delete_node(Bnode *&T,elementType x)
{
	Bnode *p,*sf,*s;
	p=bst_search(T,x);
	if(p->lchild||p->rchild)
	{
		sf=p;
		s=p->lchild;
		while(s->rchild)
		{
			sf=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(sf==p)
			sf->lchild=s->lchild;
		else
			sf->rchild=s->lchild;
		delete s;
	}
	else
	{
		s=T;
		while(s)
		{
			if(x==s->data)
				break;
			else if(x<s->data)
			{
				sf=s;
				s=s->lchild;
			}
			else
			{
				sf=s;
				s=s->rchild;
			}
		}
		if(sf->rchild==p)
			sf->rchild=NULL;
		if(sf->lchild==p)
			sf->lchild=NULL;
		delete p;
	}
}
///////////////////////////////////////////////////////
//                    AVL树                          //
///////////////////////////////////////////////////////
typedef struct Node
{
	int data;
	struct Node *lchild,*rchild;
	int bf;
}AVLTNode,*AVLTree;

void RR(AVLTree &t,AVLTNode *FA,AVLTNode *A)
{
	AVLTNode *B;
	B=A->rchild;
	A->rchild=B->lchild;
	B->lchild=A;
	A->bf=0;
	B->bf=0;
	if(FA==NULL)
		t=B;
	else if(A==FA->lchild)
		FA->lchild=B;
	else
		FA->rchild=B;
}
void LL(AVLTree &t,AVLTNode *FA,AVLTNode *A)
{
	AVLTNode *B;
	B=A->lchild;
	A->lchild=B->rchild;
	B->rchild=A;
	A->bf=0;
	B->bf=0;
	if(FA==NULL)
		t=B;
	else if(A==FA->lchild)
		FA->lchild=B;
	else
		FA->rchild=B;
}
void LR(AVLTree &t,AVLTNode *FA,AVLTNode *A,AVLTNode *S)
{
	AVLTNode *B,*C;
	B=A->lchild;
	C=B->rchild;
	B->rchild=C->lchild;
	A->lchild=C->rchild;
	C->lchild=B;
	C->rchild=A;
	if(S->data<C->data)
	{
		A->bf=-1;
		B->bf=0;
		C->bf=0;
	}
	else if(S->data>C->data)
	{
		A->bf=0;
		B->bf=1;
		C->bf=0;
	}
	else
	{
		A->bf=0;
		B->bf=0;
	}
	if(FA==NULL)
		t=C;
	else if(A==FA->lchild)
		FA->lchild=C;
	else
		FA->rchild=C;
}
void RL(AVLTree &t,AVLTNode *FA,AVLTNode *A,AVLTNode *S)
{
	AVLTNode *B,*C;
	B=A->rchild;
	C=B->lchild;
	B->lchild=C->rchild;
	A->rchild=C->lchild;
	C->lchild=A;
	C->rchild=B;
	if(S->data<C->data)
	{
		A->bf=0;
		B->bf=-1;
		C->bf=0;
	}
	else if(S->data>C->data)
	{
		A->bf=1;
		B->bf=0;
		C->bf=0;
	}
	else
	{
		A->bf=0;
		B->bf=0;
	}
	if(FA==NULL)
		t=C;
	else if(A==FA->lchild)
		FA->lchild=C;
	else
		FA->rchild=C;
}
void ins_AVLtree(AVLTree &avlt,int k)
{
	AVLTNode *S=new AVLTNode;
	S->data=k;
	S->lchild=NULL;
	S->rchild=NULL;
	S->bf=0;
	if(!avlt)
		avlt=S;
	else
	{
		AVLTNode *A,*B,*fA,*p,*fp;
		A=avlt;
		fA=NULL;
		p=avlt;
		fp=NULL;
		while(p!=NULL)
		{
			if(p->bf!=0)
			{
				A=p;
				fA=fp;
			}
			fp=p;
			if(k<p->data)
				p=p->lchild;
			else
				p=p->rchild;
		}
		if(k<fp->data)
			fp->lchild=S;
		else
			fp->rchild=S;
		if(k<A->data)
		{
			B=A->lchild;
			A->bf++;
		}
		else
		{
			B=A->rchild;
			A->bf--;
		}
		p=B;
		while(p!=S)
		{
			if(k<p->data)
			{
				p->bf=1;
				p=p->lchild;
			}
			else
			{
				p->bf=-1;
				p=p->rchild;
			}
		}
		if(A->bf==-2&&B->bf==-1)
			RR(avlt,fA,A);
		else if(A->bf==2&&B->bf==1)
			LL(avlt,fA,A);
		else if(A->bf==2&&B->bf==-1)
			LR(avlt,fA,A,S);
		else if(A->bf==-2&&B->bf==1)
			RL(avlt,fA,A,S);
	}
}
void initialize()
{
	cout<<"(1) 对下列数据表，分别采用二分查找算法实现查找，给出查找过程依次所比较的元素（的下标），并以二分查找的判定树来解释。"<<endl;
	cout<<"(2)设计出在二叉排序树中插入结点的算法，在此基础上实现构建二叉排序树的算法。"<<endl;
	cout<<"(3) 设计算法在二叉排序树中查找指定值的结点。"<<endl;
	cout<<"(4) 设计算法在二叉排序树中删除特定值的结点。"<<endl;
	cout<<"(5) 已知整型数组A[1..26]递增有序，设计算法以构造一棵平衡的二叉排序树来存放该数组中的所有元素。"<<endl;
}

void show(AVLTNode *T)
{
	if(T)
	{
		show(T->lchild);
		cout<<T->data<<" ";
		show(T->rchild);
	}

}

int TreeHeight(AVLTNode *T)
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

void graph(AVLTNode *T, AVLTNode *T1, int first, int floor,int rate, double x, double  y, double  x1, double  y1)
{
	char s[5];
	if (T1)
	{
		floor++;
		int r = 20;
		if (first == 1)
		{
			fillcircle(x, y, r);
			settextstyle(r, r, _T("宋体"));
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
void Tree(AVLTNode *T)
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
