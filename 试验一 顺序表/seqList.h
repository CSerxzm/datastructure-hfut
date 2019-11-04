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
	printf("������Ԫ����-1����.");
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
//                      ʵ��1.3                   //
//************************************************//
//		<1>��˳����е�i��Ԫ�أ��粻���ڣ�����
bool getElement(list L,int i,elementType &x)
{
	if(i<=0||i>L.len)
	{
		printf("������������.\n");
		return false;
	}
	else
	{
		x=L.data[i-1];
		return true;
	}
}
//		<2>�ڵ�i���ڵ�ǰ������ֵΪx�Ľڵ�
void insertList(list &L,int i,elementType x)
{
	int j;
	if(i<=0||i>L.len+1)
	{
		printf("������������.");
	}
	else
	{
		for(j=L.len-1;j>=i-1;j--)
			L.data[j+1]=L.data[j];
		L.data[i-1]=x;
		L.len++;
	}
}
//		<3>ɾ����i���ڵ�
void deleteList(list &L,int i)
{
	int j;
	if(i<=0||i>L.len)
	{
		printf("������������.\n");
	}
	else
	{
		for(j=i-1;j<L.len-1;j++)
			L.data[j]=L.data[j+1];
		L.len--;
	}
}
//		<4>��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������
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
//  <5>��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż������
// AΪ����  BΪż��
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
//  <6>��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�
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
// <7>ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ��������á�
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
//                      ʵ��1.4                   //
//************************************************//
//		<1> ��������˳���L1��L2����2����кϲ�����ʹ�úϲ����Ϊһ�����ϣ����ϵ�Ԫ�طŻ�L1���б���
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
//<2>����������˳����ʾ����A��B��ʵ�֣�
//C=A^B��C=AuB��C=A-B
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
//A=A^B��A=AuB��A=A-B
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
//  <3>����������˳����ʾ����A��B���ж�A�Ƿ�B���Ӽ���
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
//<4>(2011)��15 �֣�һ������ΪL��L��1������������S�����ڵڸ�λ�õ�����ΪS ����λ����
//���磬������S1=(11, 13, 15, 17, 19)����S1 ����λ����15���������е���λ���Ǻ���������Ԫ�ص��������е���λ����
//���磬��S2=(2, 4, 6, 8, 20)����S1 ��S2 ����λ����11��
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