#include<stdlib.h>
#include<stdio.h>

#include<iostream>
using namespace std;
#define MAXLEN 100
typedef struct stack
{
	int data[MAXLEN];
	int top;
}seqstack;
void initialStack(seqstack &s)
{
	s.top=-1;
}
bool stackEmpty(seqstack s)
{
	return (s.top==-1)?true:false;
}
bool pushStack(seqstack &s,int x)
{
	if(s.top==MAXLEN-1)
	{
		return false;
	}
	else
	{
		s.top++;
		s.data[s.top]=x;
		return true;
	}
}
bool popStack(seqstack &s,int &x)
{
	if(s.top==-1)
		return false;
	else
		{
			x=s.data[s.top];
			s.top--;
			return true;
		}
}
void matchParenthesis()
{
	int i=0,r;
	char b[10];
	seqstack s;
	cout<<"请输入表达式:";
	scanf("%s",b);
	initialStack(s);
	bool iflag=true;
	while(b[i]!='\0'&&iflag)
	{
		switch(b[i])
		{
		case '(':
		case '[':
		case '{':
			{	pushStack(s,b[i]);	i++;	break;}
		case ')':
		case ']':
		case '}':
			{
				if(stackEmpty(s))
					iflag=false;
				else
				{
					popStack(s,r);
					if(r==b[i]-2||r==b[i]-1)
					{
						iflag=true;
						i++;
					}
					else
						iflag=false;
				}
				break;
			}
		default: i++;
		}
	}
	if(b[i]=='\0'&&stackEmpty(s)&&iflag)
		cout<<"匹配.";
	else
		cout<<"不匹配.";
}