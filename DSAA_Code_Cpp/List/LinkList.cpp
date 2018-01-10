/*链表的实现。*/
#pragma once
#define ElemType int
#include <stdlib.h>

typedef struct Node{
	ElemType data;
	Node *Next;
} Node, *LinkList;

Node *GotoKth(LinkList L, int i) //返回一个指向第i个节点的指针
{
	Node* p = L; int j = 0;
	while (j<i) {
		p = p->Next;
		++j;
	}
	return p;
}

int IsEmpty(LinkList L) //检查链表是否为空
{
	return (L->Next == NULL);
}

ElemType GetElem(LinkList L, int i) //返回第i个元素
{
	Node* p = GotoKth(L, i);
	return p->data;
}

void ListInsert(LinkList &L, ElemType e, int i) //在链表第i个位置插入元素
{
	Node *p = GotoKth(L, i - 1);
	if (!p) exit(0);
	Node* s = (Node*)malloc(sizeof(Node));
	if (!s) exit(0);
	s->data = e;
	s->Next = p->Next;
	p->Next = s;
}

void ListDelete(LinkList &L, int i) //删除链表中第i个元素
{
	Node *p = GotoKth(L, i - 1);
	Node *s = p->Next;
	p->Next = s->Next;
	free(s);
}

void ListUnion(LinkList &La, LinkList Lb) //合并两个链表
{
	LinkList p = La;
	while (p->Next != NULL) p = p->Next;
	p->Next = Lb;
}