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

	cout<<"<1>β��L1:";
	creattailList(L1,a);
	showList(L1);

	cout<<"<2>ͷ��L1:";
	initialList(&L1);
	creatheadList(L1,a);
	showList(L1);

	cout<<"<3>���ٵ�����:";
	destoryList(L1);
	initialList(&L1);
	creattailList(L1,a);
	showList(L1);

	cout<<"<4>������L2����: ";
	lenList(L2);

	cout<<"<5>������L2�е�i��Ԫ�أ����������������ڣ�����"<<endl;
	cout<<"��5λԪ��:";
	getelement(L2,5);
	cout<<"��20λԪ��:";
	getelement(L2,20);

	cout<<"\n<6>�ڵ�i�����ǰ����ֵΪx�Ľ��:";
	cout<<"\n��L2��6�����ǰ����ֵΪ6�Ľ��:";
	insertList(L2,6,6);
	showList(L2);

	cout<<"<7>�����в���Ԫ��ֵΪx�Ľ�㣬�ɹ����ؽ��ָ�룬ʧ�ܱ���"<<endl;
	u=getelementType(L2,6);
	if(u)
		cout<<"�ýڵ����ֵ:"<<u->data<<endl;
	else
		cout<<"�ú�������ֵΪ��"<<endl;
	u=getelementType(L2,120);
	if(u)
		cout<<"�ýڵ����ֵ:"<<u->data<<endl;
	else
		cout<<"�ú�������ֵΪ��"<<endl;

	cout<<"<8>ɾ���������е�i��Ԫ�ؽ�㡣"<<endl;
	cout<<"L2ɾ����Ԫ��ǰ:";
	showList(L2);
	deleteList(L2,1);
	cout<<"L2ɾ����Ԫ�غ�:";
	showList(L2);

	cout<<"<9>��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�"<<endl;
	cout<<"L2����10ǰ:";
	showList(L2);
	insertList(L2,10);
	cout<<"L2����10��:";
	showList(L2);

	cout<<"<10>����������е��������ż������ֽ⿪"<<endl;
	separateList(L2);

	cout<<"<11>������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�С�"<<endl;
	showList(L1);
	showList(L2);
	commonList(L1,L2,L);
	cout<<"��������Ԫ��:";
	showList(L);

	cout<<"<12>ɾ���������������е��ظ�Ԫ�أ�Ҫ��ʱ��������á�"<<endl;
	initialList(&L3);
	creattailList(L3,c);
	showList(L3);
	deletecommonList(L3);
	showList(L3);

	cout<<"<13>������������L1��L2���������½�㣬����ԭ�����2����кϲ�."<<endl;
	initialList(&L1);
	creattailList(L1,a);
	showList(L1);
	initialList(&L2);
	creattailList(L2,d);
	showList(L2);
	mergeList(L1,L2);
	showList(L1);

	cout<<"<2>���������򣩵������ʾ����A��B���ж�A�Ƿ�B���Ӽ���"<<endl;
	if(subsetList(L1,L3))
		cout<<"L1��L2���Ӽ�"<<endl;
	else
		cout<<"L1����L2���Ӽ�"<<endl;

	cout<<"<3>���������ֻ������ͷָ��list���ڲ��ı������ǰ����,���������е�����k��λ���ϵĽ��"<<endl;
	showList(L1);
	getelement1(L1,5);

	initialList(&L1);
	creattailList(L1,a);
	initialList(&L2);
	creattailList(L2,b);
	
	cout<<"<4>(2011)��15 �֣�һ������ΪL����������S�������м�λ�õ�����ΪS ����λ����"<<endl;
	cout<<"����L1:";
	showList(L1);
	cout<<"����L2:";
	showList(L2);
	cout<<"L1��L2����λ��:";
	medianList(L1,L2);
	cout<<endl;

	return 0;
}