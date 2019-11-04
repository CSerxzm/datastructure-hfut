#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

template<class T>
class Stack
{
	private:
		T *data;
		int memNum;
		int size;
	public:
		Stack(int s);
		~Stack();
		void pop();
		void push(T num);
		bool empty();
		int length();
		void print();
		T top();
};
template<class T>
Stack<T>::Stack(int s)
{
	size = s>0 ? s:100;
	data = new T[size];
	memNum=0;
}
template<class T>
Stack<T>::~Stack()
{
	delete [] data;
}
template<class T>
void Stack<T>::pop()
{
	memNum--;
}
template<class T>
void Stack<T>::push(T num)
{
	data[memNum++]=num;
}
template<class T>
bool Stack<T>::empty()
{
	if(memNum==0)
		return true;
	else
		return false;
}
template<class T>
T Stack<T>::top()
{
	return data[memNum-1];
}
template<class T>
int Stack<T>::length()
{
	return memNum;
}
template<class T>
void Stack<T>::print()
{
	int i=0;
	for(i=memNum-1;i>=0;i--)
		cout<<data[i];
}
