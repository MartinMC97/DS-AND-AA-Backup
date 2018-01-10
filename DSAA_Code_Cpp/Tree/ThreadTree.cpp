/*线索二叉树相关。继续懵逼。*/
#include <iostream>
#include <stdlib.h>
#define ElemType char
#define LINK 0
#define THREAD 1
using namespace std;

struct ThrNode {
	ElemType data;
	ThrNode *lchild, *rchild;
	int LTag, RTag;
};

typedef ThrNode* ThrTree;

void ThrTreeInit(ThrTree &T)
{
	ElemType c;
	cin >> c;
	if (c == '#')
		T = NULL;
	else
	{
		T = (ThrTree)malloc(sizeof(ThrNode));
		T->lchild = NULL; T->rchild = NULL; T->LTag = LINK; T->RTag = LINK;
		if (!T) exit(0);
		T->data = c;
		ThrTreeInit(T->lchild);
		if (T->lchild)
			T->LTag = LINK;
		ThrTreeInit(T->rchild);
		if (T->rchild)
			T->RTag = LINK;
	}
}

void InThread(ThrNode *p, ThrNode *pre)
{
	if (p)
	{
		InThread(p->lchild, pre);
		if (p->lchild != NULL)
		{
			p->LTag = THREAD;
			p->lchild = pre;
		}
		if (pre->rchild != NULL)
		{
			pre->RTag = THREAD;
			pre->rchild = p;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}

void InOrderThreading(ThrTree &Thr, ThrTree T)
{
	ThrNode *pre;
	Thr = (ThrTree)malloc(sizeof(ThrNode));
	if (!Thr) exit(0);
	Thr->LTag = LINK; Thr->RTag = THREAD;
	Thr->rchild = Thr;

	if (!T) 		//The tree is empty.
		Thr->lchild = Thr;
	else
	{
		Thr->lchild = T; pre = Thr;
		InThread(T, pre);
		pre->rchild = Thr; pre->RTag = THREAD;
		Thr->rchild = pre;
	}
}

void InThreadTraverse(ThrTree T)
{
	ThrNode *p = T->lchild;
	while (p != T)
	{
		while (p->LTag == LINK)
			p = p->lchild;
		cout << p->data << ' ';
		while (p->RTag == THREAD && p->rchild != T)
		{
			p = p->rchild;
			cout << p->data << ' ';
		}
		p = p->rchild;
	}
}