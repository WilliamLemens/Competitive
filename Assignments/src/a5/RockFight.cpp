#include <stdio.h>
#include <bits/stdc++.h>

int main() {
    int T, N;
    scanf("%d\n", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d\n", &N);
        int ru[N], bl[N];
        // Read in Ruth's stones
        for (int n = 0; n < N; n++)
            scanf("%d", &ru[n]);
        std::sort(ru, ru+N);
        // Read in Bleminda's stones
        for (int n = 0; n < N; n++)
            scanf("%d", &bl[n]);
        std::sort(bl, bl+N);
        // Find optimal moves
        bool v[N];
        int out = 0, bot = 0, top = N-1;
        for (int n = N-1; n >= 0; n--)
            if (bl[n] >= ru[top]) // No way to avoid getting captured
                out += ru[bot++];
            else // Ruth can avoid getting captured
                top--;
        printf("%d\n", out);
    }
}
