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
�����һ�����������ָպ���ջ�����֣���ôֱ�ӵ�����
�����һ�����������ֲ���ջ�������Ǿ�Ҫ��ѹջ�����л�û����ջ������ѹ�븨��ջ��ֱ������һ����Ҫ����������ѹ��ջ��Ϊֹ��
������е����ֶ�ѹ����ջ����Ȼû���ҵ���һ�����������֣���ô�����оͲ�������һ���Ϸ��ĵ������С�
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
     static int number = 0;//��¼���еĸ���
     static Stack<int> stack(30);//������ջ��Ԫ��
     static int array[10];//���������Ԫ��
     int top;//����ȡtop
     if(i == n+1)//�ݹ�����������������
     {
         ++number;
         for(int j = 0;j< n-stack.length();++j)
            cout<<array[j];//�������
         stack.print();//���
         cout<<endl;
    }
    else
    {
        stack.push(i);//��ջ
        print_valid_sequence(i+1,n);
        stack.pop();//Ϊ����stack���䣬��ջ
 
        if(!stack.empty())//��ջ��Ԫ�����
        {
            top=stack.top();
            array[i-stack.length()-1] = top;//�������Ԫ�ط���array��
            stack.pop();
            print_valid_sequence(i,n);//i����
            stack.push(top);
        }
    }
}
int main()
{
	int s[100],n,i=0;
	printf("�����ջ˳��,��0����:");
	for(i=0;s[i-1]!=0;i++)
	{
		scanf("%d",&s[i]);
	}
	n=i--;
	if(Ispoporder(s,n))
		printf("����ȷ�ĳ�ջ˳��.\n");
	else
		printf("������ȷ�ĳ�ջ˳��.\n");
	cout<<"1 2 3 4���г�ջ˳��:"<<endl; 
	print_valid_sequence(1,4);
	return 0;
}
