#include <bits/stdc++.h>
using namespace std;

struct Envelope { int w, h, n, max, prev; };

bool env_sort (Envelope const& a, Envelope const& b) { return a.w < b.w; }
bool fits_in (Envelope a, Envelope b) { return a.w < b.w && a.h < b.h; }

int main() {
// READ IN
    int N, W, H;
    scanf("%d %d %d", &N, &W, &H);
    Envelope envs[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &envs[i].w, &envs[i].h);
        envs[i].n = i+1;
        envs[i].max = envs[i].w > W && envs[i].h > H ? 1 : 0;
    }
// DO LOGIC
    sort(envs, envs+N, &env_sort);
    int maxIndx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (fits_in(envs[j], envs[i]) && envs[i].max <= envs[j].max && envs[j].max > 0) {
                envs[i].max = envs[j].max+1;
                envs[i].prev = j;
            }
        }
        if (envs[i].max > envs[maxIndx].max)
            maxIndx = i;
    }
    int maxVal = envs[maxIndx].max;
    printf("%d\n", maxVal);
    // get path
    if (maxVal > 0) {
        int current = maxIndx;
        int path[maxVal];
        for (int i = maxVal-1; i >= 0; i--) {
            path[i] = envs[current].n;
            current = envs[current].prev;
        }
        for (int i = 0; i < maxVal; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
}
