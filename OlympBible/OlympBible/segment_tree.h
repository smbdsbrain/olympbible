/*
Pavel
Segment tree with lazy propagation // Дерево отрезков с массовыми операцами
Set and min // Сумма и минимум
2015
*/

#pragma once
#include "cstdio"
#include "algorithm"
#include "cmath"
using namespace std;

struct seg_node
{
	seg_node *l, *r;
	int L, R;
	int val;
	
	int q;
	bool ch;
	seg_node()
	{
		l = r = NULL;
		q = val = R = L = 0;
		ch = false;
	}
};

seg_node* seg_build(int l, int r, int* m)
{
	seg_node* v = new seg_node();
	v->L = l;
	v->R = r;

	if (r - l > 1)
	{
		v->l = seg_build(l, (l + r) / 2, m);
		v->r = seg_build((l + r) / 2, r, m);
		v->val = min(v->l->val, v->r->val);
	}
	else
	{
		v->val = m[l];
	}

	return v;
}

void seg_push(seg_node *v)
{
	if (v->ch)
	{
		v->val = v->q;
		if (v->l != NULL)
		{
			v->l->q = v->l->q = v->q;
			v->l->ch = v->r->ch = true;
		}
		v->q = 0;
		v->ch = false;
	}
}

int seg_get(seg_node* v, int l, int r)
{
	seg_push(v);
	if (v == NULL || v->L >= r || v->R <= l)
	{
		return INT_MAX;
	}

	if (v->R >= l && v->R <= r)
	{
		return v->val;
	}

	return min(seg_get(v->l, l, r), seg_get(v->r, l, r));
}

void seg_set(seg_node* v, int l, int r, int x)
{
	seg_push(v);
	if (v == NULL || v->L >= r || v->R <= l)
	{
		return;
	}

	if (v->R >= l && v->R <= r)
	{
		v->q = x;
		v->ch = true;
		seg_push(v);
	}

	seg_set(v->l, l, r, x);
	seg_set(v->r, l, r, x);
}