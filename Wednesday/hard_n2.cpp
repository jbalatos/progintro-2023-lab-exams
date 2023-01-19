#include <algorithm>
#include <cstdio>

using namespace std;

int main () {

	int n, k;
	scanf("%d%d", &n, &k);
	int a[n];
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	int res = n+1; // or INT_MAX
	for (int i=0; i<n; ++i) {
		int s = 0;
		for (int j=i; j<n; ++j) {
			s += a[j];
			if (s >= k) {
				res = min(res, j-i+1);
				break; // not necessary
			}
		}
	}

	if (res == n+1) // or (res == INT_MAX)
		printf("0\n");
	else
		printf("%d\n", res);

	return 0;
}
