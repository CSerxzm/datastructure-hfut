#include "sort.h"

int main()
{
	int i,n,x;
	int a[]={5,6,7,1,2,3,4,8,9,10,11,12,13,16,17,18,14,25,26,15,19,20,21,22,23,24};
	int a1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,16,17,18,14,25,26,15,19,20,21,22,23,24};
	int a2[]={26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int b[]={0,8,9,10,11,12,13,14,1,6,15,16,23,24,17,3,4,18,5,19,20,21,26,7,2,25};
	int b1[]={0,8,9,10,11,12,13,14,1,6,15,16,23,24,17,3,4,18,5,19,20,21,26,7,2,25};
	int b2[]={0,8,9,10,11,12,13,14,1,6,15,16,23,24,17,3,4,18,5,19,20,21,26,7,2,25};
	cin>>x;
	switch(x)
	{
	case 1:
		{
			cout<<"<1>采用不同实验数据来观察快速排序的实验中比较和交换元素的次数."<<endl;
			cout<<"  原数组  :";
			for(i=0;i<26;i++)
				cout<<a[i]<<" ";
			cout<<endl;
			n=0;
			Quicksort(a,0,25,n);
			cout<<"数组调整后:移动"<<n<<"次.";
			for(i=0;i<26;i++)
				cout<<a[i]<<" ";
			cout<<endl;
			cout<<"  原数组  :";
			for(i=0;i<26;i++)
				cout<<a1[i]<<" ";
			cout<<endl;
			n=0;
			Quicksort(a1,0,25,n);
			cout<<"数组调整后:移动"<<n<<"次.";
			for(i=0;i<26;i++)
			cout<<a1[i]<<" ";
			cout<<endl;
			cout<<"  原数组  :";
			for(i=0;i<26;i++)
			cout<<a2[i]<<" ";
			cout<<endl;
			n=0;
			Quicksort(a2,0,25,n);
			cout<<"数组调整后:移动"<<n<<"次.";
			for(i=0;i<26;i++)
				cout<<a2[i]<<" ";
			cout<<endl;

			cout<<"\n<2>将整型数组调整为:３的倍数在最左边,余１的数在中间,余２的数在最右边."<<endl;
			cout<<"  原数组  :";
			for(i=0;i<25;i++)
				cout<<b[i]<<" ";
			cout<<endl;
			adjustment(b,0,24);
			cout<<"数组调整后:";
			for(i=0;i<25;i++)
				cout<<b[i]<<" ";
			cout<<endl;

			cout<<"\n<3>实现shell排序算法，并观察在采用不同的步长选取方法对排序过程中数据的比较和移动次数的影响."<<endl;
			cout<<"  原数组  :";
			for(i=1;i<26;i++)
				cout<<b1[i]<<" ";
			cout<<endl;
			n=0;
			shellSort(b1,25,6,n);
			cout<<"数组调整后(步长为 6):移动"<<n<<"次.";
			for(i=1;i<26;i++)
				cout<<b1[i]<<" ";
			cout<<endl;
			cout<<"  原数组  :";
			for(i=1;i<26;i++)
				cout<<b2[i]<<" ";
			cout<<endl;
			n=0;
			shellSort(b2,25,18,n);
			cout<<"数组调整后(步长为18):移动"<<n<<"次.";
			for(i=1;i<26;i++)
				cout<<b2[i]<<" ";
			cout<<endl;

			cout<<"\n<4>设计算法实现树形选择排序，要求能用数组和树来演示排序过程，以清晰地表示出排序过程."<<endl;
			cout<<"  原数组  :";
			for(i=1;i<26;i++)
				cout<<b[i]<<" ";
			cout<<endl;
			sort(b,25);
			cout<<"数组调整后:";
			for(i=1;i<26;i++)
				cout<<b[i]<<" ";
			cout<<endl;

			cout<<"\n<6>按链式基数排序的方法实现对整数表（假设每个元素最多为三位）的排序."<<endl;
			RecType *p;
			char *c[]={"761","242","993","455","588","138","301","652","399","820"};
			CreaLink(p,c,10);
			cout<<"初始关键字:";
			DispLink(p);
			cout<<"排序过程:"<<endl;
			RadixSort(p,10,3);
			cout<<"最终结果:";
			DispLink(p);
			cout<<endl;
		}
		break;
	case 5:
		{
				cout<<"\n<5>以数组和二叉树形式动态演示堆排序算法的排序过程."<<endl;
				cout<<"  原数组  :";
				for(i=1;i<26;i++)
					cout<<b[i]<<" ";
				cout<<endl;
				headSort(b,25);
				cout<<"数组调整后:";
				for(i=1;i<26;i++)
					cout<<b[i]<<" ";
				cout<<endl;
		}
		break;
	}
	return 0;
}