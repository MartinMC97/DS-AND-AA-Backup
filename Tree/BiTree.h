/*二叉树相关。
大部分都用的递归的方法，写起来比较容易。
非递归遍历方法之后可能会补上吧。*/
#pragma once
#include <stdlib.h>
#include <iostream>
#include "LinkStack.h"
#define ElemType char
using namespace std;

struct TreeNode{
	ElemType data;
	TreeNode *lchild, *rchild;
};

typedef TreeNode* BiTree;

int BiTreeInit(BiTree &T)
{
	/*
	按照前序遍历的顺序输入数据来建立一个二叉树。
	每个含有数据的节点都要输入有关子节点的信息。
	不存在的子节点用'#'表示，自动将其子节点指针设置为NULL。
	*/
	ElemType c;
	cin >> c;
	
	if (c == '#')
	{
		T = NULL;
		return 0;
	}
	else
	{
		T = (TreeNode*)malloc(sizeof(TreeNode));
		T->data = c;
		BiTreeInit(T->lchild);
		BiTreeInit(T->rchild);
	}
}

/*楼下几个方法都用了递归。*/

void PreOrderTraverse(BiTree T)			//前序遍历。
{
	if (T)
	{
		cout << T->data << ' ';
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)			//中序遍历。
{
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data << ' ';
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T)		//后序遍历。
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data << ' ';
	}
}

int getDepth(BiTree T)				//获得该二叉树的深度。
{
	int depth;
	int ldepth = 1, rdepth = 1;
	if (T)
	{
		ldepth += getDepth(T->lchild);
		rdepth += getDepth(T->rchild);
	}
	else return 0;
	depth = (ldepth > rdepth) ? ldepth : rdepth;
	return depth;
}

int i;
int getLeaves(BiTree T)				//获得该二叉树叶节点（无左右子节点）的数目。
{
	if (T->lchild == NULL&&T->rchild == NULL)
		i++;
	else
	{
		getLeaves(T->lchild);
		getLeaves(T->rchild);
	}
	return i;
}

