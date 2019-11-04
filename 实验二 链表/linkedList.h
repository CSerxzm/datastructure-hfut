#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct linkedList
{
	int data;
	linkedList *next;
}node;
void initialList(node ** L)
{
	(*L)=new node;
	(*L)->next=NULL;
}
void showList(node *L)
{
	node *p;
	p=L->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
//<1>尾插法
void creattailList(node *&L,int a[])
{
	node *R,*u;
	int x=0;
	R=L;
	while(a[x]!=-1)
	{
		u=new node;
		u->data=a[x];
		R->next=u;
		R=u;
		x++;
	}
	R->next=NULL;
}
//<2>头插法
void creatheadList(node *&L,int a[])
{
	node *R,*u;
	int x=0;
	R=L;
	while(a[x]!=-1)
	{
		u=new node;
		u->data=a[x];
		u->next=L->next;
		L->next=u;
		x++;
	}
}
//<3>销毁单链表
void destoryList(node *L)
{
	node *p,*u;
	p=L->next;
	while(p)
	{
		u=p->next;
		delete p;
		p=u;
	}
	L->next=NULL;
	cout<<"链表已经摧毁."<<endl;
}
//<4>求链表长度
void lenList(node *L)
{
	int len=0;
	node *p;
	p=L->next;
	while(p)
	{
		len++;
		p=p->next;
	}
	cout<<"链表长度:"<<len<<endl;
}
//<5>求单链表中第i个元素（函数），若不存在，报错。
void getelement(node *L,int i)
{
	int j=0;
	node *p;
	p=L->next;
	while(p)
	{
		j++;
		if(j==i)
		{	
			cout<<p->data<<endl;
			break;
		}
		p=p->next;
	}
	if(!p)
		cout<<"序号错误.";
}
//<6>在第i个结点前插入值为x的结点。
void insertList(node *L,int i,int x)
{
	int j=1;
	node *p,*q;
	p=L->next;
	while((i-1)!=j)
	{
		p=p->next;
		j++;
	}
	q=new node;
	q->data=x;
	q->next=p->next;
	p->next=q;
}
//<7>链表中查找元素值为x的结点，成功返回结点指针，失败报错。
node * getelementType(node *L,int x)
{
	node *p;
	p=L->next;
	while(p)
	{
		if(p->data==x)
			return p;
		else
			p=p->next;
	}
	return NULL;
}
//<8>删除单链表中第i个元素结点。
void deleteList(node *L,int i)
{
	int j=0;
	node *p,*q;
	p=L;
	while((i-1)!=j)
	{
		p=p->next;
		j++;
	}
	q=p->next;
	p->next=q->next;
	delete q;
}
//<9>在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。
void insertList(node *L,int x)
{
	node *p,*q;
	p=L;
	while(p->next->data<x)
	{
		p=p->next;
	}
	q=new node;
	q->data=x;
	q->next=p->next;
	p->next=q;
}
//<10>将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的单链表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。
void separateList(node *L)
{
	node *q,*p1,*p2,*p;
	node *L1,*L2;
	initialList(&L1);
	initialList(&L2);
	p1=L1;
	p2=L2;
	p=L->next;
	while(p)
	{
		if(p->data%2)
		{
			q=new node;
			q->data = p->data;
			p1->next=q;
			p1=q;
			p1->next=NULL;
			p=p->next;
		}
		else
		{
			q=new node;
			q->data=p->data;
			p2->next=q;
			p2=q;
			p2->next=NULL;
			p=p->next;
		}
	}
	cout<<"奇数链表:";
	showList(L1);
	cout<<"偶数链表:";
	showList(L2);
}
//<11>求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。
void commonList(node *L1,node *L2,node *L3)
{
	node *p1,*p2,*p3,*q;
	p1=L1->next;
	p2=L2->next;
	p3=L3;
	while(p1&&p2)
	{
		if(p1->data==p2->data)
		{
			q=new node;
			q->data=p1->data;
			q->next=p3->next;
			p3->next=q;
			p3=q;
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->data<p2->data)
		{
			p1=p1->next;
		}
		else
		{
			p2=p2->next;
		}
	}
}
//<12>删除递增有序单链表中的重复元素，要求时间性能最好。
void deletecommonList(node *L)
{
	node *p,*q;
	p=L->next;
	q=p->next;
	while(q)
	{
		if(p->data==q->data)
		{
			p->next=q->next;
			delete q;
			q=p->next;
		}
		else
		{
			p=p->next;
			q=p->next;
		}
	}
}
//<13>递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并，并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除L2的头结点，要求时间性能最好。
void mergeList(node *L1,node *&L2)
{
	node *p1,*p2,*R;
	p1=L1->next;
	p2=L2->next;
	R=L1;
	while(p1&&p2)
	{
		if(p1->data<=p2->data)
		{
			R->next=p1;
			R=p1;
			p1=p1->next;
		}
		else
		{
			R->next=p2;
			R=p2;
			p2=p2->next;
		}
	}
	if(p1)
		R->next=p1;
	else
		R->next=p2;
	delete L2;
}
//2.4.1<1>（递增有序）单链表表示集合A、B，实现：
//C=A^B，C=AuB，C=A-B
void interseList1(node *L1,node *L2)//C=A^B
{
	node *L,*p,*q,*l,*m;
	p=L1->next;
	q=L2->next;
	initialList(&L);
	l=L;
	cout<<"表L1:";
	showList(L1);
	cout<<endl;
	cout<<"表L2:";
	showList(L2);
	cout<<endl;
	while(p&&q)
	{
		if(p->data==q->data)
		{
			m=new node;
			m->data=p->data;
			m->next=l->next;
			l->next=m;
			l=m;
			p=p->next;
			q=q->next;
		}
		else if(p->data<q->data)
		{
			p=p->next;
		}
		else
		{
			q=q->next;
		}
	}
	showList(L);
}
void unionList1(node *L1,node *L2)//C=AuB
{
	node *L,*p,*q,*l,*m;
	p=L1->next;
	q=L2->next;
	initialList(&L);
	l=L;
	cout<<"表L1:";
	showList(L1);
	cout<<endl;
	cout<<"表L2:";
	showList(L2);
	cout<<endl;
	while(p&&q)
	{
		if(p->data==q->data)
		{
			m=new node;
			m->data=p->data;
			m->next=l->next;
			l->next=m;
			l=m;
			p=p->next;
			q=q->next;
		}
		else if(p->data<q->data)
		{
			m=new node;
			m->data=p->data;
			m->next=l->next;
			l->next=m;
			l=m;
			p=p->next;
		}
		else
		{
			m=new node;
			m->data=q->data;
			m->next=l->next;
			l->next=m;
			l=m;
			q=q->next;
		}
	}
	while(p)
	{
		m=new node;
			m->data=p->data;
			m->next=l->next;
			l->next=m;
			l=m;
			p=p->next;
	}
	while(q)
	{
			m=new node;
			m->data=q->data;
			m->next=l->next;
			l->next=m;
			l=m;
			q=q->next;
	}
	showList(L);
}
void differenceList1(node *L1,node *L2)//C=A-B
{
	node *L,*p,*q,*l,*m;
	p=L1->next;
	q=L2->next;
	initialList(&L);
	l=L;
	cout<<"表L1:";
	showList(L1);
	cout<<endl;
	cout<<"表L2:";
	showList(L2);
	cout<<endl;
	while(p&&q)
	{
		if(p->data==q->data)
		{
			p=p->next;
			q=q->next;
		}
		else if(p->data<q->data)
		{
			m=new node;
			m->data=p->data;
			m->next=l->next;
			l->next=m;
			l=m;
			p=p->next;
		}
		else
		{
			q=q->next;
		}
	}
	while(p)
	{
		m=new node;
			m->data=p->data;
			m->next=l->next;
			l->next=m;
			l=m;
			p=p->next;
	}
	showList(L);
}
//A=A^B，A=AuB，A=A-B
void interseList2(node *L1,node *L2)//A=A^B
{
	node *p,*q,*u;
	p=L1;
	q=L2;
	cout<<"表L1:";
	showList(L1);
	cout<<endl;
	cout<<"表L2:";
	showList(L2);
	cout<<endl;
	while(p->next&&q->next)
	{
		if(p->next->data==q->next->data)
		{
			p=p->next;
			q=q->next;
		}
		else if(p->next->data<q->next->data)
		{
			u=p->next;
			p->next=u->next;
			delete u;
		}
		else
		{
			q=q->next;
		}
	}
	showList(L1);
}
void unionList2(node *A,node *B)//A=AuB
{
	node *pa,*pb,*u;
	pa=A; 
	pb=B->next; 
	while(pa->next!=NULL && pb!=NULL)
	{
		if(pa->next->data<pb->data) 
			pa=pa->next;
		else if(pa->next->data>pb->data) 
		{ 
			u=new node;
			u->data=pb->data;
			u->next=pa->next;pa->next=u;
			pb=pb->next;
		}
		else
		{
			pa=pa->next;
			pb=pb->next;
		}
	}
	while(pb!=NULL)
	{
		u=new node;
		u->data=pb->data;
		u->next=pa->next;
		pa->next=u;
		pa=u;
		pb=pb->next;
	}
	showList(A);
}
//<2>（递增有序）单链表表示集合A、B，判定A是否B的子集。
bool subsetList(node *A,node *B)
{
	node *pa,*pb;
	pa=A->next;
	pb=B->next;
	bool iflag=false;
	while(pa)
	{
		if(pa->data<pb->data)
		{
			iflag=false;
			return false;
		}
		else if(pa->data>pb->data)
		{
			pb=pb->next;
		}
		else
		{
			iflag=true;
			pa=pa->next;
		}
	}
	return iflag;
}
//3>假设该链表只给出了头指针list。在不改变链表的前提下,查找链表中倒数第k个位置上的结点
void getelement1(node *A,int k)
{
	node *pa,*pb;
	int i=0;
	pa=A;
	pb=pa;
	while(pa)
	{
		pa=pa->next;
		i++;
		if(i>=k)
			break;
	}
	while(pa)
	{
		pa=pa->next;
		pb=pb->next;
	}
	cout<<"倒数第"<<i<<"元素:"<<pb->data<<endl;
}
//<4>(2011)（15 分）一个长度为L（L≥1）的升序序列S，处在第个位置的数称为S 的中位数。
//例如，若序列S1=(11, 13, 15, 17, 19)，则S1 的中位数是15。两个序列的中位数是含它们所有元素的升序序列的中位数。
//例如，若S2=(2, 4, 6, 8, 20)，则S1 和S2 的中位数是11。
void medianList(node *A,node *B)
{
	node *pa=A->next,*pb=B->next;
	int len=0,midlen,i=0;
	while(pa)
	{
		len++;
		pa=pa->next;
	}
	while(pb)
	{
		len++;
		pb=pb->next;
	}
	midlen=len/2;
	pa=A->next,pb=B->next;
	while(i<midlen)
	{
		if(pa&&pa->data<pb->data)
		{
			pa=pa->next;
			i++;
		}
		else if(pb&&pa->data>=pb->data)
		{
			pb=pb->next;
			i++;
		}
		else
		{
			if(pb)
			{
				i++;
				pb=pb->next;
			}
			if(pa)
			{
				i++;
				pa=pa->next;
			}
		}
	}
	if(pa&&pa->data<pb->data)
		cout<<pa->data;
	if(pb&&pa->data>pb->data)
		cout<<pb->data;
//	cout<<(pa->data<pb->data)?pa->data:pb->data<<endl;
}