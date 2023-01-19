#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

/* REQUIRED : arr is sorted in ascending order
 * REQUIRED : a[r] >= x (answer exists)
 * RETURNS  : min{ l <= i <= r : a[i] >= x}
 * */
int my_lower_bound (int arr[], int l, int r, int x)
{
	for (int jmp=(r-l+1)/2; jmp>=1; jmp/=2)
		while (l+jmp <= r && arr[l+jmp] < x)
			l += jmp;
	return l+1;
}

/* REQUIRED : arr is sorted in descending order
 * REQUIRED : a[r] < x (answer exists)
 * RETURNS  : min{ l <= i <= r : a[i] < x }
 * */
int my_upper_bound (int arr[], int l, int r, int x)
{
	for (int jmp=(r-l+1)/2; jmp>=1; jmp/=2)
		while (l+jmp <= r && arr[l+jmp] >= x)
			l += jmp;
	return l+1;
}

int main () {

	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	/* PREFIX - SUFFIX MAX ARRAYS */
	int pref[n], suf[n];
	pref[0] = a[0], suf[n-1] = a[n-1];
	for (int i=1; i<n; ++i)
		pref[i] = max(pref[i-1], a[i]);
	for (int i=n-2; i>=0; --i)
		suf[i] = max(suf[i+1], a[i]);

	int res = min(a[0], a[n-1]) * n;
	for (int r=1; r<n; ++r) {
		int l = my_lower_bound(pref, 0, r, a[r]);
		if (l < r)
			res = max(res, a[r] * (r - l + 1));
	}
	for (int l=n-2; l>=0; --l) {
		int r = my_upper_bound(suf, l, n-1, a[l]);
		if (l < r)
			res = max(res, a[l] * (r - l + 1));
	}

	printf("%d\n", res);

	return 0;
}
