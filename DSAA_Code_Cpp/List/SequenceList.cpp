/*用数组实现的一个链表，没什么意思。*/
#pragma once
#include <stdlib.h>
#define LIST_SIZE 100
#define LISTINCRETMENT 10
#define ElemType int

typedef struct {
	ElemType *elem;
	int length;
	int size;
}SqList;

SqList SqListInit()
{
	SqList L;
	L.elem = (ElemType *)malloc(LIST_SIZE * sizeof(ElemType));
	L.elem = 0;
	L.size = LIST_SIZE;
	return L;
}

ElemType SqGetElem(SqList L,int i)
{
	if (i<1 || i> L.length + 1) exit(0);
	else return L.elem[i - 1];
}

int SqListInsert(SqList &L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1) return -1;
	if (L.length >= L.size)
	{
		ElemType *newbase = (ElemType *)realloc(L.elem, (L.size + LISTINCRETMENT) * sizeof(ElemType));
		if (!newbase) return -1;
		L.elem = newbase;
		L.size += LISTINCRETMENT;
	}
	ElemType *q = &(L.elem[i - 1]),*p = &(L.elem[L.length-1]);  //p指向最后一个元素，q指向插入的位置
	for (p; p >= q; p--) *(p + 1) = *p;		//从最后一个元素到插入位置的元素全部依次后移一位
	*q = e;
	L.length++;
	return 1;
 }

int SqListDelete(SqList &L, int i)
{
	if (i<1 || i>L.length + 1) return -1;
	ElemType *q = &(L.elem[i]), *p = &(L.elem[L.length - 1]);		//q指向被删除元素后一个元素，p指向末尾
	for (; q <= p; q++) *(q - 1) = *q;		//q到最后一个元素依次前移一位，第i个元素被覆盖
	L.length--;
	return 1;
}