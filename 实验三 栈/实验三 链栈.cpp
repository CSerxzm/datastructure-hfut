#include<iostream>
using namespace std;
#include "linkedstack.h"

int main()
{
	linkedstack *top;
	char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int x,n=16,r,i=0;
	cout<<"<1>利用顺序栈实现将10进制数转换为16进制数。"<<endl;
	initialStack(top);
	cout<<"请输入一个十进制数字:";
	cin>>x;
	while(x)
	{
		r=x%n;
		pushStack(top,r);
		x=x/n;
	}
	cout<<"转化为16进制为:";
	while(!stackEmpty(top))
	{
		gettop(top,r);
		popStack(top);
		cout<<a[r];
	}
	cout<<endl;
	cout<<"<2>对一个合法的数学表达式来说，其中的各大小括号相互匹配的,判断其中的各括号是否是匹配的。"<<endl;
	matchParenthesis();
	return 0;
}