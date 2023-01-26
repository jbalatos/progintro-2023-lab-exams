#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i=a; i<n; ++i)/*{{{*/
#define per(i, a, n) for (int i=n-1; i>=a; --i)
#define pb push_back
#define sz size()
#define x first
#define y second
#define ITER(a) (a).begin(), (a).end()
#define REV(a) (a).rbegin(), (a).rend()
#define gcd(a, b) __gcd(abs(a), abs(b))

typedef long long ll;
typedef vector<int> ivec;
typedef pair<int, int> iipair;
typedef vector<vector<int>> adjlist;/*}}}*/

int main ()
{
	/*
	 * TOTAL LOOPS = (n * (n+1)) / 2
	 *             = 1/2 * (n^2 + n) -> n^2 + n -> n^2
	 */

	/* j - i + 1 === size of a[i..j] */

	int n;
	for (int i=0; i<n; ++i) { // runs n times
		for (int j=i; j<n; ++j) // runs n-i times == O(n)
			for (int k=j; k>0; k/=2) // runs O(logj) == O(logn)
				foo();
	}
	// total  : O(n^2 logn)

	return 0;
}

