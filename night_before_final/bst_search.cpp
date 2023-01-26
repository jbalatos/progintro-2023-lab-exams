#include <cstdio>
#include <iostream>

using namespace std;

struct node
{
	int value;
	node *left, *right;
};

int search_recursive (node *u, int x, int d)
{
	if (u == nullptr) return 0;
	if (u->value == x) return d;
	else if (u->value > x) return search_recursive(u->left, x, d+1);
	else return search_recursive(u->right, x, d+1);
}

int search (node *u, int x) // returns depth of value x OR 0
{
	int d = 1;
	while (u != nullptr && u->value != x) {
		if (u->value > x) u = u->left;
		else u = u->right;
		d++;
	}
	if (u == nullptr) return 0;
	else return d;
}

int main ()
{
	return 0;
}

