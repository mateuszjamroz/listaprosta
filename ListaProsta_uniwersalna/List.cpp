#include <iostream>
#include <stdlib.h>
#include "List.h"
#include "global.h"

using namespace std;


ListItem* MakeEmptyList()
{
	ListItem* pList= (ListItem*)malloc(sizeof(ListItem));
	if (!pList)
	{
		printf("ERROR : there is no memory");
		return NULL;
	}
	memset(pList, 0, sizeof(ListItem));
	//pList->m_pInfo = NULL;
	//->m_pNext = NULL;
	return pList;
}


int IsEmpty(ListItem* pList)
{
	return !(pList->m_pNext);
}

ListItem* Front(ListItem* pList)
{
//	if (!IsEmpty(pList))
		return pList->m_pNext;
//	else
	//	return NULL;
}

void Insert(ListItem* pAfter, LISTINFO* Info)
{
	ListItem* q = (ListItem*)malloc(sizeof(ListItem));
	if (!q)
	{
		printf("ERROR : there is no memory");
		return;
	}
	memset(q, 0, sizeof(ListItem));
	q->m_pInfo = Info;
	q->m_pNext = pAfter->m_pNext;
	pAfter->m_pNext = q;
}

void InsertFront(ListItem* pList, LISTINFO* Info)
{
	Insert(pList, Info);
}


void Remove(ListItem* pAfter)
{
	ListItem* q = (ListItem*)malloc(sizeof(ListItem));
	if (!q)
	{
		printf("ERROR : there is no memory");
		return;
	}
	memset(q, 0, sizeof(ListItem));
	q = pAfter->m_pNext;
	pAfter->m_pNext = q->m_pNext;
	free(q->m_pInfo);//!!!!!!!!!!!!!
	free(q);
}

void RemoveFront(ListItem* pList)
{
	Remove(pList);
}

void FreeList(ListItem* pList)
{
	while (!IsEmpty(pList))
	{
		RemoveFront(pList);
	}
}

void DelList(ListItem** pList)
{

		FreeList(*pList);
		free(*pList);
		*pList = NULL;
}

ListItem* Find(ListItem* pList,const void* x , ListItem** pPrev, int(__cdecl *comp)(const void*, const void*))
{
	ListItem* q = pList->m_pNext;
	*pPrev = pList;
	
	while( q )
	{
		if (!(comp(q->m_pInfo, x))) //porownanie
		   return q;
		*pPrev = q;
		q = q->m_pNext;
	}
	pPrev = NULL;
	return NULL;
	
}



void SortList(ListItem* pList, int(__cdecl *comp)(const void*, const void*))
{
	
	ListItem* pBeg = pList;
	ListItem* temp = NULL;
	while (pBeg->m_pNext)
	{
		ListItem* pMin = pBeg;
		ListItem* p = pBeg->m_pNext;
		while (p->m_pNext)
		{
			if (comp(p->m_pNext->m_pInfo, pMin->m_pNext->m_pInfo) == -1) //wyszukuje element najmniejszy
			{
				pMin = p;
			}
			p = p->m_pNext;
		}
		if (pMin != pBeg) //przewiazanie
		{
			temp = pMin->m_pNext->m_pNext;
			pMin->m_pNext->m_pNext = pBeg->m_pNext;
			pBeg->m_pNext = pMin->m_pNext;
			pMin->m_pNext = temp;
		}
		pBeg = pBeg->m_pNext;
		}
}


