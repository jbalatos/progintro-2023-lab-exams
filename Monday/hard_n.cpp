#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

int main () {

	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	int l = 0, r = n-1, res = INT_MIN;
	while (l < r) {
		res = max(res, min(a[l], a[r]) * (r-l+1));
		if (a[l] < a[r])
			++l;
		else
			++r;
	}

	printf("%d\n", res);

	return 0;
}

