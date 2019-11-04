#include<iostream>
using namespace std;

typedef struct Node
{ 
	int data; 
	struct Node* next; 
}node;
class Queue
{
	public:
	Queue();
	//~Queue();
	bool empty();
	void getFront(int &x);
	void enQueue(int x);
	void outQueue();
	int getCount();
	private:
	int count;
	node* front;
	node* rear;
};
Queue::Queue()
{
	front=NULL;
	rear=front;
	count=0;
}
bool Queue::empty()
{
	return (front==NULL);
}
void Queue::getFront(int &x)
{
	if(empty())
		cout<<"队列为空."<<endl;
	else
		x=front->data;
}
void Queue::outQueue()
{
	node *u;
	if(empty())
		cout<<"队列为空."<<endl;
	else
	{
		u=front;
		front=front->next;
		delete u;
		if(!front)
			rear=front;
		count--;
	}
}
void Queue::enQueue(int x)
{
	node *u;
	u=new node;
	u->data=x;
	if(!front)
	{
		front=u;
		rear=u;
	}
	else
	{
		rear->next=u;
		rear=u;
	}
		count++;
		rear->next=NULL;
}
int Queue::getCount()
{
	return count;
}

void algorithm()
{
	int x;
	Queue Q;
	cout<<"请输入序列,以0结束.";
	x=-1;
	cin>>x;
	while(x!=0)
	{
		if(x%2)
			Q.enQueue(x);
		else
			Q.outQueue();
		cin>>x;
	}
	cout<<"队列元素:";
	while(!Q.empty())
	{
		Q.getFront(x);
		cout<<x<<" ";
		Q.outQueue();
	}
	cout<<endl;
}
