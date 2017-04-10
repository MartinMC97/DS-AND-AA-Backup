/*采用邻接矩阵实现的一个图。只写了建立和输出两个方法。*/
#pragma once
#include <iostream>
#include <stdlib.h>
#define ElemType char
#define VerNum 8

using namespace std;

typedef enum { DG, UDG, DN, UDN } GraphKind;

struct Graph
{
	int GKind;
	ElemType data[VerNum];
	int AdjMatrix[VerNum][VerNum];
};

Graph GraphInit()
{
	Graph g; int flag;
	cout << "Enter the type: ";
	cin >> flag;
	g.GKind = (GraphKind)flag;
	cout << "Enter the vertices:" << endl;
	for (int i = 0; i < VerNum; i++)
		cin >> g.data[i];
	cout << "Enter the AdjMatrix:" << endl;
	for (int i = 0; i < VerNum; i++)
		for (int j = 0; j < VerNum; j++)
			cin >> g.AdjMatrix[i][j];
	return g;
}

void printGraph(Graph g)
{
	cout << "Result:" << endl;
	for (int i = 0; i < VerNum; i++)
		cout << g.data[i] << ' ';
	cout << endl;
	for (int i = 0; i < VerNum; i++)
	{
		for (int j = 0; j < VerNum; j++)
			cout << g.AdjMatrix[i][j] << ' ';
		cout << endl;
	}
}
