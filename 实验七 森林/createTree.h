#include <iostream>
#include "biNode.h"
using namespace std;
//����ɭ�֣���˫�ױ�ʾ������㷨--------------------------------------------
#define MAXLEN 100

typedef char elementType;
   //���Ľ��ṹ
typedef struct pNode
{
	elementType data;   //���������
	int parent;         //�����ָ�루�±꣩

}PTNode;

    //˫�ױ�ʾ������ɭ�֣��ṹ
typedef struct pTree
{
	PTNode node[MAXLEN];   //�������
	int n;              //�������
}pTree;


//��ʼ����
void initialTree(pTree &T)
{
	T.n=0;   //�������ʼ��Ϊ0
}

//�����Ƚ��
bool getAncestor(pTree &T, elementType x)
{
	int w=0;
	elementType y;
	y=x;
	
	for(w=0;w<T.n;w++)
	{
		if(T.node[w].data==y)
		{
			w=T.node[w].parent;     //ȡ��x�ĸ����
			y=T.node[w].data;
			cout<<y<<"\t";
			break;
		}
	}
	if(w>=T.n)    //x�������ϣ�����false
		return false;
	
	             //����x�����֮����������Ƚ��
	while(w!=-1)
	{
		if(T.node[w].data==y)
		{
			w=T.node[w].parent;     //ȡ��w��˫�׽���±�
			y=T.node[w].data;
			cout<<y<<"\t";	
		}
		else
			w=(w+1)%T.n;
	}
	return true;
}

//���ӽ��
void getChildren(pTree &T, elementType x)
{
	int i,w;
	for(w=0;w<T.n;w++)     //��ȡx�ڽ�������е��±�
	{
		if(T.node[w].data==x)
			break;
	}
	if(w>=T.n)  //x���ڱ���
		return;
	for(i=0;i<T.n;i++)
	{
		if(T.node[i].parent==w)   //�ҵ��ӽ�㣬��ӡ
			cout<<T.node[i].data<<"\t";	
	}
	cout<<endl;
}

//�������
int firstChild(pTree &T,int v)    //�����±�Ϊv�Ľ��ĵ�һ�����ӽ���±�
{
	int w;
	if(v==-1)
		return -1;

	for(w=0;w<T.n;w++)
	{
		if(T.node[w].parent==v)
			return w;
	}
	return -1;
}
int nextSibling(pTree &T,int v,int w)  //����v���±�λ��w֮�����һ�����ӽ���±�
{
	int i;
	for(i=w+1;i<T.n;i++)
		if(T.node[i].parent==v)
			return i;
	return -1;
}
void preOrder(pTree &T,int v)
{
	int w;
	cout<<T.node[v].data<<"\t";

	w=firstChild(T,v);
	while(w!=-1)
	{

		preOrder(T,w);
		w=nextSibling(T,v,w);	
	}
}


void preTraverse(pTree &T)
{
	int i;
	int visited[MAXLEN];
	for(i=0;i<T.n;i++)
	{
		visited[i]=0;	
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0;i<T.n;i++)
	{
		if(T.node[i].parent==-1)
			preOrder(T,i);
	}	
}

void postOrder(pTree &T,int v)
{
	int w;
	w=firstChild(T,v);
	while(w!=-1)
	{
		postOrder(T,w);
		w=nextSibling(T,v,w);	
	}
	cout<<T.node[v].data<<"\t";   //���ʸ����
}

void postTraverse(pTree &T)
{
	int i;
	int visited[MAXLEN];
	for(i=0;i<T.n;i++)
	{
		visited[i]=0;	
	}
	    //��������㣬������ɭ�֣��ж�������
	for(i=0;i<T.n;i++)
	{
		if(T.node[i].parent==-1)
			postOrder(T,i);
	}
}

//��ӡ��
void printTree(pTree &T)
{
	int i;
	cout<<"�±�\t���\t˫��"<<endl;
	for(i=0;i<T.n;i++)
		cout<<i<<"\t"<<T.node[i].data<<"\t"<<T.node[i].parent<<endl;
}

//˫�ױ�ʾ���塢�㷨����---------------------------------------------------------------

//�����ֵ������ʾ���塢�����㷨��ʼ---------------------------------------------------
    //����ɭ�֣��ĺ����ֵ������ʾ


