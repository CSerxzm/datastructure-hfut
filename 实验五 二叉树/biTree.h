#include <iostream>
using namespace std;

typedef char elementType;
typedef struct lBNode
{
	elementType data;
	struct lBNode *lchild,*rchild;
}BiNode;

bool ReadFileToArray(char fileName[],char strLine[100][3],int &nArrLen)
{
	FILE *fp;
	char str[1000];
	fp=fopen(fileName,"r");
	if(!fp)
	{
		cout<<"打开文件失败."<<endl;
		return false;
	}
	
	if(fgets(str,1000,fp)!=NULL)
	{
		if(strcmp(str,"BinaryTree\n")!=0)
		{
			cout<<"格式错误."<<endl;
			fclose(fp);
			return false;
		}
	}
	nArrLen=0;
	while(fscanf(fp,"%c %c %c\n",&strLine[nArrLen][0],&strLine[nArrLen][1],&strLine[nArrLen][2])!=EOF)
	{
		nArrLen++;
	}
	fclose(fp);
	return true;
}

bool CreateBiTreeFromFile(BiNode *&pBT,char strLine[100][3],int nLen,int &nRow)
{
	if( (nRow>=nLen) || (nLen==0) )
		return false;
	pBT = new BiNode;
	pBT->data=strLine[nRow][0];
	pBT->lchild = NULL;
	pBT->rchild = NULL;
	
	int nRowNext = nRow;
	if(strLine[nRowNext][1]=='1')
	{
		nRow++;
		CreateBiTreeFromFile(pBT->lchild,strLine,nLen,nRow);
	}
	if(strLine[nRowNext][2]=='1')
	{
		nRow++;
		CreateBiTreeFromFile(pBT->rchild,strLine,nLen,nRow);
	}

	return true;

}

void DestroyBiTree(BiNode *pBT)
{
	if(pBT)
	{
		DestroyBiTree(pBT->lchild);
		DestroyBiTree(pBT->rchild);
		delete pBT;
	}
}

void InTraverse(BiNode *T)
{
	if(T)
	{
		InTraverse(T->lchild);
		cout<<T->data; 
		InTraverse(T->rchild);		
	}
}

void PreOrderTraverse(BiNode *T)
{
	if(T)
	{
		cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);		
	}
}

void InOrderTraverse(BiNode *T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data; 
		InOrderTraverse(T->rchild);		
	}
}

void PostOrderTraverse(BiNode *T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data; 		
	}
}

void GetNodeNumber(BiNode *T,int &num)
{
	if(T)
	{
		GetNodeNumber(T->lchild,num);
		num++;
		GetNodeNumber(T->rchild,num);
	}
}

int BiTreeDepth(BiNode *T)
{
	int m,n;
	if(!T)
		return 0;
	else
	{
		m=BiTreeDepth(T->lchild);
		n=BiTreeDepth(T->rchild);
		return (m>n ? m:n)+1;
	}
}

void BiTreeLeaves(BiNode *T,int &num)
{
	if(!T->lchild&&!T->rchild)
		num++;
	if(T->rchild)
		BiTreeLeaves(T->rchild,num);
	if(T->lchild)
		BiTreeLeaves(T->lchild,num);
}

//设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数。 
void InTraverse(BiNode *T,int num)
{
	if(T)
	{
		num++;
		InTraverse(T->lchild,num);
		cout<<T->data<<"  "<<num<<endl; 
		InTraverse(T->rchild,num);		
	}
}


void creatSubTree(BiNode *q,int k)
{
	BiNode *u;
	elementType x;
	cin>>x;
	if(x!='/')
	{
		u = new BiNode;
		u->data=x;
		u->lchild=NULL;
		u->rchild=NULL;
		if(k==1)
			q->lchild=u;
		if(k==2)
			q->rchild=u;
		createSubTree(u,1);
		createSubTree(u,1);
	}
}

void creatBiTree(BiNode *&BT)
{
	BiNode *p;
	char x;
	cout<<"按照先序输入二叉树(/表示没有子树):";
	cin>>x;
	if(x=='/')
		return ;
	BT=new BiNode;
	BT->data=x;
	BT->lchild=NULL;
	BT->rchild=NULL;
	p=BT;
	creatSubTree(p,1);
	creatSubTree(p,2);
}