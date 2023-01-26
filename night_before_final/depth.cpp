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
	return b;
}

int get_height (tree t)
{
	if (t == nullptr)
		return 0;
	return 1 + max(get_height(t->left), get_height(t->right));
}

int count_aux (tree t, int depth)
{
	if (t == nullptr)
		return 0;
	int res = (depth == get_height(t));
	// int res = 0;
	// if (depth == get_height(t))
		// res++;
	return res + count_aux(t->left, depth+1) + count_aux(t->right, depth+1);
}

int count_n2 (tree t) { return count_aux(t, 1); }

/* O(n) */

struct ret_type {
	int count, height;
};

/* a->x === (*a).x */

ret_type count_n_aux (tree t, int depth)
{
	if (t == nullptr) {
		ret_type res;
		res.count = 0, res.height = 0;
		return res;
	}
	ret_type left = count_n_aux(t->left, depth+1),
		 right = count_n_aux(t->right, depth+1);
	int cur_height = max(left.height, right.height);
	ret_type res;
	res.count = left.count + right.count + (cur_height == depth);
	res.height = cur_height;
	return res;
}

int count_n (tree t) { return count_n_aux(t, 1).count; }


int main ()
{
	return 0;
}
