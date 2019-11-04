#include<stdio.h>
#include<stdlib.h>
typedef int elementType;
#define MAXLEN 100
typedef struct
{
	elementType data[MAXLEN];
	int len;
}list;
void initialList(list &L)
{
	L.len=0;
}
void creatList(list &L)
{
	int x;
	printf("请输入元素以-1结束.");
	scanf("%d",&x);
	while(x!=-1)
	{
		L.data[L.len]=x;
		L.len++;
		scanf("%d",&x);
	}
}
void showList(list L)
{
	for(int i=0;i<L.len;i++)
		printf("%d ",L.data[i]);
}

//************************************************//
//                      实验1.3                   //
//************************************************//
//		<1>求顺序表中第i个元素，如不存在，报错。
bool getElement(list L,int i,elementType &x)
{
	if(i<=0||i>L.len)
	{
		printf("输入的序号有误.\n");
		return false;
	}
	else
	{
		x=L.data[i-1];
		return true;
	}
}
//		<2>在第i个节点前插入数值为x的节点
void insertList(list &L,int i,elementType x)
{
	int j;
	if(i<=0||i>L.len+1)
	{
		printf("输入的序号有误.");
	}
	else
	{
		for(j=L.len-1;j>=i-1;j--)
			L.data[j+1]=L.data[j];
		L.data[i-1]=x;
		L.len++;
	}
}
//		<3>删除第i个节点
void deleteList(list &L,int i)
{
	int j;
	if(i<=0||i>L.len)
	{
		printf("输入的序号有误.\n");
	}
	else
	{
		for(j=i-1;j<L.len-1;j++)
			L.data[j]=L.data[j+1];
		L.len--;
	}
}
//		<4>在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性
void insertList(list &L,elementType x)
{
	for(int i=L.len-1;i>=0;i--)
	{
		if(x<L.data[i])
		{
			L.data[i+1]=L.data[i];
		}
		else
		{
			L.data[i+1]=x;
			break;
		}
	}
	L.len++;
}
//  <5>将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数）。
// A为奇数  B为偶数
void decompositionList(list L,list &A,list &B)
{
	A.len=0;
	B.len=0;
	for(int i=0;i<L.len;i++)
	{
		if(L.data[i]%2)
			A.data[A.len++]=L.data[i];
		else
			B.data[B.len++]=L.data[i];
	}
}
//  <6>求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。
void commonList(list A,list B,list &L)
{
	L.len=0;
	int ia=0,ib=0;
	while(ia<A.len&&ib<B.len)
	{
		if(A.data[ia]<B.data[ib])
			ia++;
		else if(A.data[ia]>B.data[ib])
			ib++;
		else
			L.data[L.len++]=A.data[ia++];
	}
}
// <7>删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好。
void deleteRepeat(list &L)
{
	int i=0,j=1;
	int count=0;
	while(j<L.len)
	{
		if(L.data[i]==L.data[j])
			j++;
		else
		{
			if((i+1)!=j)
			{
				L.data[i+1]=L.data[j];
				i++;
				j++;
				count++;
			}
			else
				j++;
		}
	}
	L.len=i+1;
	printf("count=%d\n",count);
}
//************************************************//
//                      实验1.4                   //
//************************************************//
//		<1> 递增有序顺序表L1、L2，对2表进行合并，并使得合并后成为一个集合，集合的元素放回L1表中保存
void mergeList(list &L1,list L2)
{
	int i=0,j=0,k=0;
	list L;
	while(i<L1.len&&j<L2.len)
	{
		if(L1.data[i]<L2.data[j])
			L.data[k++]=L1.data[i++];
		else if(L1.data[i]>L2.data[j])
			L.data[k++]=L2.data[j++];
		else
		{
			L.data[k++]=L1.data[i++];
			L.data[k++]=L2.data[j++];
		}
	}
	while(i<L1.len)
	{
		L.data[k++]=L1.data[i++];
	}
	while(j<L1.len)
	{
		L.data[k++]=L2.data[j++];
	}
	for(i=0;i<k;i++)
	{
		L1.data[i]=L.data[i];
	}
	L1.len=k;
}
//<2>（递增有序）顺序表表示集合A、B，实现：
//C=A^B，C=AuB，C=A-B
void interseList(list A,list B,list &C)//C=A^B
{
	int ia=0,ib=0,ic=0;
	while(ia<A.len&&ib<B.len)
	{
		if(A.data[ia]<B.data[ib])
			ia++;
		else if(A.data[ia]>B.data[ib])
			ib++;
		else
		{
			C.data[ic++]=A.data[ia++];
			ib++;
		}
	}
	C.len=ic;
}
void unionList(list A,list B,list &C)//C=AuB
{
	int ia=0,ib=0,ic=0;
	while(ia<A.len&&ib<B.len)
	{
		if(A.data[ia]<B.data[ib])
			C.data[ic++]=A.data[ia++];
		else if(A.data[ia]>B.data[ib])
			C.data[ic++]=B.data[ib++];
		else
		{
			C.data[ic++]=A.data[ia++];
			ib++;
		}
	}
	while(ia<A.len)
	{
		C.data[ic++]=A.data[ia++];
	}
	while(ib<B.len)
	{
		C.data[ic++]=B.data[ib++];
	}
	C.len=ic;
}
void differenceList(list A,list B,list &C)
{
	int ia=0,ib=0,ic=0;
	while(ia<A.len&&ib<B.len)
	{
		if(A.data[ia]<B.data[ib])
			C.data[ic++]=A.data[ia++];
		else if(A.data[ia]>B.data[ib])
			C.data[ic++]=B.data[ib++];
		else
		{
			ia++;
			ib++;
		}
	}
	while(ia<A.len)
	{
		C.data[ic++]=A.data[ia++];
	}
	C.len=ic;
}
//A=A^B，A=AuB，A=A-B
void interseList(list &A,list B)//A=A^B
{
	int ia=0,ib=0,ic=0;
	while(ia<A.len&&ib<B.len)
	{
		if(A.data[ia]==B.data[ib])
		{
			A.data[ic]=B.data[ib];
			ia++;
			ic++;
		}
		else if(A.data[ia]<B.data[ib])
		{
			ia++;
		}
		else
		{
			ib++;
		}
	}
	A.len=ic;
}
void unionList(list &A,list B)//A=AuB
{
	int ia=0,ib=0,i;
	while(ia<A.len&&ib<B.len)
	{
		if(A.data[ia]>B.data[ib])
		{
			for(i=A.len-1;i>=ia;i--)
				A.data[i+1]=A.data[i];
			A.data[ia-1]=B.data[ib];
			A.len++;
		}
		else if(A.data[ia]<B.data[ib])
		{
			
			ia++;
		}
	}
	while(ib<B.len)
	{
		A.data[A.len++]=B.data[ib++];
	}
}
void differenceList(list &A,list B)
{
	int ia=0,ib=0,ic=0;
	while(ia<A.len&&ib<B.len)
	{
		if(A.data[ia]==B.data[ib])
		{
			ia++;
			ib++;
		}
		else if(A.data[ia]<B.data[ib])
			A.data[ic++]=A.data[ia++];
		else
			ib++;

	}
	A.len=ic;
}
//  <3>（递增有序）顺序表表示集合A、B，判定A是否B的子集。
bool subsetList(list A,list B)
{
	int ia=0,ib=0;
	bool iflag=false;
	while(ia<A.len)
	{
		if(A.data[ia]>B.data[ib])
		{
			ib++;
		}
		else if(A.data[ia]<B.data[ib]||ib>=B.len)
		{
			iflag=false;
			break;
		}
		else
		{
			iflag=true;
			ia++;
		}
	}
	return iflag;
}
//<4>(2011)（15 分）一个长度为L（L≥1）的升序序列S，处在第个位置的数称为S 的中位数。
//例如，若序列S1=(11, 13, 15, 17, 19)，则S1 的中位数是15。两个序列的中位数是含它们所有元素的升序序列的中位数。
//例如，若S2=(2, 4, 6, 8, 20)，则S1 和S2 的中位数是11。
int medianList(list A,list B)
{
	int ia=0,ib=0,ic=0;
	int x=(A.len+B.len)/2-1;
	while(ic<x)
	{
		if(A.data[ia]<B.data[ib])
		{
			ia++;
			ic++;
		}
		else if(A.data[ia]>B.data[ib])
		{
			ib++;
			ic++;
		}
		else
		{
			ia++;
			ib++;
			ic++;
		}
	}
	if(A.data[ia]<B.data[ib])
		return A.data[ia];
	else
		return B.data[ib];
}