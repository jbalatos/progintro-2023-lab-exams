#include <algorithm>
#include <cstdio>

using namespace std;

int main () {

	int n, k;
	scanf("%d%d", &n, &k);
	int a[n];
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	/* FIND FIRST PAIR (l = 0, r) */
	int l = 0, r = 0, s = a[0];
	while (r+1 < n && s < k) {
		r++;
		s += a[r];
	}

	if (r == n-1 && s < k) { // s is max_sum < k --> no answer exists
		printf("0\n");
		return 0;
	}

	int res = r - l + 1;
	while (l < n-1) {
		s -= a[++l]; // or l++; s -= a[l];
		while (r+1 < n && s < k)
			s += a[++r]; // or r++; s += a[r];
		if (s < k) break;
		res = min(res, r - l + 1);
	}

	printf("%d\n", res);


	return 0;
}

