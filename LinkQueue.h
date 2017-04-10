/*���е�����ʵ��*/
#pragma once
#include <iostream>
#include <stdlib.h>
#define ElemType int
using namespace std;

struct QNode {
	ElemType data;
	QNode * Next;
};

struct LinkQueue				
{
	QNode *front; //front->Next �Ƕ��еĵ�һ���ڵ㡣
	QNode *rear;
};

LinkQueue LinkQueueInit()		//���е�����ʵ�ֳ�ʼ����
{
	QNode *qtmp = (QNode*)malloc(sizeof(QNode));
	if (qtmp == NULL) {
		cout << "Error allocating space." << endl; exit(0);
	}
	LinkQueue q;
	q.front = qtmp;
	q.rear = qtmp;
	q.front->Next = NULL;
	return q;
}

void LinkQueueDestroy(LinkQueue &Q)		//����������С�
{
	while (Q.front)
	{
		Q.rear = Q.front->Next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

void EnQueue(LinkQueue &Q, ElemType e)	//Ԫ����ӡ�
{
		QNode *qtmp = (QNode*)malloc(sizeof(QNode));
		if (qtmp == NULL) {
			cout << "Error allocating space." << endl; exit(0);
		}
		qtmp->data = e; qtmp->Next = NULL;
		Q.rear->Next = qtmp;
		Q.rear = qtmp;
}

ElemType DeQueue(LinkQueue &Q)			//Ԫ�س��ӡ�
{
	QNode *qtmp = (QNode*)malloc(sizeof(QNode));
	if (qtmp == NULL) {
		cout << "Error allocating space." << endl; exit(0);
	}
	qtmp = Q.front; 
	ElemType tmp = qtmp->Next->data;
	Q.front = Q.front->Next;
	free(qtmp);
	return tmp;
}

void printQueue(LinkQueue Q)			//������ӡ���С�
{
	QNode *qtmp = Q.front->Next;
	while (qtmp != Q.rear)
	{
		cout << qtmp->data << ' ';
		qtmp = qtmp->Next;
	}
	cout << qtmp->data << ' ';
}