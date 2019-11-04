#include<iostream>
using namespace std;
typedef int elementType;
#define MAXLEN 100

typedef struct Queue
{
	elementType data[MAXLEN];
	int front;
	int rear;
}queue;

void initialQueue(queue *Q)
{
	Q->front=0;
	Q->rear=0;
}

bool queueEmpty(queue *Q)
{
	return (Q->front==Q->rear);
}

bool queueFull(queue *Q)
{
	return (Q->front==(Q->rear+1)%MAXLEN);
}

void enQueue(queue *Q,elementType x)
{
	if(queueFull(Q))
		cout<<"队列已满."<<endl;
	else
	{
		Q->rear=(Q->rear+1)%MAXLEN;
		Q->data[Q->rear]=x;
	}
}

void outQueue(queue *Q)
{
	if(queueEmpty(Q))
		cout<<"队列为空."<<endl;
	else
	{
		Q->front=(Q->front+1)%MAXLEN;
	}
}

void queueFront(queue *Q,elementType &x)
{
	if(queueEmpty(Q))
		cout<<"队列为空."<<endl;
	else
	{
		x=Q->data[(Q->front+1)%MAXLEN];
	}
}

void queueLenght(queue *Q)
{
	cout<<"该队列元素个数:"<<(Q->rear-Q->front+MAXLEN)%MAXLEN<<endl;
}

void algorithm(queue *Q)
{
	elementType x;
	initialQueue(Q);
	cout<<"请输入序列,以0结束.";
	x=-1;
	cin>>x;
	while(x!=0)
	{
		if(x%2)
			enQueue(Q,x);
		else
			outQueue(Q);
		cin>>x;
	}
	cout<<"队列元素:";
	while(!queueEmpty(Q))
	{
		queueFront(Q,x);
		cout<<x<<" ";
		outQueue(Q);
	}
	cout<<endl;
}