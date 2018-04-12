#include <bits/stdc++.h>

using namespace std;

int main() {
// Read in values
    int n;
    int64_t a, b;
    scanf("%d", &n);
    std::vector<std::pair <std::pair<int64_t, int64_t>, int> > v(n);

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        v[i] = std::make_pair(std::make_pair(a, b), i+1);
    }
// Logic
    sort(v.begin(), v.end());
    printf("%d %d ", v[0].second, v[1].second); // first two values
    // slope equal if y2(x1-x0)+x2(y0-y1)=y0x1-y1x0
    int64_t rhs = v[0].first.second*v[1].first.first-v[1].first.second*v[0].first.first;
    a = v[1].first.first-v[0].first.first, // x1-x0
        b = v[0].first.second-v[1].first.second; // y0-y1

    int i = 1;
    while (v[++i].first.second*a+v[i].first.first*b == rhs) {} // skip degenerate triangles
    printf("%d\n", v[i].second);
}
