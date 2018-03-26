#include <bits/stdc++.h>
using namespace std;

const long MOD = 1000000007l;

int main() {
    unsigned int T;
    unsigned long n, k, d;
    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        scanf("%ld %ld %ld", &n, &k, &d);
        for (int i = 0; i < d; i++)
            n = ((n % MOD) * (k % MOD)) % MOD;
        printf("%ld\n", n);
    }
}
