#include <bits/stdc++.h>
using namespace std;

bool isNotPrime(int x) {
    if (x % 2 == 0)
        return true;
    else
        for (int i = 2; i <= sqrt(x); i++)
            if (x == i * (int)(x / i))
                return true;
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int a = n/2, b = n-n/2;
    while (!isNotPrime(a) || !isNotPrime(b)) {
        a--;
        b++;
    }
    printf("%d %d\n", a, b);
}
