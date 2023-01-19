#include <cstdio>

using namespace std;

int main () {

	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		char c = getchar();
		if (c == ' ' || c == '\n')
			continue;

		if ('a' <= c && c <= 'z')
			c = c - 'a' + 'A';
		else if ('A' <= c && c <= 'Z')
			c = c - 'A' + 'a';
		putchar(c);
	}

	return 0;
}
