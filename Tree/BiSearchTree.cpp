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

	bool Copy(BSTNode node)
	{
		this->data = node.data;
		this->LChild = node.LChild;
		this->RChild = node.RChild;
	}
};

const BSTNode NotFound = { -1, -1, -1 };


class BSTree
{
public:
	vector<BSTNode> vec;
	const BSTNode NotFound = { -1, -1, -1 };

	void NewNode(ELEMTYPE data)
	{
		BSTNode newNode = { data, -1, -1 };
		vec.push_back(newNode);
	}

	BSTNode Find(ELEMTYPE data)
	{
		if (vec.size() == 0)
			return NotFound;
		int i = 0;
		while (i < vec.size())
		{
			if (vec[i].data == data)
			{
				return vec[i];
			}
			else if (vec[i].data < data)
				i = vec[i].RChild;
			else
				i = vec[i].LChild;
		}
		return NotFound;
	}

	BSTNode FindMin(BSTNode StartNode)
	{
		if (StartNode.LChild == -1 && StartNode.RChild == -1)
			return StartNode;
		else
		{
			while (StartNode.LChild != -1)
				StartNode = vec[StartNode.LChild];
			return StartNode;
		}
	}

	void Insert(ELEMTYPE newdata)			///新建节点插入二叉排序树中。
	{
		if (vec.size() == 0)
			//cout << "No Nodes." << endl;
			NewNode(newdata);

		unsigned i = 0;
		while (i < vec.size())
		{
			if (newdata <= vec[i].data)		//新节点应在vec[i]的左子树上
			{
				if (vec[i].LChild == -1)		//若该节点无左子树，则新节点应该放在此处。
				{
					vec[i].LChild = vec.size();
					BSTNode N = { newdata, -1, -1 };
					vec.push_back(N);
					break;
				}
				else
					i = vec[i].LChild;		//当前节点变为左子树根节点，继续搜索位置。
			}
			else							//新节点应在当前节点右子树上，具体放置方法同上。
			{
				if (vec[i].RChild == -1)
				{
					vec[i].RChild = vec.size();
					BSTNode N = { newdata, -1, -1 };
					vec.push_back(N);
					break;
				}
				else
					i = vec[i].RChild;
			}
		}
	}
/*
	void Delete(ELEMTYPE data)
	{
		BSTNode tempNode;
		//int tempPosition;
		tempNode = Find(data);	//查找该节点
		if (tempNode.data = -1)
		{
			cout << "Not Found." << endl;
			return;
		}
		else
			if (tempNode.LChild != -1 && tempNode.RChild != -1)
			{
				BSTNode tempNode2 = FindMin(tempNode);
				Delete(tempNode2.data);

				tempNode.Copy(tempNode2);
			}
			else
			{
				
				if (tempNode.LChild == -1)
				{
					tempNode.Copy(vec[tempNode.RChild)
				}//让其子节点代替该节点现在的位置
				else if (tempNode.RChild == -1)
					T = T->LChild;
				free(tempNode);		//再将该节点删除。（如果没有子节点直接删除即可）
			}

	}
*/
	void InOrderTraverse(int i)				//中序遍历该二叉搜索树，并将结果打印出来。
	{
		if (vec[i].LChild != -1)
			InOrderTraverse(vec[i].LChild);
		cout << vec[i].data << ' ';
		if (vec[i].RChild != -1)
			InOrderTraverse(vec[i].RChild);
	}

	void PreOrderTraverse(int i)			//前序遍历。
	{
		cout << vec[i].data << ' ';
		if (vec[i].LChild != -1)
			InOrderTraverse(vec[i].LChild);
		if (vec[i].RChild != -1)
			InOrderTraverse(vec[i].RChild);
	}

	void PostOrderTraverse(int i)			//后序遍历。
	{
		if (vec[i].LChild != -1)
			InOrderTraverse(vec[i].LChild);
		if (vec[i].RChild != -1)
			InOrderTraverse(vec[i].RChild);
		cout << vec[i].data << ' ';
	}

	int Search(ELEMTYPE c)
	{
		int i = 0;
		int depth = 1;
		while (i != -1)
		{
			if (c == vec[i].data)
			{
				return depth;
			}
			else if (c > vec[i].data)
			{
				depth++;
				i = vec[i].RChild;
			}
			else
			{
				depth++;
				i = vec[i].LChild;
			}
		}
		return -1;
	}


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
		print(vec[i].LChild, str);
		cout << str << vec[i].data << endl;
		print(vec[i].RChild, str);
	}
};
