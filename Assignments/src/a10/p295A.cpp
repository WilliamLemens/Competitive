#include <cstdio>

constexpr int MAX_N = 100001;

using namespace std;
using ull = unsigned long long int;

int main() {
    // Read in array
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    int arr[n], que[m][3];
    for (int i = 1; i <= n; ++i) // read in array
        scanf(" %d", &arr[i]);
    for (int i = 0; i < m; ++i) // read in queries
        scanf(" %d %d %d", &que[i][0], &que[i][1], &que[i][2]);
    for (int i = 0; i < k; ++i) { // execute queries
        int x, y;
        scanf(" %d %d", &x, &y);
        for (int j = x; j < y; j++) {
            
        }
    }

    return 0;
}
