#include <cstdio>

using namespace std;

int main () {

	int n, k;
	scanf("%d%d", &n, &k);
	int a[n];
	for (int i=0; i<n; ++i)
		scanf("%d", &a[i]);

	int count = 0;
	for (int i=0; i<n; ++i)
		if (a[i] == k)
			count++;

	printf("%d\n", count);

	return 0;
}
