#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include "seqList.h"
int inter()
{
	int x;
	printf(" <1>��˳����е�i��Ԫ�أ����������������ڣ�����\n");
	printf(" <2>�ڵ�i�����ǰ����ֵΪx�Ľ�㡣\n");
	printf(" <3>ɾ��˳����е�i��Ԫ�ؽ�㡣\n");
	printf(" <4>��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�\n");
	printf(" <5>��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������\n");
	printf(" <6>��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�\n");
	printf(" <7>ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ��������á�\n");
	printf(" <9>����������˳����ʾ����A��B���ж�A�Ƿ�B���Ӽ���\n");
	printf(" <10>�ҳ���������A ��B ����λ����\n");
	printf(" <0>��������.\n ���������ѡ��:");
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
					cout<<"������Ԫ�ص�λ��:";
					cin>>i;
					if(getElement(L,i,x))
						printf("��%d��Ԫ�ص���ֵ��:%d\n",i,x);
				}
			break;
		case 2 :{
					creatList(L);
					cout<<"���������λ�ü�Ԫ����ֵ:";
					cin>>i>>x;
					insertList(L,i,x);
					showList(L);
					cout<<endl;
				}
			break;
		case 3 :{
					creatList(L);
					cout<<"������ɾ��λ��:";
					cin>>i;
					deleteList(L,i);
					showList(L);
				}
			break;
		case 4 :{
					creatList(L);
					cout<<"�����������ֵ:";
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
					cout<<"\nԭ��L:";
						showList(L);
					cout<<"\n������A:";
						showList(A);
					cout<<"\nż����B:";
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
						cout<<"�ñ�Ϊ��.";
					else
					{
						cout<<"\n��L:";
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
						cout<<"A��B���Ӽ�.";
					else
						cout<<"A����B���Ӽ�.";
			   }break;
		case 10:{
					initialList(A);
					initialList(B);
					creatList(A);
					creatList(B);
					cout<<"��λ����:"<<medianList(A,B)<<endl;
				}break;
		}
		system("pause");
		system("cls");
	}
Label:
	return 0;
}