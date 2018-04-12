#include <bits/stdc++.h>
using namespace std;

const long MOD = 1000000007l;

int main() {
    unsigned int T;
    unsigned long long n, k, d, a;
    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        a=1;
        scanf("%llu %llu %llu", &n, &k, &d);
        // Calculate k^d using exponentiation by squaring
        while (d > 0) {
            if (d & 1) // odd exponent, so multiply answer by this value
                a = (a*k) % MOD;
            k = (k * k) % MOD; // even exponent, so square value
            d >>= 1; // divide exponent by 2
        }
        n = (n * a) % MOD; // multiply k^d by n to get final number
        printf("%llu\n", n);
    }
}
