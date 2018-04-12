#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct jewel { int v, w; };

bool jewel_sort(jewel const& a, jewel const& b) { return a.w < b.w; }

int main() {
// READ IN
    int T, N, C;
    scanf("%d",&T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &N, &C);
        jewel j[N];
        int opt[N+1][C+1];
        for (int n = 0; n < N; n++)
            scanf("%d %d", &j[n].v, &j[n].w);
// SOLVE
        sort(j, j+N, &jewel_sort);
        for (int i = 0; i <= N; i++) {
            for (int c = 0; c <= C; c++) {
                if (i==0||c==0)
                    opt[i][c] = 0;
                else if (j[i-1].w <= c)
                    opt[i][c] = max(opt[i-1][c], opt[i-1][c-j[i-1].w]+j[i-1].v);
                else
                    opt[i][c] = opt[i-1][c];
            }
        }
        printf("%d\n", opt[N][C]);
    }
}
