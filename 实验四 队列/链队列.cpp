#include <iostream>
#include "linkedQueue.h"
using namespace std;

int main()
{
	int i;
	Queue Q;
	cout<<"��ʼ����:";
	if(Q.empty())
		cout<<"����Ϊ��."<<endl;
	else
		cout<<"���в�Ϊ��."<<endl;
	cout<<"�������Ԫ��,��0����:";
	cin>>i;
	while(i!=0)
	{
		Q.enQueue(i);
		cin>>i;
	}
	cout<<"������Ԫ�ظ���:"<<Q.getCount()<<endl;
	while(!Q.empty())
	{
		Q.getFront(i);
		cout<<i<<" ";
		Q.outQueue();
	}
	cout<<endl;


	cout<<"<8>��д�㷨ʵ�ֵ�������������ʱ,���������;����������ż��ʱ,��ͷ����;"<<endl;
	algorithm();
	return 0;
}