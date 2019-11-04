#include <iostream>
#include "seqQueue.h"
using namespace std;

int main()
{
	queue Q;
	int i,j=0;
	initialQueue(&Q);
	cout<<"��ʼ����:";
	if(queueEmpty(&Q))
		cout<<"����Ϊ��."<<endl;
	else
		cout<<"���в�Ϊ��."<<endl;
	cout<<"1-100�����,���ֶ������."<<endl;
	for(i=1;i<100;i++)
	{
		if(queueFull(&Q))
			break;
		enQueue(&Q,i);
	}
	cout<<"����Ԫ��:";
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
	cout<<"���������Ԫ��,��0����:";
	cin>>i;
	while(i!=0)
	{
		enQueue(&Q,i);
		cin>>i;
	}
	cout<<"����Ԫ��:"<<endl;
	while(!queueEmpty(&Q))
	{
		queueFront(&Q,i);
		cout<<i<<" ";
		outQueue(&Q);
	}
	cout<<endl;

	cout<<"<8>��д�㷨ʵ�ֵ�������������ʱ,���������;����������ż��ʱ,��ͷ����;"<<endl;
	algorithm(&Q);

	return 0;
}