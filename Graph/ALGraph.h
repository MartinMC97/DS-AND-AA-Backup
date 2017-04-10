/*采用邻接表实现的一个图的结构。看了很长时间才勉强写(chao)出来,写完一脸智障。*/
#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#define ElemType char
#define MAX_NODES 10
using namespace std;

struct ArcNode 		//邻接弧。
{		
	int adjvex;			//顶点连接的另一个顶点的编号。
	ArcNode *nextArc;	//下一个邻接弧。
	int key;
};

struct Vertex
{
	ElemType data;
	ArcNode * nextArc;	//存储第一个邻接弧。邻接弧用类似于链表的方式存储。
};


class ALGraph
{
public:
	Vertex vertices[MAX_NODES];		//用一个数组存储顶点相关信息。
	int numOfNodes;
	int numOfArcs;

	ALGraph()
	{
		int i, j, k;
		cout << "Enter the number of nodes and the number of arcs:" << endl;
		cin >> numOfNodes >> numOfArcs;

		for (i = 0; i < numOfNodes; i++)
		{
			cout << "Enter the data of the vertex:" << endl;
			cin >> vertices[i].data;
			vertices[i].nextArc = NULL;
		}

		for (k = 0; k < numOfArcs; k++)
		{
			cout << "enter the two vertices:" << endl;
			cin >> i >> j;
			ArcNode * arc = new ArcNode;
			arc->adjvex = j;
			arc->nextArc = vertices[i].nextArc;
			vertices[i].nextArc = arc;
			arc = new ArcNode;
			arc->adjvex = i;
			arc->nextArc = vertices[j].nextArc;
			vertices[j].nextArc = arc;
		}
	}

	void DFSTraverse()				//深度优先遍历这个图。 采用递归的方法。
	{
		vector<int> Visited;
		for (int i = 0; i < numOfNodes; i++)
			Visited.push_back(0);
		for (int i = 0; i < numOfNodes; i++)
		{
			if(Visited[i] == 0)
				DFS(i,Visited);
		}			
	}

	void BFSTraverse()				//广度优先遍历这个图。 	非递归。
	{
		vector<int> Visited;		//用一个与原数组相同元素个数的Visited数组标记各个元素是否被访问。
		for (int i = 0; i < numOfNodes; i++)
			Visited.push_back(0);
		deque<Vertex> Q;			//使用一个队列作为辅助。
		for (int v = 0; v < numOfNodes; v++)
		{
			if (!Visited[v])
			{
				Visited[v] = 1;
				cout << vertices[v].data <<' ';
				Q.push_back(vertices[v]);
				while (!Q.empty())
				{
					Vertex ver = Q.front();
					for (ArcNode *p = ver.nextArc; p != nullptr; p = p->nextArc)
					{
						if (!Visited[p->adjvex])
						{
							Visited[p->adjvex] = 1;
							cout << vertices[p->adjvex].data <<' ';
							Q.push_back(vertices[p->adjvex]);
						}
					}
					Q.pop_front();
				}
			}
		}
	}

private:
	void DFS(int v, vector<int> &Visited)
	{
		Visited[v] = 1;
		cout << vertices[v].data <<' ';
		for (auto w = vertices[v].nextArc; w->nextArc != nullptr; w = w->nextArc)
			if (!Visited[w->adjvex])
				DFS(w->adjvex, Visited);
	}
};