#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int d, sumTime;
    scanf("%d%d", &d, &sumTime);
    int minTime[d], maxTime[d];
    for (int i = 0; i < d; ++i)
        scanf("%d%d", &minTime[i], &maxTime[i]);
    int minTimeSum = accumulate(minTime, minTime + d, 0);
    int maxTimeSum = accumulate(maxTime, maxTime + d, 0);

    if (minTimeSum <= sumTime && sumTime <= maxTimeSum) {
        printf("YES\n");
        for (int i = 0; i < d; ++i) {
            int t = min(minTime[i] + sumTime - minTimeSum, maxTime[i]);
            printf((i + 1 < d ? "%d " : "%d\n"), t);
            sumTime -= (t - minTime[i]);
        }
    }
    else printf("NO\n");
    return 0;
}
