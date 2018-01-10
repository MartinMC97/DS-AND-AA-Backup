#pragma once
#include <iostream>
#include <cstdlib>
#define ELEMTYPE char
using namespace std;

struct TreeNode
{
	ELEMTYPE data;
	TreeNode *LChild;
	TreeNode *RChild;

	TreeNode(ELEMTYPE newdata)
	{
		this->data = newdata;
		LChild = nullptr;
		RChild = nullptr;
	}
};

typedef TreeNode* ptrBSTree;

ptrBSTree MakeEmpty(ptrBSTree T)
{
	if (T != nullptr)
	{
		MakeEmpty(T->LChild);
		MakeEmpty(T->RChild);
		free(T);
	}
	return NULL;
}

TreeNode* Find(ptrBSTree T, ELEMTYPE data)
{
	if (T == NULL)
		return nullptr;
	if (T->data < data)
		return Find(T->RChild, data);
	else if (T->data > data)
		return Find(T->LChild, data);
	else
		return T;
}

TreeNode* FindMin(ptrBSTree T)
{
	if (T == nullptr)
		return nullptr;
	if (T->LChild == nullptr)
		return T;
	else
		return FindMin(T->LChild);
}

TreeNode* FindMax(ptrBSTree T)
{
	if (T == nullptr)
		return T;
	else
	{
		while (T->RChild != nullptr)
			T = T->RChild;
		return T;
	}
}

ptrBSTree Insert(ptrBSTree T, ELEMTYPE newdata)
{
	if (T == nullptr)
		T = new TreeNode(newdata);
	else if (T->data > newdata)
		T->LChild = Insert(T->LChild, newdata);
	else if (T->data < newdata)
		T->RChild = Insert(T->RChild, newdata);
	//相等时代表该数据已经在树中，无需再插入。
	return T;
}

ptrBSTree Delete(ptrBSTree T, ELEMTYPE data)	///返回删除data节点后的新二叉搜索树。
{
	TreeNode *tempNode;
	if (T == nullptr)
	{
		cerr << "ELEMENT NOT FOUND" << endl;
		return NULL;
	}
	else if (T->data > data)
		T->LChild = Delete(T->LChild, data);	//该节点在左子树上，返回删除之后的二叉搜索树作为新的左子树。
	else if (T->data < data)
		T->RChild = Delete(T->RChild, data);	//同上。
	else 
		if (T->LChild && T->RChild)		//该节点有两个子节点。
		{
			tempNode = FindMin(T->RChild);		//找到右子树上的最小节点代替该节点。
			T->data = tempNode->data;
			T->RChild = Delete(T->RChild, tempNode->data);	//在右子树中删去data节点。
		}
		else		//该节点拥有至多一个子节点。
		{
			tempNode = T;	
			if (T->LChild == nullptr)
				T = T->RChild;		//让其子节点代替该节点现在的位置
			else if (T->RChild == nullptr)
				T = T->LChild;		
			free(tempNode);		//再将该节点删除。（如果没有子节点直接删除即可）
		}
	return T;
}

