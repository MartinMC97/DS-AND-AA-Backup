/*˫������ûд̫�࣬�ص㻹�ǲ��������*/
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

DNode *DGotoKth(DList L, int i) //����һ��ָ���i���ڵ��ָ��
{
	DNode* p = L; int j = 0;
	while (j<i) {
		p = p->Next;
		++j;
	}
	return p;
}

ElemType DGetElem(DList L, int i) //���ص�i��Ԫ��
{
	DNode* p = DGotoKth(L, i);
	return p->data;
}

void DListInsert(DList &L, ElemType e, int i) //�������i��λ�ò���Ԫ��
{
	DNode *p = DGotoKth(L, i - 1);
	if (p==NULL) exit(0);
	DNode* s = (DNode*)malloc(sizeof(DNode));
	if (!s) exit(0);
	s->data = e;
	if (p->Next == NULL)   //��pΪ�ձ�
	{
		p->Next = s; 
		s->Next = NULL; 
		s->Prev = p;
	}
	else	//��p��Ϊ�ձ�
	{
		s->Next = p->Next; s->Prev = p;
		s->Next->Prev = s;
		p->Next = s;
	}
}

void DListDelete(DList &L, int i) //ɾ�������е�i��Ԫ��
{
	DNode *p = DGotoKth(L, i - 1);
	DNode *s = p->Next;
	p->Next = s->Next;
	s->Next->Prev = p;
	free(s);
}