#include <bits/stdc++.h>
using namespace std;

int recurse(int x) {
	if (x == 0)
		return 1;
	else if (x < 0)
		return 0;
	else
		return recurse(x-1) + recurse(x-5) + recurse(x-10) + recurse(x-25);
}

int get(int f[], int x) { return x < 0 ? 0 : f[x]; }

int main() {
	int T, X;
	scanf("%d",&T);
	for (int t = 0; t < T; t++) { // each test
		scanf("%d",&X);
		int f[X+1];
		f[0] = 1;
		for (int x = 1; x <= X; x++)
			f[x] = ((get(f,x-1) + get(f, x-5)) % 1000000007
					+ (get(f, x-10) + get(f, x-25)) %1000000007)
					% 1000000007;
		printf("%d\n",f[X]);
	}
}
