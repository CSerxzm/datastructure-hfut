#include <stdlib.h>
#include <stdio.h>
#include "biNode.h"

#include<iostream>
using namespace std;
#define MAXLEN 100
typedef TriTree elementType1;
typedef struct stack
{
	elementType1  data[MAXLEN];
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
bool pushStack(seqstack &s,elementType1 x)
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
bool popStack(seqstack &s,elementType1 &x)
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
void topStack(seqstack s,elementType1 &x)
{
	x=s.data[s.top];
}
