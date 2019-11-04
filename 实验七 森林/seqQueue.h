#include<iostream>
#include "biNode.h"
using namespace std;
typedef csTree elementType1;
#define MAXLEN 100

typedef struct Queue
{
	elementType1 data[MAXLEN];
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

void enQueue(queue *Q,elementType1 x)
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

void queueFront(queue *Q,elementType1 &x)
{
	if(queueEmpty(Q))
		cout<<"队列为空."<<endl;
	else
	{
		x=Q->data[(Q->front+1)%MAXLEN];
	}
}