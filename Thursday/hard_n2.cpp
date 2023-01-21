#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

int main ()
{

	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	int res = INT_MAX;
	for (int i=1; i<n-1; ++i)
		for (int j=i+1; j<n; ++j)
			res = min( res, max(a[i] - a[0],
			                max(a[j] - a[i], a[n-1] - a[j]))
			         );

	printf("%d\n", res);

	return 0;
}
