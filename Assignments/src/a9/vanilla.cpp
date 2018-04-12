#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, x, y, j;
    int64_t area;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) { // each test
        scanf("%d", &n);
        std::vector<std::pair<int64_t, int64_t> > v(n);
        area = 0;
        for (int i = 0; i < n; i++) { // read in points for this test
            scanf("%d %d", &x, &y);
            v[i] = std::make_pair(x, y);
        }

        for (int i = 0; i < n; i++) { // find area
            j = (n+i-1)%n;
            area += (v[j].first+v[i].first) * (v[i].second-v[j].second);
        }
        printf("%ld\n", area);
    }
}
