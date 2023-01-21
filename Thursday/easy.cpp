#include <cstdio>

using namespace std;

int main ()
{

	int n, b;
	scanf("%d%d", &n, &b);

	int res = n % b; // lsb
	while ((n/b) != 0) n /= b;
	res += n; // msb
	printf("%d\n", res);

	return 0;
}
