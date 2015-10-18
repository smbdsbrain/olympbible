#pragma once
#include<cstdio>
#include<algorithm>
#include<cmath>
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

int seg_get(seg_node* v, int l, int r)
{
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

void seg_set(seg_node* v, int l, int r)
{

}

void seg_inc(seg_node*, int l, int r)
{

}