//ɾ���ַ������ַ�������߿ո�
void strLTrim(char* str)
{
	int i,j;
	int n=0;
	n=strlen(str)+1;
	for(i=0;i<n;i++)
	{
		if(str[i]!=' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	    //�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for(j=0;j<n;j++)
	{
		str[j]=str[i];
		i++;
	}
}


//****************** �ļ�����˫�ױ�ʾ������ɭ�֣�********************//
//* �������ܣ����ı��ļ�����˫�ױ�ʾ��ͼ                            *//
//* ��ڲ���  char fileName[]�������ļ���                           *//
//* ���ڲ�����pTree &T������������                                  *//
//* �� �� ֵ��bool��true�����ɹ���false����ʧ��                     *//
//* �� �� ����CreateTreeFromFile(char fileName[], pTree &T)         *//
//* ��ע��������ʹ�õ������ļ���ʽ�Աߣ����Ӷԣ�Ϊ��������          *//
//*******************************************************************//
bool CreateTreeFromFile(char fileName[], pTree &T)
{
	FILE* pFile;     //����˳�����ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

    int i=0,j=0;


	pFile=fopen(fileName,"r");
	if(!pFile)
	{
		printf("�����ļ�%s��ʧ�ܡ�\n",fileName);
		return false;
	}
	
	while(fgets(str,1000,pFile)!=NULL)  //�������к�ע����
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //����ע����
			continue;
		else  //��ע���С��ǿ��У�����ѭ��
			break;
	}

    //ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
	if(strstr(str,"Tree or Forest")==NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}


	//��ȡ������ݣ���str����������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;		
		else  //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

	//������ݴ������Ľ������		
	char* token=strtok(str," ");
	int nNum=0;	
	while(token!=NULL)
	{
		T.node[nNum].data=*token;
		T.node[nNum].parent=-1;       //�����ָ���ʼ��Ϊ-1
		
		token = strtok( NULL, " ");
        
		nNum++;
	}
	
    //ѭ����ȡ�ߣ����Ӷӣ�����
	int nP;  //����������±�
	int nC;  //�ӽ�������±�

	elementType Nf,Ns; //���ӽ��Ե��������
	while(fgets(str,1000,pFile)!=NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0]=='\n')  //���У�������ȡ��һ��
			continue;
		
		strncpy(strTemp,str,2);
		if(strstr(strTemp,"//")!=NULL)  //ע���У�������������ȡ��һ��
			continue;

		char* token=strtok(str," ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���
		
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf=*token;  //��ȡ�����
		
		token = strtok( NULL, " ");  //��ȡ��һ���Ӵ������ӽ��
		if(token==NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ���ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}

		Ns=*token;  //��ȡ�ߵĵڶ�����㣨�ӽ�㣩
            //ȡ�ø�����±�		
		for(nP=0;nP<nNum;nP++)
		{
			if(T.node[nP].data==Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
           //��ȡ�ӽ��������±�		
		for(nC=0;nC<nNum;nC++)
		{
			if(T.node[nC].data==Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		T.node[nC].parent=nP;        //nC�ĸ������±�ΪnP
	}

    T.n=nNum;  //���Ľ�����������������ʵ�ʴ�С

	fclose(pFile); //�ر��ļ�
	return true;
}

//����˫�ױ�ʾ�У��±�w����һ���ֵܽ�㣬�����ֵܽ����±�
int next(pTree T,int w)  
{
	int i;
	for(i=w+1;i<T.n;i++)
	{
		if(T.node[w].parent==T.node[i].parent)
			return i;	
	}
	return -1;
}

//�ݹ鴴��һ�ú����ֵ������ʾ����
void create(csNode *&T,pTree &T1,int v)
{
	int w;
	T=new csNode;
	T->data=T1.node[v].data;
	T->firstChild=NULL;
	T->nextSibling=NULL;
	w=firstChild(T1,v);  //����v�ĵ�һ�����ӽ��
	if(w!=-1)
	{
		create(T->firstChild,T1,w);
	}
	
	w=next(T1,v);       //����v����һ���ֵܽ��
	if(w!=-1)
	{
		create(T->nextSibling,T1,w);
	}	
}

//��˫�ױ�ʾ������ɭ�֣����������ֵ������ʾ������ɭ�֣�
void createCsTree(csNode *&T,pTree T1)
{
	int i;
	//����T1�ĵ�һ�������
	for(i=0;i<T1.n;i++)
	{
		if(T1.node[i].parent==-1)   //�ҵ���һ�������
			break;		
	}
	if(i<T1.n)
		create(T,T1,i);
}

//�����ֵ������ʾ���塢�����㷨����---------------------------------------------------