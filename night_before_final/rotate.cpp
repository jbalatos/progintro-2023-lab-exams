#include <cstdio>
#include <iostream>

using namespace std;

/* rotate array a k times left */
void rotate (int a[], int n, int k)
{
	int b[n];
	for (int i=0; i<n; ++i) // for every a[i] OR for every b[i]
		b[ (i-k+n) % n ] = a[i];
		// b[i] = a[ (i+k) % n ];
	for (int i=0; i<n; ++i)
		a[i] = b[i];
}

void rotate_one (int a[], int n, int k)
{
	int tmp = a[0];
	for (int i=n-2; i>=0; --i)
		a[i] = a[i+1];
	a[n-1] = tmp;
}

int main ()
{

	return 0;
}

