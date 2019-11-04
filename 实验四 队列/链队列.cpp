#include <iostream>
#include "linkedQueue.h"
using namespace std;

int main()
{
	int i;
	Queue Q;
	cout<<"初始化后:";
	if(Q.empty())
		cout<<"队列为空."<<endl;
	else
		cout<<"队列不为空."<<endl;
	cout<<"输入入队元素,以0结束:";
	cin>>i;
	while(i!=0)
	{
		Q.enQueue(i);
		cin>>i;
	}
	cout<<"队列中元素个数:"<<Q.getCount()<<endl;
	while(!Q.empty())
	{
		Q.getFront(i);
		cout<<i<<" ";
		Q.outQueue();
	}
	cout<<endl;


	cout<<"<8>编写算法实现当键盘输入奇数时,此奇数入队;当键盘输入偶数时,队头出队;"<<endl;
	algorithm();
	return 0;
}