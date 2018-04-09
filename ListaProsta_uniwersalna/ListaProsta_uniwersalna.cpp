// ListaProsta_uniwersalna.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include "global.h"

#define PRINT

void PrintList(ListItem* pList, int nLineSize);
int comp(const void*, const void*);

int main()
{
	ListItem* pTest = MakeEmptyList();
	ListInfo* pInfo1 = (ListInfo*)malloc(sizeof(ListInfo));
	memset(pInfo1, 0, sizeof(ListInfo));
	pInfo1->nKey = 25;
	InsertFront(pTest, pInfo1);
	ListInfo* pInfo2 = (ListInfo*)malloc(sizeof(ListInfo));
	memset(pInfo2, 0, sizeof(ListInfo));
	pInfo2->nKey = 50;
	InsertFront(pTest, pInfo2);
	ListInfo* pInfo3 = (ListInfo*)malloc(sizeof(ListInfo));
	memset(pInfo3, 0, sizeof(ListInfo));
	pInfo3->nKey = 20;
	InsertFront(pTest, pInfo3);
	ListInfo* pInfo4 = (ListInfo*)malloc(sizeof(ListInfo));
	memset(pInfo4, 0, sizeof(ListInfo));
	pInfo4->nKey = 70;
	InsertFront(pTest, pInfo4);
	ListInfo* pInfo5 = (ListInfo*)malloc(sizeof(ListInfo));
	memset(pInfo5, 0, sizeof(ListInfo));
	pInfo5->nKey = 80;
	InsertFront(pTest, pInfo5);
	ListInfo* pInfo6 = (ListInfo*)malloc(sizeof(ListInfo));
	memset(pInfo6, 0, sizeof(ListInfo));
	pInfo6->nKey = 45;
	InsertFront(pTest, pInfo6);

	ListInfo* pInfo7 = (ListInfo*)malloc(sizeof(ListInfo));
	memset(pInfo7, 0, sizeof(ListInfo));
	pInfo7->nKey = 700;
	
	
	#ifdef PRINT
	PrintList(pTest, 2);
	#endif

	SortList(pTest, comp);

	#ifdef PRINT
	PrintList(pTest, 2);
	#endif

	ListItem* pPrev = NULL;

	Insert(Find(pTest, pInfo6, &pPrev, comp), pInfo7);

	#ifdef PRINT
	PrintList(pTest, 2);
	#endif

	Remove(pPrev);

	#ifdef PRINT
	PrintList(pTest, 2);
	#endif

	RemoveFront(pTest);

	#ifdef PRINT
	PrintList(pTest, 2);
	#endif

	Remove(pTest->m_pNext->m_pNext);

	PrintList(pTest, 2);
	FreeList(pTest);
	DelList(&pTest);
	system("PAUSE");
	return 0;

}

void PrintList(ListItem* pList, int nLineSize)
{
	ListItem* q = pList->m_pNext;
	int i = 1;
	while (q)
	{
		printf(" %d", q->m_pInfo->nKey);
		q = q->m_pNext;
		if (i++%nLineSize == 0)
				printf("\n");
	}
	printf("\n\n");
}

int comp(const void* p1, const void* p2)
{
	if (((LISTINFO*)p1)->nKey < ((LISTINFO*)p2)->nKey)
	{
		return -1;
	}
	else if (((LISTINFO*)p1)->nKey == ((LISTINFO*)p2)->nKey)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
