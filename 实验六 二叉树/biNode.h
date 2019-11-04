#ifndef _HEADERNAME_H
#define _HEADERNAME_H

typedef char elementType;
typedef struct lBNode
{
	elementType data;
	struct lBNode *lchild,*rchild;
}BiNode,*TriTree;

#endif

