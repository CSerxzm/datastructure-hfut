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
//<1>β�巨
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
//<2>ͷ�巨
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
//<3>���ٵ�����
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
	cout<<"�����Ѿ��ݻ�."<<endl;
}
//<4>��������
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
	cout<<"������:"<<len<<endl;
}
//<5>�������е�i��Ԫ�أ����������������ڣ�����
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
		cout<<"��Ŵ���.";
}
//<6>�ڵ�i�����ǰ����ֵΪx�Ľ�㡣
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
//<7>�����в���Ԫ��ֵΪx�Ľ�㣬�ɹ����ؽ��ָ�룬ʧ�ܱ���
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
//<8>ɾ���������е�i��Ԫ�ؽ�㡣
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
//<9>��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�
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
//<10>����������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µĵ������У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
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
	cout<<"��������:";
	showList(L1);
	cout<<"ż������:";
	showList(L2);
}
//<11>������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�С�
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
//<12>ɾ���������������е��ظ�Ԫ�أ�Ҫ��ʱ��������á�
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
//<13>������������L1��L2���������½�㣬����ԭ�����2����кϲ�����ʹ�úϲ����Ϊһ�����ϣ��ϲ�����L1��ͷ�����Ϊͷ��㣬ɾ��L2��ͷ��㣬Ҫ��ʱ��������á�
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
//2.4.1<1>���������򣩵������ʾ����A��B��ʵ�֣�
//C=A^B��C=AuB��C=A-B
void interseList1(node *L1,node *L2)//C=A^B
{
	node *L,*p,*q,*l,*m;
	p=L1->next;
	q=L2->next;
	initialList(&L);
	l=L;
	cout<<"��L1:";
	showList(L1);
	cout<<endl;
	cout<<"��L2:";
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
	cout<<"��L1:";
	showList(L1);
	cout<<endl;
	cout<<"��L2:";
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
	cout<<"��L1:";
	showList(L1);
	cout<<endl;
	cout<<"��L2:";
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
//A=A^B��A=AuB��A=A-B
void interseList2(node *L1,node *L2)//A=A^B
{
	node *p,*q,*u;
	p=L1;
	q=L2;
	cout<<"��L1:";
	showList(L1);
	cout<<endl;
	cout<<"��L2:";
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
//<2>���������򣩵������ʾ����A��B���ж�A�Ƿ�B���Ӽ���
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
//3>���������ֻ������ͷָ��list���ڲ��ı������ǰ����,���������е�����k��λ���ϵĽ��
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
	cout<<"������"<<i<<"Ԫ��:"<<pb->data<<endl;
}
//<4>(2011)��15 �֣�һ������ΪL��L��1������������S�����ڵڸ�λ�õ�����ΪS ����λ����
//���磬������S1=(11, 13, 15, 17, 19)����S1 ����λ����15���������е���λ���Ǻ���������Ԫ�ص��������е���λ����
//���磬��S2=(2, 4, 6, 8, 20)����S1 ��S2 ����λ����11��
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