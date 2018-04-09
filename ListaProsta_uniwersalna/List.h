#ifndef _LIST_INCLUDE_
#define _LIST_INCLUDE_
#include "global.h"

typedef struct tagListItem
{
	ListInfo* m_pInfo;
	tagListItem* m_pNext;

}ListItem;


ListItem* MakeEmptyList();
int IsEmpty(ListItem* pList);
ListItem* Front(ListItem* pList); 
void Insert(ListItem* pAfter, LISTINFO* m_pInfo);
void InsertFront(ListItem* pList, LISTINFO* m_pInfo); 
void Remove(ListItem* pAfter);
void RemoveFront(ListItem* pList); 
void FreeList(ListItem* pList);
void DelList(ListItem** pList);
ListItem* Find(ListItem* pList,const void* , ListItem** pPrev, int (__cdecl *comp)(const void*, const void*));
void SortList(ListItem* pList, int(__cdecl *comp)(const void*, const void*));


#endif
