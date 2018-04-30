#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 101;

bool BFS(int graph[MAX_N][MAX_N], int N, int s, int t, int parent[]) {
    bool visited[N];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < N; v++)
            if (!visited[v] && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
    }

    return visited[t];
}

// Returns the maximum flow from s to t in the given graph
int ford_fulkerson(int G[MAX_N][MAX_N], int N, int s, int t) {
    int u, v;

    int R[MAX_N][MAX_N]; // Set up residual graph
    for (u = 0; u < N; u++)
        for (v = 0; v < N; v++)
             R[u][v] = G[u][v];

    int parent[N];
    int max_flow = 0;

    while (BFS(R, N, s, t, parent)) {
        int path_flow = INT_MAX;

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, R[u][v]);
        }

        // update residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            R[u][v] -= path_flow;
            R[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int T, N, M, S, P, H, u, v, c;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        // READ IN
        scanf("%d %d %d %d", &N, &M, &S, &P);
        int G[MAX_N][MAX_N];
        for (int m = 0; m < M; m++) {
            scanf("%d %d %d", &u, &v, &c);
            G[u][v] = c;
        }
        for (int j = 0; j < S; j++) {
            scanf("%d", &H);
            G[H][0] = INT_MAX;
        }
        // FEED TO FORD-FULKERSON'S
        int maxSaved = ford_fulkerson(G, N+1, S, 0);
        // OUTPUT
        if (maxSaved >= P)
            printf("YES\n");
        else
            printf("NO %d\n", P-maxSaved);
    }

    return 0;
}
