#pragma once
#include <iostream>
#include <vector>
#include <string>
#define ELEMTYPE char
using namespace std;

struct BSTNode
{
	ELEMTYPE data;
	int LChild;
	int RChild;		//记录子节点在数组中的编号，-1代表无该子节点。
};

class BSTree
{
	public:	
	vector<BSTNode> v;

	void NewNode(ELEMTYPE data)
	{
		BSTNode newNode = { data, -1, -1 };
		v.push_back(newNode);
	}

	void Insert(ELEMTYPE newdata)			//新建节点插入二叉排序树中。
	{
		if (v.size() == 0)
			cout << "No Nodes." << endl;
		
		unsigned i = 0;
		while (i < v.size())
		{
			if (newdata <= v[i].data)		//新节点应在vec[i]的左子树上
			{
				if (v[i].LChild == -1)		//若该节点无左子树，则新节点应该放在此处。
				{
					v[i].LChild = v.size();
					BSTNode N = { newdata, -1, -1 };
					v.push_back(N);
					break;
				}
				else
					i = v[i].LChild;		//当前节点变为左子树根节点，继续搜索位置。
			}
			else							//新节点应在当前节点右子树上，具体放置方法同上。
			{
				if (v[i].RChild == -1)
				{
					v[i].RChild = v.size();
					BSTNode N = { newdata, -1, -1 };
					v.push_back(N);
					break;
				}
				else
					i = v[i].RChild;
			}
		}
	}
	
	void InOrderTraverse(int i)				//中序遍历该二叉搜索树，并将结果打印出来。
	{
		if (v[i].LChild != -1)
			InOrderTraverse(v[i].LChild);
		cout << v[i].data << ' ';
		if (v[i].RChild != -1)
			InOrderTraverse(v[i].RChild);
	}

	void PreOrderTraverse(int i)			//前序遍历。
	{
		cout << v[i].data << ' ';
		if (v[i].LChild != -1)
			InOrderTraverse(v[i].LChild);
		if (v[i].RChild != -1)
			InOrderTraverse(v[i].RChild);
	}

	void PostOrderTraverse(int i)			//后序遍历。
	{
		if (v[i].LChild != -1)
			InOrderTraverse(v[i].LChild);
		if (v[i].RChild != -1)
			InOrderTraverse(v[i].RChild);
		cout << v[i].data << ' ';
	}

	int Search(ELEMTYPE c)
	{
		int i = 0;
		int depth = 1;
		while (i != -1)
		{
			if (c == v[i].data)
			{
				return depth;
			}
			else if (c > v[i].data)
			{
				depth++;
				i = v[i].RChild;
			}
			else
			{
				depth++;
				i = v[i].LChild;
			}
		}
		return -1;
	}

	/*
	将该二叉搜索树打印出来,形式如下。
					a
			c
	 s
					t
			u
	*/
	void Print()
	{								
		string str = "";			
		print(0, str);				
									
	}								

	private: 
	void print(int i, string str)
	{
		if (i == -1)
			return;
		str += "    ";
		print(v[i].LChild, str);
		cout << str << v[i].data << endl;
		print(v[i].RChild, str);
	}
};
