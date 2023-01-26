#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	//INPUT("file.txt");
	freopen("odd_numbers.in", "r", stdin);
	freopen("odd_numbers.out", "w", stdout);
	
	int n, k; scanf("%d%d", &n, &k);
	int a[n];
	for (int i=0; i<n; ++i) scanf("%d", &a[i]);

	const int MAXN = 1000010;
	int res = MAXN;

	/* O(n^3) */
	/* for every sub-array,  check */
	// for (int i=0; i<n; ++i)
		// for (int j=i; j<n; ++j) {
			// int count_odd = 0;
			// for (int k=i; k<=j; ++k)
				// if (a[k] % 2 == 1) count_odd++;
			// if (count_odd >= k)
				// res = min(res, j-i+1);
		// }

	/* O(n^2) */
	// for (int i=0; i<n; ++i) {
		// int count_odd = 0;
		// for (int j=i; j<n; ++j) {
			// if (a[j] % 2 == 1) count_odd++;
			// if (count_odd >= k)
				// res = min(res, j-i+1);
		// }
	// }

	/* O(n) */
	/* for best answer, a[l] and a[r] odd */
	int l = 0, r = 0, count = 0;
	// find first odd
	for (int i=0; i<n; ++i) if (a[i]%2 == 1) {
		l = r = i;
		count = 1;
		break;
	}
	while (l <= r && r < n) {
		while (r+1 < n && count < k)
			count += (a[++r]%2 == 1);
		if (count < k) // reached end of array
			break; // or return res;
		res = min(res, r - l + 1);
		count--;
		// previous subarray
		do
			l++;
		while (l <= r && a[l]%2 == 0);
		// next subarray
	}


	if (res == MAXN) printf("0\n");
	else printf("%d\n", res);

	return 0;
}

