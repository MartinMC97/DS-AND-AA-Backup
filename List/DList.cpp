/*双向链表。没写太多，重点还是插入操作。*/
#pragma once
#include <stdlib.h>
#define ElemType int

typedef struct DNode {
	ElemType data;
	DNode *Prev;
	DNode *Next;
}*DList;

int DIsEmpty(DList L)
{
	return (L->Next == NULL);
}

DNode *DGotoKth(DList L, int i) //返回一个指向第i个节点的指针
{
	DNode* p = L; int j = 0;
	while (j<i) {
		p = p->Next;
		++j;
	}
	return p;
}

ElemType DGetElem(DList L, int i) //返回第i个元素
{
	DNode* p = DGotoKth(L, i);
	return p->data;
}

void DListInsert(DList &L, ElemType e, int i) //在链表第i个位置插入元素
{
	DNode *p = DGotoKth(L, i - 1);
	if (p==NULL) exit(0);
	DNode* s = (DNode*)malloc(sizeof(DNode));
	if (!s) exit(0);
	s->data = e;
	if (p->Next == NULL)   //若p为空表
	{
		p->Next = s; 
		s->Next = NULL; 
		s->Prev = p;
	}
	else	//若p不为空表
	{
		s->Next = p->Next; s->Prev = p;
		s->Next->Prev = s;
		p->Next = s;
	}
}

void DListDelete(DList &L, int i) //删除链表中第i个元素
{
	DNode *p = DGotoKth(L, i - 1);
	DNode *s = p->Next;
	p->Next = s->Next;
	s->Next->Prev = p;
	free(s);
}