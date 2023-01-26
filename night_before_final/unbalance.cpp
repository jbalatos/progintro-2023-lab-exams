#include <cstdio>
using namespace std;

//   Oriste typo dentrou
struct node {
	int value;
	node *left, *right;
};

typedef node* tree;

// Plithos komvwn me iso ipsos, vathos
// O(n^2)

int max (int a, int b)
{
	if (a > b) return a;
	else return b;
}

int abs (int x)
{
	if (x > 0) return x;
	else return -x;
}

int height (tree t)
{
	if (t == nullptr) return 0;
	return 1 + max(height(t->left), height(t->right));
}

int unbalance (tree t)
{
	if (t == nullptr) return 0;
	int res = max(unbalance(t->left), unbalance(t->right));
	res = max(res, abs(height(t->left) - height(t->right)));
	return res;
}

/* O(n) solution */

struct tmp
{
	int res, h;
};

tmp unbalance_aux (tree t)
{
	if (t == nullptr) {
		tmp res;
		res.res = 0, res.h= 0;
		return res;
	}
	tmp left = unbalance_aux(t->left),
	    right = unbalance_aux(t->right),
	    res;
	res.h = 1 + max(left.h, right.h);
	res.res = max( max(left.res, right.res), abs(left.h - right.h) );
	return res;
}

int unbalance_n (tree t) { return unbalance_aux(t).res; }

int main ()
{
	return 0;
}

