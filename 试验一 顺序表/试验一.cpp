#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include "seqList.h"
int inter()
{
	int x;
	printf(" <1>求顺序表中第i个元素（函数），若不存在，报错。\n");
	printf(" <2>在第i个结点前插入值为x的结点。\n");
	printf(" <3>删除顺序表中第i个元素结点。\n");
	printf(" <4>在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性。\n");
	printf(" <5>将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，然后原表和新表元素同时输出到屏幕上，以便对照求解结果。\n");
	printf(" <6>求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。\n");
	printf(" <7>删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好。\n");
	printf(" <9>（递增有序）顺序表表示集合A、B，判定A是否B的子集。\n");
	printf(" <10>找出两个序列A 和B 的中位数。\n");
	printf(" <0>结束程序.\n 请输入你的选择:");
	cin>>x;
	return x;
}
int main()
{
	list L,A,B;
	int x,i;
	while(1)
	{
		initialList(L);
		switch(inter())
		{
		case 0 :goto Label;break;
		case 1 :{
					creatList(L);
					cout<<"请输入元素的位置:";
					cin>>i;
					if(getElement(L,i,x))
						printf("第%d号元素的数值是:%d\n",i,x);
				}
			break;
		case 2 :{
					creatList(L);
					cout<<"请输入插入位置及元素数值:";
					cin>>i>>x;
					insertList(L,i,x);
					showList(L);
					cout<<endl;
				}
			break;
		case 3 :{
					creatList(L);
					cout<<"请输入删除位置:";
					cin>>i;
					deleteList(L,i);
					showList(L);
				}
			break;
		case 4 :{
					creatList(L);
					cout<<"请输入插入数值:";
					cin>>x;
					insertList(L,x);
					showList(L);
				}
			break;
		case 5 :{
					initialList(A);
					initialList(B);
					creatList(L);
					decompositionList(L,A,B);
					cout<<"\n原表L:";
						showList(L);
					cout<<"\n奇数表A:";
						showList(A);
					cout<<"\n偶数表B:";
						showList(B);
						cout<<endl;
				}
			break;
		case 6 :{
					initialList(A);
					initialList(B);
					creatList(A);
					creatList(B);
					commonList(A,B,L);
					if(L.len==0)
						cout<<"该表为空.";
					else
					{
						cout<<"\n表L:";
						showList(L);
					}
					cout<<endl;
				}
			break;
		case 7 :{
					creatList(L);
					deleteRepeat(L);
					showList(L);
				}
			break;
		case 8 :{
				}
			break;
		case 9:{
					initialList(A);
					initialList(B);
					creatList(A);
					creatList(B);
					if(subsetList(A,B))
						cout<<"A是B的子集.";
					else
						cout<<"A不是B的子集.";
			   }break;
		case 10:{
					initialList(A);
					initialList(B);
					creatList(A);
					creatList(B);
					cout<<"中位数是:"<<medianList(A,B)<<endl;
				}break;
		}
		system("pause");
		system("cls");
	}
Label:
	return 0;
}