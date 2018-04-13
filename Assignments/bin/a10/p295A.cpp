#include <cstdio>

constexpr int MAX_N = 100001;

using namespace std;
using ll = long long int;

int main() {
    // Read in array
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    ll arr[n], que[m][3], q[m+1], add[n+1];

    for(int i = 0; i <= m; i++)
        q[i] = 0;
    for(int i = 0; i <= n; i++)
        add[i] = 0;

    // Read in array
    for (int i = 0; i < n; i++) scanf(" %lld", &arr[i]);

    for (int i = 0; i < m; i++) // Read in queries "l r d"
        scanf(" %lld %lld %lld", &que[i][0], &que[i][1], &que[i][2]);

    for (int i = 0; i < k; i++) { // magic?
        int x, y;
        scanf(" %d %d", &x, &y);
        ++q[x-1];
        --q[y];
    }

    ll sum = 0;
    for (int i = 0; i < m; i++) {
        sum += q[i];
        add[que[i][0] - 1] += sum * que[i][2];
        add[que[i][1]]     -= sum * que[i][2];
    }

    ll totalAdd = 0;
    for (int i = 0; i < n; i++) {
        totalAdd += add[i];
        printf("%lld ", totalAdd+arr[i]);
    }
    printf("\n");
    return 0;
}
