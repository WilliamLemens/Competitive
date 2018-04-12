#include <cstdio>

constexpr int MAX_N = 100001;

using namespace std;

int n, m;
int arr[MAX_N];

int tree[4 * MAX_N];

// 0 = root
// children of i = 2 * i + 1, 2 * i + 2

// Finds GCD of two numbers
int gcd(int a, int b) {
    if (a < b) gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

// Recursive function for building the tree
int build(int i, int l, int r) {
    if (l == r) // base case
        tree[i] = arr[l];
    else
        tree[i] = gcd(build(2 * i + 1, l, (l + r) / 2),
                      build(2 * i + 2, (l + r) / 2 + 1, r));

    return tree[i];
}

// Caller function for building the tree
void build() { build(0, 1, n); }

// Recursive function for querying the tree
int query(int i, int l, int r, int a, int b) {
    if (l >= a && r <= b) return tree[i];
    if (r < a || b < l) return 0;
    return gcd(query(2 * i + 1, l, (l + r) / 2, a, b),
               query(2 * i + 2, (l + r) / 2 + 1, r, a, b));
}

// Caller function for querying the tree
int query(int a, int b) { return query(0, 1, n, a, b); }

// Recursive function for updating the seg tree
int update(int i, int l, int r, int j, int v) {
    if (j < l || j > r) return tree[i];
    if (l == r)
        tree[i] = v;
    else
        tree[i] = gcd(update(2 * i + 1, l, (l + r) / 2, j, v),
                      update(2 * i + 2, (l + r) / 2 + 1, r, j, v));

    return tree[i];
}

// Initial caller for updating the seg tree
void update(int j, int v) { update(0, 1, n, j, v); }

int main() {
    int T;
    scanf(" %d", &T);
    for (int t = 0; t < T; t++) {
        int a, b;
        // Setup test case
        scanf(" %d %d", &n, &m); // read in n and m
        for (int i = 1; i <= n; ++i) // read in array
            scanf(" %d", &arr[i]);
        build();
        // Execute test case
        for (int i = 0; i < m; ++i) {
            int typ;
            scanf(" %d", &typ);
            if (typ == 1) { // type 1, "1 i x" change a[i] to x
                int i, x;
                scanf(" %d %d", &i, &x);
                update(i, x);
            } else { // type 2, "2 l r" get gcd of range l to r
                int l, r;
                scanf(" %d %d", &l, &r);
                printf("%d ", query(l, r));
            }
        }
    }
    printf("\n");
    return 0;
}
