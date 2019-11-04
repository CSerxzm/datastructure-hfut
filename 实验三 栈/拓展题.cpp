#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#include "stack.h"

Stack<int> num(10);

bool Ispoporder(int s[],int len)
{
/*	
如果下一个弹出的数字刚好是栈顶数字，那么直接弹出；
如果下一个弹出的数字不在栈顶，我们就要把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止；
如果所有的数字都压入了栈中仍然没有找到下一个弹出的数字，那么该序列就不可能是一个合法的弹出序列。
	*/
	int i=0,j=1;
	for(i=0;i<len-1;i++)
		if(len-1<s[i])
			return false;

		i=0;
	while(i<len-1)
	{
			if(!(num.empty())||s[i]==num.top())
			{
				num.pop();
			}
			else
			{
				while(j>i&&j<s[i])
				{
					num.push(j);
					j++;
				}
			}
			i++;
			if(num.top()>s[i])
				return false;
	}
	if(i>=len-1)
		return true;
}
void print_valid_sequence(int i,const int n )
 {
     static int number = 0;//记录序列的个数
     static Stack<int> stack(30);//保存入栈的元素
     static int array[10];//保存输出的元素
     int top;//用来取top
     if(i == n+1)//递归结束条件，输出序列
     {
         ++number;
         for(int j = 0;j< n-stack.length();++j)
            cout<<array[j];//正序输出
         stack.print();//输出
         cout<<endl;
    }
    else
    {
        stack.push(i);//入栈
        print_valid_sequence(i+1,n);
        stack.pop();//为保持stack不变，出栈
 
        if(!stack.empty())//将栈顶元素输出
        {
            top=stack.top();
            array[i-stack.length()-1] = top;//将输出的元素放入array中
            stack.pop();
            print_valid_sequence(i,n);//i不变
            stack.push(top);
        }
    }
}
int main()
{
	int s[100],n,i=0;
	printf("输入出栈顺序,以0结束:");
	for(i=0;s[i-1]!=0;i++)
	{
		scanf("%d",&s[i]);
	}
	n=i--;
	if(Ispoporder(s,n))
		printf("是正确的出栈顺序.\n");
	else
		printf("不是正确的出栈顺序.\n");
	cout<<"1 2 3 4所有出栈顺序:"<<endl; 
	print_valid_sequence(1,4);
	return 0;
}
