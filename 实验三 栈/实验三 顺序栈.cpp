#include<iostream>
using namespace std;
#include "seqstack.h"

int main()
{
	seqstack s;
	char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int x,n=16,r,i=0;
	cout<<"<1>����˳��ջʵ�ֽ�10������ת��Ϊ16��������"<<endl;
	initialStack(s);
	cout<<"������һ��ʮ��������:";
	cin>>x;
	while(x)
	{
		r=x%n;
		pushStack(s,r);
		x=x/n;
	}
	cout<<"ת��Ϊ16����Ϊ:";
	while(!stackEmpty(s))
	{
		popStack(s,r);
		cout<<a[r];
	}
	cout<<endl;
	cout<<"<2>��һ���Ϸ�����ѧ���ʽ��˵�����еĸ���С�����໥ƥ���,�ж����еĸ������Ƿ���ƥ��ġ�"<<endl;
	matchParenthesis();
	return 0;
}