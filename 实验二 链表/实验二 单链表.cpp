#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
int a[15]={1,3,5,7,9,11,12,13,14,18,-1};
int b[15]={2,3,6,7,10,12,13,15,16,20,-1};
int c[15]={2,2,2,7,7,12,13,15,15,20,-1};
int d[15]={-1};
int main()
{
	node * L1,*L2,*L,*L3,*L4,*u;
	initialList(&L1);
	initialList(&L2);
	creattailList(L2,b);
	initialList(&L);
	//creattailList(L,a);

	cout<<"<1>尾插L1:";
	creattailList(L1,a);
	showList(L1);

	cout<<"<2>头插L1:";
	initialList(&L1);
	creatheadList(L1,a);
	showList(L1);

	cout<<"<3>销毁单链表:";
	destoryList(L1);
	initialList(&L1);
	creattailList(L1,a);
	showList(L1);

	cout<<"<4>求链表L2长度: ";
	lenList(L2);

	cout<<"<5>求单链表L2中第i个元素（函数），若不存在，报错。"<<endl;
	cout<<"第5位元素:";
	getelement(L2,5);
	cout<<"第20位元素:";
	getelement(L2,20);

	cout<<"\n<6>在第i个结点前插入值为x的结点:";
	cout<<"\n在L2第6个结点前插入值为6的结点:";
	insertList(L2,6,6);
	showList(L2);

	cout<<"<7>链表中查找元素值为x的结点，成功返回结点指针，失败报错。"<<endl;
	u=getelementType(L2,6);
	if(u)
		cout<<"该节点的数值:"<<u->data<<endl;
	else
		cout<<"该函数返回值为空"<<endl;
	u=getelementType(L2,120);
	if(u)
		cout<<"该节点的数值:"<<u->data<<endl;
	else
		cout<<"该函数返回值为空"<<endl;

	cout<<"<8>删除单链表中第i个元素结点。"<<endl;
	cout<<"L2删除首元素前:";
	showList(L2);
	deleteList(L2,1);
	cout<<"L2删除首元素后:";
	showList(L2);

	cout<<"<9>在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。"<<endl;
	cout<<"L2插入10前:";
	showList(L2);
	insertList(L2,10);
	cout<<"L2插入10后:";
	showList(L2);

	cout<<"<10>将单链表Ｌ中的奇数项和偶数项结点分解开"<<endl;
	separateList(L2);

	cout<<"<11>求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。"<<endl;
	showList(L1);
	showList(L2);
	commonList(L1,L2,L);
	cout<<"两个表公共元素:";
	showList(L);

	cout<<"<12>删除递增有序单链表中的重复元素，要求时间性能最好。"<<endl;
	initialList(&L3);
	creattailList(L3,c);
	showList(L3);
	deletecommonList(L3);
	showList(L3);

	cout<<"<13>递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并."<<endl;
	initialList(&L1);
	creattailList(L1,a);
	showList(L1);
	initialList(&L2);
	creattailList(L2,d);
	showList(L2);
	mergeList(L1,L2);
	showList(L1);

	cout<<"<2>（递增有序）单链表表示集合A、B，判定A是否B的子集。"<<endl;
	if(subsetList(L1,L3))
		cout<<"L1是L2的子集"<<endl;
	else
		cout<<"L1不是L2的子集"<<endl;

	cout<<"<3>假设该链表只给出了头指针list。在不改变链表的前提下,查找链表中倒数第k个位置上的结点"<<endl;
	showList(L1);
	getelement1(L1,5);

	initialList(&L1);
	creattailList(L1,a);
	initialList(&L2);
	creattailList(L2,b);
	
	cout<<"<4>(2011)（15 分）一个长度为L的升序序列S，处在中间位置的数称为S 的中位数。"<<endl;
	cout<<"链表L1:";
	showList(L1);
	cout<<"链表L2:";
	showList(L2);
	cout<<"L1和L2的中位数:";
	medianList(L1,L2);
	cout<<endl;

	return 0;
}