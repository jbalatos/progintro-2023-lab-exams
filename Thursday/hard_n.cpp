#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

#define MAXN 1000010
int n, a[MAXN];

int cost (int l, int r)
{
	return max( a[l] - a[0], max(a[r] - a[l], a[n-1] - a[r]) );
}

int main ()
{

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	int left = INT_MAX, middle = INT_MAX, right = INT_MAX;
	int l, r;

	/* LEFT */
	l = n-3, r = n-2, left = a[l] - a[0];
	for (l=n-4; l>=1; --l) {
		while (a[r] - a[l] > a[l] - a[0])
			--r;
		if (a[n-1] - a[r] > a[l] - a[0])
			break;
		left = a[l] - a[0];
	}

	/* RIGHT */
	l = 1, r = 2, right = a[n-1] - a[r];
	for (r = 3; r<n-1; ++r) {
		while (a[r] - a[l] > a[n-1] - a[r])
			++l;
		if (a[l] - a[0] > a[n-1] - a[r])
			break;
		right = a[n-1] - a[r];
	}

	/* MIDDLE */
	l = 1, r = 2;
	while (l < n-1) {
		while (r < n-1 && a[r] - a[l] != cost(l, r))
			++r;
		if (r == n-1)
			break;
		while (l+1 < r && a[r] - a[l+1] == cost(l+1, r))
			++l;
		middle = min(middle, cost(l, r));
		l++;
	}

	printf("%d\n", min(left, min(middle, right)));

	return 0;
}

