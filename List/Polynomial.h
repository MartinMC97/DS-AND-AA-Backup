/*������ʵ�ֵĶ���ʽ�ṹ�������Ӻͳ���������*/
#pragma once
#include <stdlib.h>

typedef struct Term{
	double coef;
	int exp;
	Term *Next;
}*Poly;

void PolyAppend(Poly &pa, double coef, int exp)		//�����ʽ�ṹ�����һ�
{
	Term *s = new Term,*p = pa;
	s->coef = coef; s->exp = exp; s->Next = NULL;
	for (; p->Next != (Term*)0xcdcdcdcd && p->Next != NULL; p = p->Next);
	p->Next = s;
}

Poly PolyMultiply(Poly pa, Poly pb)			//������ʽ��ˣ����س˻���
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
			while (p->Next != (Term*)0xcdcdcdcd && p->Next!=NULL&&p->Next->exp != exp)      p = p->Next; //��� pc ���Ƿ���ָ��Ϊ exp ����
			if (p->Next == NULL || p->Next == (Term*)0xcdcdcdcd)      //���һֱ�� pc ĩβ��û��ָ��Ϊ exp ������½�һ��ӵ� pc ĩβ
			{
				Term *newterm = new Term;
				newterm->coef = coef;
				newterm->exp = exp;
				newterm->Next = NULL;
				p->Next = newterm;
			}
			else if (p->Next->exp == exp) //��� pc ����ָ��Ϊexp����ͽ���һ����˻��ϲ�
			{
				p->Next->coef += coef;
			}
			ppb = ppb->Next;
		}
		ppa = ppa->Next;
	}
	return pc;
}

void PolyAdd(Poly &pa, Poly pb)				//������ʽ��ӣ����������pa�С�
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

void PolyMinus(Poly &pa, Poly pb)			//����ʽ��������ǰ�+������-������û�䣬���ÿ��ˡ�
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