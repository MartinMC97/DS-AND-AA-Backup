#pragma once
#define ElemType int
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	ElemType data;
	Node *Next;
} *LinkStack;     //栈指针指向栈最上面的元素

LinkStack Stackinit()
{
	LinkStack s = new Node;
	s->Next = NULL;
	return s;
}

int IsEmpty(LinkStack s)
{
	return s->Next == NULL;
}

void Push(LinkStack s, ElemType e)
{
	Node *tmp = new Node;
	if (tmp == NULL) 
	{
		printf("Out of space.\n"); 
		exit(0); 
	}
	else 
	{ 
		tmp->data = e;
		tmp->Next = s->Next;
		s->Next = tmp;
	}
}

ElemType Pop(LinkStack s)
{
	if (IsEmpty(s)) {
		printf("Empty Stack.\n"); exit(0);
	}
	else {
		auto tmp = s->Next;
		s->Next = tmp->Next;
		ElemType e = tmp->data;
		free(tmp);
		return e;
	}
}

ElemType Top(LinkStack s) {
	if (IsEmpty(s)) {
		printf("Empty Stack.\n"); exit(0);
	}
	else return s->Next->data; 
}

void MakeEmpty(LinkStack s)
{
	if (s == NULL)
	{
		printf("Invalid stack pointer.\n"); exit(0);
	}
	else
	{
		while (s->Next != NULL)
			Pop(s);
	}
}