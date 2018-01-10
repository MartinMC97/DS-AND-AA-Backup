#pragma once
#include <stdlib.h>
#include <stdio.h>
#define EMPTY -1
#define ElemType int


typedef struct StackRecord {
	int Capacity;			//栈容量
	int TopOfStack;			//栈顶元素编号
	ElemType *Arr;
} *SqStack;

SqStack SqStackInit(int len)  
{
	SqStack s = (SqStack) malloc(sizeof(StackRecord));
	if (s == NULL) exit(0);
	s->Arr = (ElemType *)malloc(sizeof(ElemType) * len);
	if (s->Arr == NULL) exit(0);
	s->Capacity = len;
	s->TopOfStack = EMPTY;  //栈顶元素位置为-1，即栈为空
	return s;
}

void FreeStack(SqStack s)
{
	if (s!=NULL)
	{
		free(s->Arr);
		free(s);
	}
	else printf("The stack is already empty.\n");
}

void SqPush(SqStack s, ElemType e)
{
	if (s->TopOfStack + 1 == s->Capacity) {
		printf("Stack Full.\n"); exit(0);
	}
	else s->Arr[++s->TopOfStack] = e; //栈顶编号+1，并赋值为e
}

ElemType SqPop(SqStack s)
{
	ElemType e;
	if (s->TopOfStack == EMPTY) {
		printf("Stack Empty.\n");
		exit(0);
	}
	else
	{
		e = s->Arr[s->TopOfStack];
		s->TopOfStack--;
	}
	return e;
}