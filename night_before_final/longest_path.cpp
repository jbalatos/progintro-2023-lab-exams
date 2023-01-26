#include <cstdio>
using namespace std;

//   Oriste typo dentrou
struct node {
	int value;
	node *left, *right;
};

typedef node* tree;

int max (int a, int b)
{
	if (a > b) return a;
	return b;
}

/* LONGEST PATH */

int longestPath (tree t)
{
	if (t == nullptr) return 0;
	int res = 0;
	// if ((t->left == nullptr || t->left->value == t->value) &&
	    // (t->right == nullptr || t->right->value == t->value))
		// return 0;
	if (t->left != nullptr && t->left->value != t->value)
		res = max(res, longestPath(t->left));
	if (t->right != nullptr && t->right->value != t->value)
		res = max(res, longestPath(t->right));
	if (res == 0) return 0; // this or 'if' 
	else return res + 1;
}


int main () { return 0; }
