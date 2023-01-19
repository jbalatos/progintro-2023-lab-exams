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

	int res = INT_MIN;
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			res = min( res, max(a[i], a[j]) * (j - i + 1) );

	printf("%d\n", res);

	return 0;
}
