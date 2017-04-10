/*队列的数组实现*/
#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

struct SqQueue {
	int capacity;
	int size;
	int front;
	int rear;
	ElemType *Arr;
};

int Next(int sqrear, SqQueue sq)	//获得sqrear后一个元素的编号。
{
	if (++sqrear == sq.capacity)	//当sqrear指向最后时，sqrear的后一个元素的编号则回到开头。
		sqrear = 0;					//以充分利用数组空间。
	return sqrear;
}

void MakeEmpty(SqQueue sq)
{
	sq.size = 0;
	sq.front = 1;
	sq.rear = 0;
}

SqQueue SqQueueInit(int cap)		//分配一个容量为cap的数组队列。
{
	SqQueue sq;
	sq.Arr = (ElemType*)malloc(cap * sizeof(ElemType));
	if (sq.Arr == NULL) {
		cerr << "Error allocating space.";
		exit(0);
	}
	else
	{
		MakeEmpty(sq);
		sq.capacity = cap;
	}
	return sq;
}

int IsEmpty(SqQueue sq)
{
	return sq.size == 0;
}

void EnQueue(SqQueue sq, ElemType e)
{
	if (sq.size == sq.capacity) cout << "Full Queue.";
	else {
		sq.size++;
		Next(sq.rear, sq);
		sq.Arr[sq.rear] = e;
	}
}

ElemType DeQueue(SqQueue sq)
{
	ElemType tmp = 0;
	if (IsEmpty(sq)) cerr << "Empty Queue.";
	else {
		tmp = sq.Arr[sq.front];
		sq.front++;
		sq.size--;
	}
	return tmp;
}