#include<stdlib.h>
#include<stdio.h>

#include<iostream>
using namespace std;

typedef struct stack
{
	int data;
	struct stack *next;
}linkedstack;
void initialStack(linkedstack *& top)
{
	top=NULL;
}
bool stackEmpty(linkedstack *top)
{
	return top==NULL?true:false;
}
void pushStack(linkedstack *&top,int x)
{
	linkedstack *s;
	s = new linkedstack;
	s->data=x;
	s->next=top;
	top=s;
}
bool popStack(linkedstack *&top)
{
	if(!top)
		return false;
	else
	{
		linkedstack *u;
		u=top;
		top=top->next;
		delete u;
		return true;
	}
}
bool gettop(linkedstack *top,int &x)
{
	if(top==NULL)
		return false;
	else
	{
		x=top->data;
		return true;
	}	
}
void matchParenthesis()
{
	int i=0,r;
	char b[10];
	linkedstack *top;
	cout<<"请输入表达式:";
	scanf("%s",b);
	initialStack(top);
	bool iflag=true;
	while(b[i]!='\0'&&iflag)
	{
		switch(b[i])
		{
		case '(':
		case '[':
		case '{':
			{	pushStack(top,b[i]);	i++;	break;}
		case ')':
		case ']':
		case '}':
			{
				if(stackEmpty(top))
					iflag=false;
				else
				{
					gettop(top,r);
					popStack(top);
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
	if(b[i]=='\0'&&stackEmpty(top)&&iflag)
		cout<<"匹配.";
	else
		cout<<"不匹配.";
}