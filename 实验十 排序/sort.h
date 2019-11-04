#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"drawing.h"
#include<math.h>
#include<iomanip>
#include<iostream>
using namespace std;

typedef int elementType;
// 快速排序
void partition(elementType A[],int s,int t,int *cutPoint,int &n)
{
	elementType x=A[s];
	int i=s,j=t;
	while(i!=j)
	{
		while(i<j&&A[j]>x)
			j--;
		if(i<j)
		{
			A[i]=A[j];
			i=i+1;
		}
		while(i<j&&A[i]<x)
			i++;
		if(i<j)
		{
			A[j]=A[i];
			j=j-1;
		}
	}
	A[i]=x;
	n++;
	*cutPoint = i;
}

void Quicksort(elementType A[],int s,int t,int &n)
{
	int i;
	if(s<t)
	{
		partition(A,s,t,&i,n);
		Quicksort(A,s,i-1,n);
		Quicksort(A,i+1,t,n);
	}
}

//调整数组使3的倍数在前面，余1的倍数位于中间，余2的倍数位于最后
void adjustment(elementType A[],int s,int t)
{
	elementType x;
	int low=s,high=t,i;
	while(high>low)
	{
		if(A[low]%3==0)
		{
			low++;
		}
		else if(A[high]%3==0)
		{
			x=A[high];
			A[high]=A[low];
			A[low]=x;
			low++;
			high--;
		}
		else
		{
			high--;
		}
	}
	high=t;
	while(high>low)
	{
		if(A[low]%3==1)
		{
			low++;
		}
		else if(A[high]%3==1)
		{
			x=A[high];
			A[high]=A[low];
			A[low]=x;
			low++;
			high--;
		}
		else
		{
			high--;
		}
	}
}

//shell排序
void shellSort(elementType A[],int n,int d,int &l)
{
	int i,j;
	elementType x;
	while(d>0)
	{
		/*for(i=d;i<n;i++)
		{
			j=i-d;
			while(j>=0&&A[j+d]<A[j])
			{
				x=A[j+d];
				A[j+d]=A[j];
				A[j]=x;
				j=j-d;
			}
			//A[j+d]=x;
		}*/
		for(i=d+1;i<=n;i++)
		{
			x=A[i];
			j=i-d;
			while(j>0&&x<A[j])
			{
				A[j+d]=A[j];
				j=j-d;
			}
			A[j+d]=x;
			l++;
		}
		d=d/2;
	}
}
//堆排序
void sift(elementType A[],int n,int k,int m)
{
	elementType x=A[k];
	bool finished=false;
	int i=k,j=2*i;
	while(j<=m&&!finished)
	{
		if(j<m&&A[j]<A[j+1])
			j++;
		if(x>=A[j])
			finished=true;
		else
		{
			A[i]=A[j];
			i=j;
			j=2*j;
		}
	}
	A[i]=x;
}
void headSort(elementType A[],int n)
{
	int i,j;
	Bnode *p=NULL;
	elementType x;
	for(i=n/2;i>=1;i--)
	{
		sift(A,n,i,n);
		creat(p,A,1,n);
		Tree(p);
		destroy(p);
	}
	for(i=n;i>=2;i--)
	{
		x=A[i];
		A[i]=A[1];
		A[1]=x;
		sift(A,n,1,i-1);
		creat(p,A,1,n);
		Tree(p);
		destroy(p);
	}
}
/////////////////////////////////////////////////////
//                    树形排序                     //
/////////////////////////////////////////////////////
#define num 10
#define max 1000
void sort(int *a,int n)
{
	int h,k,m;
	int i,j;
	int m1,k1;
	int *p;
	h=(int)ceil(log(n)/log(2))+1;
	k=(int)pow(2,h)-1;
	p=new int[k];
	m=(int)pow(2,h-1)-1;
	for(i=0;i<n;i++)
		p[i+m]=a[i];
	for(j=i;j<k-m;j++)
		p[m+j]=max;
	for(i=0;i<n;i++)
	{
		m1=m;k1=k;
		while(m1)
		{
			for(j=m1;j<k1-1;j+=2)
				p[j/2]=(p[j]<=p[j+1]?p[j]:p[j+1]);
			k1=m1;
			m1=m1/2;
		}
		a[i]=p[0];
		m1=0;
		for(j=1;j<h;j++)
			if(p[m1]==p[2*m1+1])
				m1=2*m1+1;
			else
				m1=2*m1+2;
		p[m1]=max;
	}
	delete p;
}
/////////////////////////////////////////////////////
//                     基数排序                    //
/////////////////////////////////////////////////////

#define MAXE 20
#define MAXR 10
#define MAXD  8

typedef struct Node
{
	char data[MAXD];
	struct Node *next;
}RecType;

void CreaLink(RecType *&p,char *a[],int n)
{
	int i;
	RecType *s,*t;
	for(i=0;i<n;i++)
	{
		s = new RecType;
		if(s==NULL)
		{
			exit(0);
		}
		strcpy(s->data,a[i]);
		if(i==0)
		{
			p=s;
			t=s;
		}
		else
		{
			t->next=s;
			t=s;
		}
		t->next=NULL;
	}
}

void DispLink(RecType *p)
{
	RecType *s=p;
	while(s)
	{
		printf("%4s",s->data);
		s=s->next;
	}
	cout<<endl;
}

void RadixSort(RecType *&p,int r,int d)
{
	RecType *head[MAXR],*tail[MAXR],*t;
	int i,j,k;
	for(i=d-1;i>=0;i--)
	{
		for(j=0;j<r;j++)
			head[j]=tail[i]=NULL;
		while(p)
		{
			k=p->data[i]-'0';
			if(head[k]==NULL)
			{
				head[k]=p;
				tail[k]=p;
			}
			else
			{
				tail[k]->next=p;
				tail[k]=p;
			}
			p=p->next;
		}
		p=NULL;
		for(j=0;j<r;j++)
		{
			if(head[j])
			{
				if(p==NULL)
				{
					p=head[j];
					t=tail[j];
				}
				else
				{
					t->next=head[j];
					t=tail[j];
				}
			}
		}
		t->next=NULL;
		DispLink(p);
	}
}
