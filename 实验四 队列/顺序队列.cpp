#include <iostream>
#include "seqQueue.h"
using namespace std;

int main()
{
	queue Q;
	int i,j=0;
	initialQueue(&Q);
	cout<<"初始化后:";
	if(queueEmpty(&Q))
		cout<<"队列为空."<<endl;
	else
		cout<<"队列不为空."<<endl;
	cout<<"1-100入队列,出现队满情况."<<endl;
	for(i=1;i<100;i++)
	{
		if(queueFull(&Q))
			break;
		enQueue(&Q,i);
	}
	cout<<"队列元素:";
	while(!queueEmpty(&Q))
	{
		j++;
		queueFront(&Q,i);
		cout<<i<<" ";
		outQueue(&Q);
		if(!(j%20))
			cout<<endl;
	}

	initialQueue(&Q);
	cout<<endl;
	cout<<"输入入队列元素,以0结束:";
	cin>>i;
	while(i!=0)
	{
		enQueue(&Q,i);
		cin>>i;
	}
	cout<<"队列元素:"<<endl;
	while(!queueEmpty(&Q))
	{
		queueFront(&Q,i);
		cout<<i<<" ";
		outQueue(&Q);
	}
	cout<<endl;

	cout<<"<8>编写算法实现当键盘输入奇数时,此奇数入队;当键盘输入偶数时,队头出队;"<<endl;
	algorithm(&Q);

	return 0;
}