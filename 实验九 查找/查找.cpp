#include "seek.h"

int main()
{
	int x,i,mid;
	int a[]={1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,100};
	int b[]={100,150,120,50,70,60,80,170,180,160,110,30,40,35,175};
	int c[]={100,90,80,60,70,50,120,110,87,88,89,90,89,1000};
	Bnode *T=NULL;
	while(1)
	{
		initialize();
		cin>>i;
		switch(i)
		{
			case 0: exit(0);break;
			case 1:
				{
					for(int j=0;j<25;j++)
						cout<<a[j]<<" ";
					cout<<"\n请输入你查找的元素:";
					cin>>x;
					mid=bin_search(a,25,x);
					cout<<"你查找的元素:"<<x<<"所处位置:"<<mid<<endl;
				}
				break;
			case 2:
				{
					for(int i=0;i<16;i++)
					{
						creat_bst(&T,b[i]);
					}
					show(T);
					destroy(T);
					cout<<endl;
				}break;
			case 3:
				{
					for(int i=0;i<16;i++)
					{
						creat_bst(&T,b[i]);
					}
					show(T);
					cout<<"\n请输入查找的数值:";
					cin>>x;
					Bnode *p=bst_search(T,x);
					if(p)
						cout<<"找到数值:"<<p->data<<endl;
					else
						cout<<"未找到数值."<<endl;
					destroy(T);
				}
				break;
			case 4:
				{
					for(int i=0;i<16;i++)
					{
						creat_bst(&T,b[i]);
					}
					show(T);
					cout<<"\n输入删除的结点数值:";
					cin>>x;
					delete_node(T,x);
					show(T);
					cout<<endl;
					destroy(T);
				}break;
			case 5:
				{
					AVLTree avlt=NULL;
					for(int i=0;c[i]!=1000;i++)
					ins_AVLtree(avlt,c[i]);
					show(avlt);
					Tree(avlt);
				}break;
		}
		system("pause");
		system("cls");
	}
		return 0;
}