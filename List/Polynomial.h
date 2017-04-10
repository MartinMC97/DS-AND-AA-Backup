/*用链表实现的多项式结构，包括加和乘两种运算*/
#pragma once
#include <stdlib.h>

typedef struct Term{
	double coef;
	int exp;
	Term *Next;
}*Poly;

void PolyAppend(Poly &pa, double coef, int exp)		//向多项式结构中添加一项。
{
	Term *s = new Term,*p = pa;
	s->coef = coef; s->exp = exp; s->Next = NULL;
	for (; p->Next != (Term*)0xcdcdcdcd && p->Next != NULL; p = p->Next);
	p->Next = s;
}

Poly PolyMultiply(Poly pa, Poly pb)			//两多项式相乘，返回乘积。
{
	Poly ppa = pa->Next, ppb = pb->Next;
	Poly pc = new Term, p = pc;
	
	while (ppa)
	{
		ppb = pb->Next;
		while (ppb)
		{
			p = pc;
			double coef = ppa->coef * ppb->coef;
			int exp = ppa->exp + ppb->exp;
			while (p->Next != (Term*)0xcdcdcdcd && p->Next!=NULL&&p->Next->exp != exp)      p = p->Next; //检查 pc 里是否有指数为 exp 的项
			if (p->Next == NULL || p->Next == (Term*)0xcdcdcdcd)      //如果一直到 pc 末尾都没有指数为 exp 的项，就新建一项加到 pc 末尾
			{
				Term *newterm = new Term;
				newterm->coef = coef;
				newterm->exp = exp;
				newterm->Next = NULL;
				p->Next = newterm;
			}
			else if (p->Next->exp == exp) //如果 pc 中有指数为exp的项就将这一项与乘积合并
			{
				p->Next->coef += coef;
			}
			ppb = ppb->Next;
		}
		ppa = ppa->Next;
	}
	return pc;
}

void PolyAdd(Poly &pa, Poly pb)				//两多项式相加，结果保存在pa中。
{
	Term *p1 = pa->Next, *p2 = pb->Next;
	while (p1->Next&&p2->Next)
	{
		if (p1->exp == p2->exp)
		{
			p1->coef += p2->coef;
			p1 = p1->Next; p2 = p2->Next;
		}
		else if (p1->exp > p2->exp) p2 = p2->Next;
		else p1 = p1->Next;
	}
	if (NULL == p1->Next) p1->Next = p2;
}

void PolyMinus(Poly &pa, Poly pb)			//多项式相减，就是把+换成了-，其余没变，不用看了。
{
	Term *p1 = pa->Next, *p2 = pb->Next;
	while (p1->Next&&p2->Next)
	{
		if (p1->exp == p2->exp)
		{
			p1->coef -= p2->coef;
			p1 = p1->Next; p2 = p2->Next;
		}
		else if (p1->exp > p2->exp) p2 = p2->Next;
		else p1 = p1->Next;
	}
	if (NULL == p1->Next) p1->Next = p2;
}