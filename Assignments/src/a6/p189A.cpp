#include <bits/stdc++.h>

using namespace std;

int get(int f[], int i) { return i < 0 ? -1 : f[i]; }

int main() {
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    int f[n];
    f[0] = 0;
	for (int i = 1; i <= n; ++i) {
        int tmp = max( get(f, i-a), max( get(f, i-b), get(f, i-c)));
		f[i] = tmp == -1 ? tmp : tmp + 1;
    }
	cout << f[n] << "\n";
    return 0;
}
