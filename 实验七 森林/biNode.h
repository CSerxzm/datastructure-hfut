#ifndef _HEADERNAME_H
#define _HEADERNAME_H

typedef char elementType;

typedef struct csNode
{
	elementType data;
	struct csNode *firstChild, *nextSibling;
}csNode,*csTree;


#endif

