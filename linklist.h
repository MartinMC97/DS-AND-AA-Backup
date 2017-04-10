/*�����ʵ�֡�*/
#pragma once
#define ElemType int
#include <stdlib.h>

typedef struct Node{
	ElemType data;
	Node *Next;
} Node, *LinkList;

Node *GotoKth(LinkList L, int i) //����һ��ָ���i���ڵ��ָ��
{
	Node* p = L; int j = 0;
	while (j<i) {
		p = p->Next;
		++j;
	}
	return p;
}

int IsEmpty(LinkList L) //��������Ƿ�Ϊ��
{
	return (L->Next == NULL);
}

ElemType GetElem(LinkList L, int i) //���ص�i��Ԫ��
{
	Node* p = GotoKth(L, i);
	return p->data;
}

void ListInsert(LinkList &L, ElemType e, int i) //�������i��λ�ò���Ԫ��
{
	Node *p = GotoKth(L, i - 1);
	if (!p) exit(0);
	Node* s = (Node*)malloc(sizeof(Node));
	if (!s) exit(0);
	s->data = e;
	s->Next = p->Next;
	p->Next = s;
}

void ListDelete(LinkList &L, int i) //ɾ�������е�i��Ԫ��
{
	Node *p = GotoKth(L, i - 1);
	Node *s = p->Next;
	p->Next = s->Next;
	free(s);
}

void ListUnion(LinkList &La, LinkList Lb) //�ϲ���������
{
	LinkList p = La;
	while (p->Next != NULL) p = p->Next;
	p->Next = Lb;
}